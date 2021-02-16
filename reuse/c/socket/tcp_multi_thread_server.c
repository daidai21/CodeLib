/* =============================================================================
> File Name: tcp_multi_thread_server.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Fri 13 Mar 2020 10:15:59 PM CST
============================================================================= */

/**
 * 只是创建了一个子线程处理msg
 */

#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

const int MAX_LINE = 2048;
const int PORT = 6001;
const int BACKLOG = 10;
const int LISTENQ = 6666;
const int MAX_CONNECT = 20;

/*处理接收客户端消息函数*/
void *recv_message(void *fd) {
  int sockfd = *(int *)fd;
  while (1) {
    char buf[MAX_LINE];
    memset(buf, 0, MAX_LINE);
    int n;
    if ((n = recv(sockfd, buf, MAX_LINE, 0)) == -1) {
      perror("recv error.\n");
      exit(1);
    }
    buf[n] = '\0';
    //若收到的是exit字符，则代表退出通信
    if (strcmp(buf, "byebye.") == 0) {
      printf("Client closed.\n");
      close(sockfd);
      exit(1);
    }

    printf("\nClient: %s\n", buf);
  }
}

int main(int argc, char *argv[]) {
  //声明套接字
  int listenfd, connfd;
  socklen_t clilen;
  //声明线程ID
  pthread_t recv_tid, send_tid;

  //定义地址结构
  struct sockaddr_in servaddr, cliaddr;

  /*(1) 创建套接字*/
  if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket error.\n");
    exit(1);
  }

  /*(2) 初始化地址结构*/
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(PORT);

  /*(3) 绑定套接字和端口*/
  if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("bind error.\n");
    exit(1);
  }

  /*(4) 监听*/
  if (listen(listenfd, LISTENQ) < 0) {
    perror("listen error.\n");
    exit(1);
  }

  /*(5) 接受客户请求，并创建线程处理*/

  clilen = sizeof(cliaddr);
  if ((connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen)) < 0) {
    perror("accept error.\n");
    exit(1);
  }

  printf("server: got connection from %s\n", inet_ntoa(cliaddr.sin_addr));

  /*创建子线程处理该客户链接接收消息*/
  if (pthread_create(&recv_tid, NULL, recv_message, &connfd) == -1) {
    perror("pthread create error.\n");
    exit(1);
  }

  /*处理服务器发送消息*/
  char msg[MAX_LINE];
  memset(msg, 0, MAX_LINE);
  while (fgets(msg, MAX_LINE, stdin) != NULL) {
    if (strcmp(msg, "exit\n") == 0) {
      printf("byebye.\n");
      memset(msg, 0, MAX_LINE);
      strcpy(msg, "byebye.");
      send(connfd, msg, strlen(msg), 0);
      close(connfd);
      exit(0);
    }

    if (send(connfd, msg, strlen(msg), 0) == -1) {
      perror("send error.\n");
      exit(1);
    }
  }
  return 0;
}
