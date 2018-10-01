#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//#include <sys/types.h>
#include <winsock2.h>
//#include <time.h>
#include <windows.h>
#include <ws2tcpip.h>
#pragma comment(lib,"ws2_32.lib")

//#include <netinet/in.h>
//#include <netdb.h>
//#include <arpa/inet.h>
//#include <err.h>

char response[] = "HTTP/1.1 200 OK\r\n"
                  "Content-Type: text/html; charset=UTF-8\r\n\r\n"
                  "<!DOCTYPE html><html><head><title>Hello world</title></head>"
                  "<body><h1>Hello world</h1><h1>Обращений: ";
char response2[] = "</h1></body></html>";
char res[1000];
int counter = 0;
int main()
{
    WSADATA wsdata;
    WSAStartup(0x0101,&wsdata);
    int one = 1, client_fd;
    struct sockaddr_in svr_addr, cli_addr;
    SOCKET sin_len = sizeof(cli_addr);

    int sock = socket(AF_INET, SOCK_STREAM, 0); //int - SOCKET
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
        counter=rand()%100+1;
        if (client_fd == -1) {
            perror("Can't accept");
            continue;
        }
        sprintf(res,"%s %d", response, counter);
        strcat(res,response2);
        send(client_fd, res, sizeof(res) - 1, 0); /*-1:'\0'*/
        close(client_fd);
    }
    WSACleanup();
}
