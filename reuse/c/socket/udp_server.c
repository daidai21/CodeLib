#include <stdio.h>
#include <stdlib.h>

#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>


#define BUF_SIZE  1024
#define SERV_PORT 8000


int main(int argc, char* argv[]) {
  int sock_fd; // socket file descriptor
  struct sockaddr_in serv_addr;
  struct sockaddr_in clie_addr;

  bzero(&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family      = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // local address
  serv_addr.sin_port        = htons(SERV_PORT);

  if ( (sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) { // config udp
    perror("socket() error");
    exit(1);
  }
  if (bind(sock_fd, (struct sockaddr* )& serv_addr, sizeof(serv_addr))) {
    perror("bind() error");
    exit(1);
  }

  char buf[BUF_SIZE];
  socklen_t sock_len; // size of address
  int buf_recv_size;

  while(1) {
    sock_len = sizeof(clie_addr);
    if ( (buf_recv_size = recvfrom(sock_fd, buf, BUF_SIZE, 0, 
                                   (struct sockaddr *)& clie_addr, &sock_len)) < 0) {
      perror("recvfrom() error");
      exit(1);
    }
    if ( (buf_recv_size = sendto(sock_fd, buf, buf_recv_size, 0, 
                                 (struct sockaddr* )& clie_addr, sock_len)) < 0) {
      perror("sendto() error");
      exit(1);
    }
  }


  return 0;
}
