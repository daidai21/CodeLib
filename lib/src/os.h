/* =============================================================================
> File Name: os.h
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 09 Dec 2019 11:38:35 AM CST
============================================================================= */


#ifndef DAIDAI_OS_H_
#define DAIDAI_OS_H_


#include <string>


namespace os {


std::string env();
std::string homedir();
// get current working path
std::string cwd();

// get result of running command
std::command(std::string);

std::string exepath();
std::string exename();
std::string pid();


int cpu_num();
// get memory size GB
int mem_size();

} // namespace os


#endif // DAIDAI_OS_H_

