#include <stdio.h>
#include <stdlib.h>

#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>


#define BUF_SIZE    1024
#define PORT        8000
#define MAX_CONNECT 20


int main() {
  int i;
  int listen_fd;                // listen file descriptor
  int max_fd;
  int max_i;
  int clients[FD_SETSIZE];
  int n_ready;
  int conn_fd;
  int sock_fd;
  ssize_t n;                    // data type range [-1, SSIZE_MAX]
  ssize_t ret;
  fd_set allset;                // a fixed size buffer
  fd_set rset;
  socklen_t clie_len;           // ancillary data buffer len
  char buf[BUF_SIZE];
  struct sockaddr_in serv_addr; // server address
  struct sockaddr_in clie_addr; // client address

  // get listen fd
  listen_fd = socket(AF_INET, SOCK_STREAM, 0);

  // bind the socket
  bzero(&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(PORT);
  bind(listen_fd, (struct sockaddr* )& serv_addr, sizeof(serv_addr));

  // listen
  listen(listen_fd, MAX_CONNECT);

  // config select
  max_fd = listen_fd;
  max_i = -1;
  for (i = 0; i < FD_SETSIZE; ++i) {
    clients[i] = -1;
  }
  FD_ZERO(&allset); // clears a set
  FD_SET(listen_fd, &allset);

  // enter the server to receive the request loop
  while (1) {
    rset = allset;
    n_ready = select(max_fd + 1, &rset, NULL, NULL, NULL);
    if (FD_ISSET(listen_fd, &rset)) { // TODO
      clie_len = sizeof(clie_addr);
      printf("\naccpet connection~\n");
      if ( (conn_fd = accept(listen_fd, (struct sockaddr* )& clie_addr, &clie_len)) < 0) {
        perror("accept() error");
        exit(1);
      }
      printf("accept a new client: %s:%d\n", inet_ntoa(clie_addr.sin_addr), clie_addr.sin_port);

      // adds the customer link socket descriptor to the array
      for (i = 0; i < FD_SETSIZE; ++i) {
        if (clients[i] < 0) {
          clients[i] = conn_fd;
          break;
        }
      }
      if (i == FD_SETSIZE) {
        perror("too many connection");
        exit(1);
      }
      FD_SET(conn_fd, &allset);
      if (conn_fd > max_fd) {
        max_fd = conn_fd;
      }
      if (i > max_i) {
        max_i = i;      
      }
      n_ready--;
      if (n_ready < 0) {
        continue;
      }
    }

    for (i = 0; i < max_i; ++i) {
      if ( (sock_fd = clients[i]) < 0) {
        continue;
      }

      if (FD_ISSET(sock_fd, &rset) < 0) {
        // handle client requests
        printf("\nreading the socket~~~\n");
        bzero(buf, BUF_SIZE);
        if ( (n = read(sock_fd, buf, BUF_SIZE)) <= 0) {
          close(sock_fd);
          FD_CLR(sock_fd, &allset); // clear fd
          clients[i] = -1;
        } else {
          printf("client[%d] seed msg: %s\n", i, buf);
          if ( (ret = write(sock_fd, buf, n)) != n) {
            printf("error writting to the sock_fd");
            break;
          }
        }
        n_ready--;
        if (n_ready <= 0) {
          break;
        }
      }

    }

  }

  return 0;
}

