#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <sys/types.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <winsock2.h>

#pragma comment(lib,"Ws2_32.lib")

/*
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <err.h>*/

char response[] = "HTTP/1.1 200 OK\r\n"
                  "Content-Type: text/html; charset=UTF-8\r\n\r\n"
                  "<!DOCTYPE html><html><head><title>oops</title>"
                  "<style>body { background-color: #111 }"
                  "h1 { font-size:4cm; text-align: center; color: black;"
                  " text-shadow: 0 0 2mm red}</style></head>"
                  "<body><h1>not found</h1><h1>views:   </html>\r\n";

char response2[1000];


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

    int port = 8083;
    svr_addr.sin_family = AF_INET;
    svr_addr.sin_addr.s_addr = INADDR_ANY;
    svr_addr.sin_port = htons(port);

    if (bind(sock, (struct sockaddr *) &svr_addr, sizeof(svr_addr)) == -1) {
        close(sock);
        printf("Can't bind");
    }

    listen(sock, 5);
    while (1) {
        static int count = 0;
        client_fd = accept(sock, (struct sockaddr *) &cli_addr, &sin_len);
        printf("got connection\n");
        count++;
        if (client_fd == -1) {
            perror("Can't accept");
            continue;
        }
        sprintf(response2, " %s  %d ", response, count);
        send(client_fd, response2, sizeof(response2) - 1,0); /*-1:'\0'*/

        close(client_fd);




    }
    WSACleanup();
}

