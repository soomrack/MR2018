#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/*
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <err.h>
*/
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
// link with Ws2_32.lib
#pragma comment(lib,"Ws2_32.lib")

int i=0;
char response[2000];
char begin[]= "HTTP/1.1 200 OK\r\n"
                  "Content-Type: text/html; charset=UTF-8\r\n\r\n"
                  "<!DOCTYPE html><html><head><title>Hello World!2</title></head>"
                  "<body><h1>Hello World!</h1><h3>Значение переменной";
                  char end[]="<h3></h3>конец программы</h3></body></html>\r\n";

int main()
{
    WSADATA wsdata;
    WSAStartup(0x0101,&wsdata);
    int one = 1, client_fd;
    struct sockaddr_in svr_addr, cli_addr;
    socklen_t sin_len = sizeof(cli_addr);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
        printf("can't open socket");

    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(int));

    int port = 8080;
    svr_addr.sin_family = AF_INET;
    svr_addr.sin_addr.s_addr = INADDR_ANY;
    svr_addr.sin_port = htons(port);

    if (bind(sock, (struct sockaddr *) &svr_addr, sizeof(svr_addr)) == -1) {
        close(sock);
        printf("Can't bind");
    }

    listen(sock, 5);
    while (1) {
        client_fd = accept(sock, (struct sockaddr *) &cli_addr, &sin_len);
        printf("got connection\n");
        sleep(1);
        i++;
        sprintf(response,"%s%d%s",begin,i,end);
        printf("%s",response);

        if (client_fd == -1) {
            perror("Can't accept");
            continue;
        }

        send(client_fd, response, sizeof(response) - 1,0); /*-1:'\0'*/
        close(client_fd);
    }
    WSACleanup();
}