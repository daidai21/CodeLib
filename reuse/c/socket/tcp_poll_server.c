/* =============================================================================
> File Name: tcp_poll_server.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Fri 13 Mar 2020 10:16:59 PM CST
============================================================================= */
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h> /*for OPEN_MAX*/
#include <netdb.h>
#include <netinet/in.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#ifndef OPEN_MAX
#define OPEN_MAX 1024
#endif

#ifndef INFTIM
#define INFTIM -1
#endif

#define PORT 8888
#define MAX_LINE 2048
#define LISTENQ 20

int main(int argc, char* argv[]) {
  int i, maxi, listenfd, connfd, sockfd;

  int nready;

  ssize_t n, ret;

  struct pollfd client[OPEN_MAX];

  char buf[MAX_LINE];

  socklen_t clilen;

  struct sockaddr_in servaddr, cliaddr;

  /*(1) 得到监听描述符*/
  listenfd = socket(AF_INET, SOCK_STREAM, 0);

  /*(2) 绑定套接字*/
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(PORT);

  bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

  /*(3) 监听*/
  listen(listenfd, LISTENQ);

  /*(4) 设置poll*/
  client[0].fd = listenfd;
  client[0].events = POLLRDNORM; // POLLRDNORM是 有普通数据可读
  for (i = 1; i < OPEN_MAX; ++i) {
    client[i].fd = -1;
  }
  maxi = 0;

  /*(5) 进入服务器接收请求死循环*/
  while (1) {
    nready = poll(client, maxi + 1, INFTIM);

    if (client[0].revents & POLLRDNORM) {
      /*接收客户端的请求*/
      clilen = sizeof(cliaddr);

      printf("\naccpet connection~\n");

      if ((connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &clilen)) < 0) {
        perror("accept error.\n");
        exit(1);
      }

      printf("accpet a new client: %s:%d\n", inet_ntoa(cliaddr.sin_addr), cliaddr.sin_port);

      /*将客户链接套接字描述符添加到数组*/
      for (i = 1; i < OPEN_MAX; ++i) {
        if (client[i].fd < 0) {
          client[i].fd = connfd;
          break;
        }
      }

      if (OPEN_MAX == i) {
        perror("too many connection.\n");
        exit(1);
      }

      /*该描述符等待的事件*/
      client[i].events = POLLRDNORM;
      if (i > maxi)
        maxi = i;

      if (--nready < 0)
        continue;
    }

    for (i = 1; i <= maxi; ++i) {
      if ((sockfd = client[i].fd) < 0)
        continue;
      /*该链接描述符实际发生的事件*/
      if (client[i].revents & (POLLRDNORM | POLLERR)) { // POLLERR是出错
        /*处理客户请求*/
        printf("\nreading the socket~~~ \n");

        bzero(buf, MAX_LINE);
        if ((n = read(sockfd, buf, MAX_LINE)) <= 0) {
          close(sockfd);
          client[i].fd = -1;
        } else {
          printf("clint[%d] send message: %s\n", i, buf);
          if ((ret = write(sockfd, buf, n)) != n) {
            printf("error writing to the sockfd!\n");
            break;
          }
        }
        if (--nready <= 0)
          break;
      }
    }
  }
  exit(0);
}
