/* ****************************************************************************
 * File Name   : tcp_server.c
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 一  2/15 21:15:07 2021
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
const int PORT = 6000;   // 端口
const int BACKLOG = 10;  //
const int LISTENQ = 6666;
const int MAX_CONNECT = 20;

/**
 * 输出接收到的信息
 */
void output_char_array(const char* msg, ssize_t len) {
  for (int i = 0; i < len; ++i) {
    printf("%c", msg[i]);
  }
  printf("\n");
}

int main(int argc, char* argv[]) {
  /*声明服务器地址和客户链接地址*/
  struct sockaddr_in servaddr, cliaddr;  // sockaddr_in处理因特网地址的结构

  /*声明服务器监听套接字和客户端链接套接字*/
  int listenfd, connfd;
  pid_t childpid;  // 进程id

  /*声明缓冲区*/
  // char buf[MAX_LINE];

  socklen_t clilen;  // 数据字节计数
  /* (1) 初始化监听套接字listenfd*/
  if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {  // AF_INET是IPv4,  SOCK_STREAM是tcp
    perror("socket error");
    exit(1);
  }
  /*(2) 设置服务器sockaddr_in结构*/
  bzero(&servaddr, sizeof(servaddr));  // 会将内存块（字符串）的前n个字节清零

  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);  //表明可接受任意IP地址
  servaddr.sin_port = htons(PORT);

  /*(3) 绑定套接字和端口*/
  if (bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
    perror("bind error");
    exit(1);
  }

  /*(4) 监听客户请求*/
  if (listen(listenfd, LISTENQ) < 0) {
    perror("listen error");
    exit(1);
  }

  /*(5) 接受客户请求*/
  for (;;) {
    clilen = sizeof(cliaddr);
    if ((connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &clilen)) < 0) {
      perror("accept error");
      exit(1);
    }

    //新建子进程单独处理链接
    if ((childpid = fork()) == 0) {
      close(listenfd);
      //str_echo
      ssize_t n;
      char buff[MAX_LINE];
      while ((n = read(connfd, buff, MAX_LINE)) > 0) {
        output_char_array(buff, n); // 输出接收到的msg
        write(connfd, buff, n);
      }
      exit(0);
    }
    close(connfd);
  }

  /*(6) 关闭监听套接字*/
  close(listenfd);

  return 0;
}
