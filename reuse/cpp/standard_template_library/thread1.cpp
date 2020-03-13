/* =============================================================================
> File Name: thread1.cpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Wed 09 Oct 2019 06:06:50 PM CST
============================================================================= */


#include <iostream>
#include <thread>
#include <vector>
#include <chrono>


using namespace std;


void f() {
    cout << "start running f()" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "exit running f()" << endl;
}

int main() {
    cout << "start init thead" << endl;
    thread t(f);
    t.detach();
    this_thread::sleep_for(chrono::seconds(1));
    cout << "exit thread" << endl;

    this_thread::sleep_for(chrono::seconds(3));
    return 0;
}
