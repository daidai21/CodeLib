/* ****************************************************************************
 * File Name   : tcp_client.c
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 一  2/15 21:15:01 2021
 *************************************************************************** */

#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

const int MAX_LINE = 2048;
const int PORT = 6000;
const int BACKLOG = 10;
const int LISTENQ = 6666;
const int MAX_CONNECT = 20;

/*readline函数实现*/
ssize_t readline(int fd, char* vptr, size_t maxlen) {
  ssize_t n, rc;
  char c, *ptr;

  ptr = vptr;
  for (n = 1; n < maxlen; n++) {
    if ((rc = read(fd, &c, 1)) == 1) {
      *ptr++ = c;
      if (c == '\n')
        break; /* newline is stored, like fgets() */
    } else if (rc == 0) {
      *ptr = 0;
      return (n - 1); /* EOF, n - 1 bytes were read */
    } else
      return (-1); /* error, errno set by read() */
  }

  *ptr = 0; /* null terminate like fgets() */
  return (n);
}

int main(int argc, char* argv[]) {
  /*声明套接字和链接服务器地址*/
  int sockfd;
  struct sockaddr_in servaddr;

  /*判断是否为合法输入*/
  if (argc != 2) {
    perror("usage:tcpcli <IPaddress>");
    exit(1);
  }

  /*(1) 创建套接字*/
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket error");
    exit(1);
  }
  /*(2) 设置链接服务器地址结构*/
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) < 0) {
    printf("inet_pton error for %s\n", argv[1]);
    exit(1);
  }

  /*(3) 发送链接服务器请求*/
  if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect error");
    exit(1);
  }
  /*(4) 消息处理*/
  char sendline[MAX_LINE], recvline[MAX_LINE];
  while (fgets(sendline, MAX_LINE, stdin) != NULL) {
    write(sockfd, sendline, strlen(sendline));

    if (readline(sockfd, recvline, MAX_LINE) == 0) {
      perror("server terminated prematurely");
      exit(1);
    }

    if (fputs(recvline, stdout) == EOF) {
      perror("fputs error");
      exit(1);
    }
  }

  /*(5) 关闭套接字*/
  close(sockfd);
  return 0;
}
