//
// Created by safic on 21.09.18.
//

#include <iostream>
#include <fstream>
#include <cstring> //atoi

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/array.hpp>

#include <boost/gil.hpp>
#include <boost/gil/io/io.hpp>
#include <boost/gil/extension/io/jpeg.hpp>
#include <boost/gil/extension/numeric/sampler.hpp> //gil::bilinear_sampler()
#include <boost/gil/extension/numeric/resample.hpp>  //gil::resize_view()

#include "../utils/structures.h"
#include "../utils/config.h"

using namespace boost::asio;
using namespace boost::system;
namespace gil = boost::gil;
using namespace std;

std::string class_idx_to_name(int class_idx){
    if (class_idx == 0)
        return std::string("person");
    if (class_idx == 2)
        return std::string("car");
    if (class_idx == 3)
        return std::string("motorbike");
    if (class_idx == 63)
        return std::string("laptop");

    return std::string("object");
}

bool image_to_array(gil::rgb8_image_t::const_view_t img, uint8_t **array, int *height, int *width){

    uint32_t width_tmp = img.width();
    uint32_t height_tmp = img.height();
    uint8_t *array_tmp = new uint8_t[width_tmp*height_tmp*3];

    *width = width_tmp;
    *height = height_tmp;
    *array = array_tmp;

    uint32_t width_x3 = width_tmp * 3;

    for(int i = 0; i < height_tmp; i++){
        for(int j = 0; j < width_tmp; j++){
            gil::rgb8_pixel_t px = *img.at(j, i);
            for(int k = 0; k < 3; k++){
                array_tmp[i * width_x3 + j * 3 + k] = (uint8_t)px[k];
            }
        }
    }

    return true;
}

void resize_box(Box *box, float *from_h_w_to_h_w){
    float scale_h = from_h_w_to_h_w[2] / from_h_w_to_h_w[0];
    float scale_w = from_h_w_to_h_w[3] / from_h_w_to_h_w[1];

    //fprintf(stdout, "scale_h %.2f, scale_w %.2f", scale_h, scale_w);

    box->l *= scale_w;
    box->r *= scale_w;
    box->t *= scale_h;
    box->b *= scale_h;
}

void crop_image_and_save(gil::rgb8_image_t img, Prediction pred, int image_idx){
    gil::image_write_info<gil::jpeg_tag> write_settings;

    //crop image
    Box box = pred.box;
    gil::rgb8_image_t::view_t sv = boost::gil::subimage_view(gil::view(img), box.l, box.t, box.r-box.l, box.b-box.t);

    //generate filename
    char filename[100];
    sprintf(filename, "%s_conf_%.2f_%d.jpg", class_idx_to_name(pred.class_).c_str(), pred.class_probability, image_idx);

    //write to file
    gil::write_view(filename, sv, write_settings);
}

void log_class_found(Prediction pred, int image_idx)
{
    fprintf(stdout, "%d. {objectness: %.2f, class_idx: %2d, \n", image_idx, pred.objectness, pred.class_);
    fprintf(stdout, "class_name: %s,\n", class_idx_to_name(pred.class_).c_str());
    fprintf(stdout, "class_confidence: %.2f,\n", pred.class_probability);

    Box box = pred.box;
    fprintf(stdout, "size: {height:%d, width:%d},\n", box.b-box.t, box.r-box.l);
    fprintf(stdout, "coordinates: {x:[%d, %d], y:[%d, %d]},\n", box.l, box.r, box.t, box.b);
    fprintf(stdout, "}\n");
}

void print_help()
{
    fprintf(stdout, "Usage:\n");
    fprintf(stdout, "tcp_CLIENT <path to image> [-p <port number> -a <ip adress>]\n");
    fprintf(stdout, "Example:\n");
    fprintf(stdout, "tcp_CLIENT car.jpg -a 192.168.0.1 -p 1024\n");
    fprintf(stdout, "\n");
    fprintf(stdout, "-p --port - default is 20180\n");
    fprintf(stdout, "\n");
    fprintf(stdout, "-a --address - default is 127.0.0.1\n");
    fprintf(stdout, "\n");
    fprintf(stdout, "Supported image formats are: .jpg, .jpeg\n");
}

