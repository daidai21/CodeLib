#include <stdlib.h>
#include <stdio.h>

#include <sys/sysinfo.h>


// get memory size GB
inline int mem_size() {
  struct sysinfo sys_infor;
  if ( sysinfo(&sys_infor) == -1) {
    perror("Exec os::mem_size(), sysinfo()");
    exit(-1);
  }
  return sys_infor.totalram / 1024 / 1024 / 1024;
}
