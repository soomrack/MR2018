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


char response[] = "HTTP/1.1 200 OK\r\n"
                  "Content-Type: text/html; charset=UTF-8\r\n\r\n"
                  "<!DOCTYPE html><html><head><title>Hello World!</title></head>"
                  "<body><h1>Hello World!</h1></body></html>\r\n";

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

    int count = 0;
    char countout[5];
    listen(sock, 5);
    while (1) {
        client_fd = accept(sock, (struct sockaddr *) &cli_addr, &sin_len);
        count++;
        printf("got connection %d\n", count);

        if (client_fd == -1) {
            perror("Can't accept");
            continue;
        }
        sprintf(countout,"%d",count);
        send(client_fd, response, sizeof(response) - 1,0); /*-1:'\0'*/
        send(client_fd, &countout, sizeof(countout) - 1,0);
        close(client_fd);
    }
    WSACleanup();
}