static inline bool is_file_exist(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

int main(int argc, char* argv[])
{
    if(argc < 2){
        print_help();
        return 1;
    }

    //parse "--key" args, set address and port
    int port = DEFAULT_TCP_SERVER_PORT;
    const char *address = DEFAULT_TCP_SERVER_ADRESS;
    for (int i = 0; i < argc; i++){
        if(std::strncmp(argv[i], "-p", 2) == 0 || std::strncmp(argv[i], "--port", 6) == 0){
            i++;
            port = atoi(argv[i]);
        }
        if(std::strncmp(argv[i], "-a", 2) == 0 || std::strncmp(argv[i], "--address", 9) == 0){
            i++;
            address = argv[i];
        }
        if(std::strncmp(argv[i], "-h", 2) == 0 || std::strncmp(argv[i], "--help", 6) == 0){
            print_help();
            return 0;
        }
    }
    ip::tcp::endpoint ep( ip::address::from_string(address), port);

    const char *image_path = argv[1];
    if( !is_file_exist(image_path) ){
        fprintf(stdout, "No such file or directory: %s\n", argv[1]);
        return 2;
    }

    //read image
    gil::rgb8_image_t img;
    std::string filename( image_path );
    gil::image_read_settings<gil::jpeg_tag> read_settings;
    gil::read_image( filename, img, read_settings);
    fprintf(stdout, "Image loaded. height = %d, width = %d\n", img.height(), img.width());

    //resize image
    boost::gil::rgb8_image_t img_sized(416, 416);
    gil::resize_view(gil::const_view(img), gil::view(img_sized), boost::gil::bilinear_sampler());

    //serialize image
    gil::rgb8_image_t::const_view_t cv = gil::const_view(img_sized);
    uint8_t *array = nullptr;
    int height = 0;
    int width = 0;
    image_to_array(cv, &array, &height, &width);
    long array_len = height*width*3;

    //establish tcp connection
    boost::asio::io_service io;
    ip::tcp::socket sock( io);
    sock.connect(ep);

    fprintf(stdout, "Connection established with %s:%d\n", address, port);

    //write image as bytes
    boost::asio::write(sock, buffer({height, width}, 2 * sizeof(int)));
    boost::asio::write(sock, buffer(array, array_len * sizeof(uint8_t)));

    fprintf(stdout, "Data sent\n");

    //receive answer from server
    const int buf_len = 1024;
    char *buf = new char[buf_len];
    boost::system::error_code error;
    size_t response_len_bytes = sock.read_some(boost::asio::buffer(buf, buf_len * sizeof(char)), error);

    fprintf(stdout, "Received bytes: %zd\n", response_len_bytes);

    //check answer for validity
    if(response_len_bytes < 1){
        fprintf(stdout, "Error: wrong response from server\n");
        sock.close();
        return 1;
    }

    char error_code = buf[0];

    if (error_code != 0){
        fprintf(stdout, "Error on server side. Error code: %d\n", error_code);
        sock.close();
        return 1;
    }

    //parse predictions and save to files
    Prediction *preds = (Prediction *)(buf + sizeof(char));
    int preds_len = (response_len_bytes-1)/sizeof(Prediction);

    for(int i = 0; i < preds_len; i++){
        Prediction pred = preds[i];

        float from_h_w_to_h_w[] = {416.0, 416.0, (float)img.height(), (float)img.width()};
        resize_box(&pred.box, from_h_w_to_h_w);

        crop_image_and_save(img, pred, i);
        log_class_found(pred, i);
    }

    //release resources
    delete [] buf;

    sock.close();
}