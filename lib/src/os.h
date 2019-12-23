/* =============================================================================
> File Name: os.h
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 09 Dec 2019 11:38:35 AM CST
============================================================================= */


#ifndef DAIDAI_OS_H_
#define DAIDAI_OS_H_


#include <string>
#include <thread>

#include <sys/sysinfo.h>
#include <stdio.h>


namespace os {

// get ipv4 address
std::string ipv4();
std::string ipv6();


std::string env();
std::string homedir();
// get current working path
std::string cwd();

// get result of running command
std::string command(std::string);

std::string exepath();
std::string exename();
std::string pid();

// get CPU core number
inline int cpu_core_num() {
  return std::thread::hardware_concurrency();
}

// get memory size GB
inline int mem_size() {
  struct sysinfo sys_infor;
  if ( sysinfo(&sys_infor) == -1) {
    perror("Exec os::mem_size(), sysinfo()");
    exit(-1);
  }
  return sys_infor.totalram / 1024 / 1024 / 1024;
}

} // namespace os


#endif // DAIDAI_OS_H_

