#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <err.h>
#include <string.h>

const char response[] = "HTTP/1.1 200 OK\r\n"
"Content-Type: text/html; charset=UTF-8\r\n\r\n"
"<!DOCTYPE html><html><head><title>Vlbager</title></head>"
"<body><h1>Hello world!</h1><h1>Обращений: ";
char res[10000];

/*
  Поиск в cli_info параметра, перед которым стоит '?'
  Значение записывается в аргумент parameter
*/
void getparameter(char* parameter, char* cli_info, size_t lenght) {
    for (int i = 0; i < lenght; i++) {
        if (cli_info[i] == '?') {
            for (int j = i; j < lenght; j++) {
                if (cli_info[j] == ' ') {
                    strncpy(parameter, &cli_info[i+1], (size_t) j - i - 1);
                    break;
                }
            }
            break;
        }
    }
}

int main()
{
  int one = 1, client_fd = 0;
  struct sockaddr_in svr_addr, cli_addr;
  socklen_t sin_len = sizeof(cli_addr);

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0)
    err(1, "can't open socket");

  setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(int));

  int port = 8080;
  svr_addr.sin_family = AF_INET;
  svr_addr.sin_addr.s_addr = INADDR_ANY;
  svr_addr.sin_port = htons(port);

  if (bind(sock, (struct sockaddr *) &svr_addr, sizeof(svr_addr)) == -1) {
    close(sock);
    err(1, "Can't bind");
  }

  listen(sock, 5);

  while (1) {
    client_fd = accept(sock, (struct sockaddr *) &cli_addr, &sin_len);

    printf("got connection\n");


    if (client_fd == -1) {
      perror("Can't accept");
      continue;
    }

    static int counter = 0;
    counter++;
    memset(res, 0, 10000);
    sprintf(res, "%s %i", response, counter);

    char cli_info[1000];
    char parameter[1000];
    static ssize_t cli_addr_len;

    cli_addr_len = recv(client_fd, cli_info, 999, 0);
    memset(parameter, 0, 1000);
    getparameter(parameter, cli_info, (size_t) cli_addr_len);
    strcat(res, "</h1><h1>Параметр: ");
    strcat(res, parameter);

    strcat(res, "</h1></body></html>");
    write(client_fd, res, sizeof(res) - 1); /*-1:'\0'*/
    close(client_fd);
  }
}
