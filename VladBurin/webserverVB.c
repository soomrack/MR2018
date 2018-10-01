#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <err.h>



char response[] = "HTTP/1.1 200 OK\r\n"
                  "Content-Type: text/html; charset=UTF-8\r\n\r\n"
                  "<!DOCTYPE html><html><head><title>Hello World!</title></head>"
                  "<body><h1>Hello World!</h1><h1>Обращений: ";
char response2[] = "</h1></body></html>";
char res[250];


int main()
{
  int one = 1, client_fd;
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
    static int counter = 0;
    printf("got connection\n");
    counter++;
    if (client_fd == -1) {
      perror("Can't accept");
      continue;
    }

      sprintf(res, "%s %i", response, counter);

      strcat(res, response2);



      write(client_fd, res, sizeof(res) - 1); /*-1:'\0'*/
    close(client_fd);
  }
}
