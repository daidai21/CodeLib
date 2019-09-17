/* =============================================================================
> File Name: set_process_id_information.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 09 Sep 2019 09:36:29 PM CST
============================================================================= */


/*
  test only one example

  API
    int setuid(uid_t uid);
    int setpid(gid_t gid);
    int setreuid(uid_t ruid, uid_t euid);
    int setregid(gid_t rgid, uid_t egid);
    int seteuid(uid_t uid);
    int setegid(uid_t gid);
    int setpgid(pid_t pid,pid_t pgid);
*/


#include <stdio.h>
#include <unistd.h>


int main() {
  printf("actual user id of call process %d\n", getuid());
  if (setuid(1000) < 0)
    printf("setuid exec error\n");
  else
    printf("actual user id of call process %d\n", getuid());

  return 0;
}
