/* =============================================================================
> File Name: thread.cpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Wed 09 Oct 2019 05:48:06 PM CST
============================================================================= */


#include <iostream>
#include <thread>
#include <vector>


using namespace std;


// global var
vector<int> vec;


void f1() {
    vec.push_back(1);
    cout << "now running f1()" << endl;
}

void f2() {
    vec.push_back(2);
    cout << "now running f2()" << endl;
}

void f3() {
    vec.push_back(3);
    cout << "now running f3()" << endl;
}


int main() {
    thread t1(f1);
    thread t2(f2);
    thread t3(f3);

    cout << "t1 id:" << t1.get_id() << endl;
    cout << "t2 id:" << t2.get_id() << endl;
    cout << "t3 id:" << t3.get_id() << endl;

    t1.join();
    t2.join();
    t3.join();

    cout << "all thread running over" << endl;

    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
    cout << endl;

    return 0;
}
