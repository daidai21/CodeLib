#include <stdio.h>
#include <stdlib.h>

#include <sys/select.h>
#include <sys/socket.h>
#include <strings.h>
#include <arpa/inet.h>


#define PORT     8000
#define BUF_SIZE 1024


#define max(a, b) (a > b ? a : b)

// TODO
ssize_t readline(int fd, char* vptr, size_t max_len) {
  return ;
}

void clie() {
}

void clie_select() {
}

int main(int argc, char* argv[]) {
  // judge input valid
  if (argc != 2) {
    perror("input IP address");
    exit(1);
  }
  // declare socket and link server address
  int sock_fd;
  struct sockaddr_in serv_addr;
  // create socket
  if ( (sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket() error");
    exit(1);
  }
  // config link server address structure
  bzero(&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port   = htons(PORT);
  if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) < 0) {
    printf("inet_pton() error for %s\n", argv[1]);
    exit(1);
  }
  // send link server request
  if (connect(sock_fd, (struct sockaddr_in*)& serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect() error");
    exit(1);
  }
  // call msg handle function
  clie(sock_fd);
  // call msg handle function with select()
  // clie_select(stdin, sock_fd);

  return 0;
}
