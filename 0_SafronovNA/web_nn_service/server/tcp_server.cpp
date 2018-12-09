//
// Created by safic on 20.09.18.
//

#include <ctime>
#include <string>
#include <iostream>

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/format.hpp>
#include <boost/smart_ptr.hpp>

#include "../utils/config.h"
#include "../tf_model/engine.h"

using boost::asio::ip::tcp;
using namespace std;

Engine engine;

class client_session
{
public:
    typedef boost::shared_ptr<client_session> pointer;

    static pointer create(boost::asio::io_service &io) {
        return pointer(new client_session(io));
    }

    ~client_session() {
        log("Connection closed");
    }

    tcp::socket &socket() { return socket_; }

    void start() {
        log("Connection established");

        int image_shape[2]; //shape is (width, height)
        boost::system::error_code error;
        socket_.read_some(boost::asio::buffer(image_shape, 2* sizeof(int)), error);

        long array_size = image_shape[0] * image_shape[1] * 3;
        uint8_t *array = new uint8_t[array_size];

        //boost::this_thread::sleep(boost::posix_time::milliseconds(1000));

        uint8_t *data_start = array;
        long already_read = 0;
        long total_to_read = array_size;
        long left_to_read = total_to_read;
        long len = 0;
        while(already_read < total_to_read){
            len = socket_.read_some(boost::asio::buffer(data_start, left_to_read), error);
            //cout << "read " << len << " bytes" << endl;
            already_read += len;
            left_to_read -= len;
            data_start += len;
        }
        //cout << endl;

        fprintf(stdout, "Read bytes: %ld of %ld", array_size, already_read);

        if (image_shape[0] != 416 || image_shape[1] != 416){
            int recog[] = {0};
            boost::asio::write(socket_, boost::asio::buffer(recog));
            delete[] array;
            return;
        }

        Prediction * preds = nullptr;
        int preds_len = 0;

        float * array_float = new float[array_size];
        for (int i = 0; i < array_size; i++){
            array_float[i] = array[i] / 255.0;
        }

        engine.predict_416_x_416(array_float, &preds, &preds_len);

        fprintf(stdout, "Prediction results: preds_len = %d\n", preds_len);
        /*
        for (size_t i = 0; i < preds_len; i++){
            fprintf(stdout, "[\n");
            for (size_t j = 0; j < sizeof(Prediction); j++){
                char *this_char = (char*)(preds + i*sizeof(Prediction) + j);
                fprintf(stdout, "%c, ",*this_char);
            }
            fprintf(stdout, "]\n");
        }
        */

        boost::asio::write(socket_, boost::asio::buffer({0}, sizeof(char)));
        boost::asio::write(socket_, boost::asio::buffer(preds, preds_len*sizeof(Prediction)));

        delete[] array;
        //no need to "delete[] array_float", because it will be freed inside tensorflow session
    }

protected:
    client_session(boost::asio::io_service &io)
            : socket_(io) {
    }

    void log(std::string const &message) {
        std::clog << boost::format("%|-25| [client address: %|15|]\n")
                     % message % socket_.remote_endpoint().address().to_string();
    }

private:
    tcp::socket socket_;
};

int main()
{
    engine = Engine();
    engine.init();

    boost::asio::io_service io;

    tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), DEFAULT_TCP_SERVER_PORT));
    for (;;) {
        client_session::pointer new_client = client_session::create(io);
        acceptor.accept(new_client->socket());
        boost::thread(boost::bind(&client_session::start, new_client)).detach();
    }
}

