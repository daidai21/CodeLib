#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <strings.h>
#include <arpa/inet.h>


#define SERV_PORT 8000
#define BUF_SIZE  1024


int main(int argc, char* argv[]) {
  int sock_fd; // socket file descriptor
  struct sockaddr_in serv_addr;
  if (argc != 2) {
    perror("main() param error"); // TODO
    exit(1);
  }

  bzero(&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(SERV_PORT);

  if ( inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
    perror("inet_pton() error");
    exit(1);
  }
  if ( (sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) { // SOCK_DGRAM 指定socket类型UDP
    perror("socket() error");
    exit(1);
  }

  int buf_recv_len;
  char send_line[BUF_SIZE];
  char recv_line[BUF_SIZE + 1];
  while( fgets(send_line, BUF_SIZE, stdin) != NULL) {
    if (sendto(sock_fd, send_line, strlen(send_line), 0, 
               (struct sockaddr*)& serv_addr, sizeof(serv_addr)) < 0) {
      perror("sendto() error");
      exit(1);
    }
    if ( (buf_recv_len = recvfrom(sock_fd, recv_line, BUF_SIZE, 0, NULL, NULL)) < 0) {
      perror("recvfrom() error");
      exit(1);
    }
    recv_line[buf_recv_len] = '\0';
    fputs(recv_line, stdout);
  }


  return 0;
}
