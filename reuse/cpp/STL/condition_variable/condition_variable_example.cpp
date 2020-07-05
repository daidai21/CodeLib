// std::condition_variable


#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>


using namespace std;


void non_condition_variable_f1() {
    cout << "now runnning f1()" << endl;
}

void non_condition_variable_f2() {
    cout << "now runnning f2()" << endl;
}

void non_condition_variable_f3() {
    cout << "now runnning f3()" << endl;
}


condition_variable cv;
int enbale_run_n = 1;


void add_condition_variable_f1() {
    cout << "now runnning f1()" << endl;
    enbale_run_n = 2;
    cv.notify_one();
}

void add_condition_variable_f2() {
    while (enbale_run_n != 2)
        wait(cv);
    cout << "now runnning f2()" << endl;
    enbale_run_n = 3;
    cv.notify_one();
}

void add_condition_variable_f3() {
    while (enbale_run_n != 3)
        wait(cv);
    cout << "now runnning f3()" << endl;
}

int main() {
    cout << "non condition_variable" << endl;
    thread t1(non_condition_variable_f1);
    thread t2(non_condition_variable_f2);
    thread t3(non_condition_variable_f3);
    t1.join();
    t2.join();
    t3.join();

    cout << "add condition_variable" << endl;
    thread t4(add_condition_variable_f1);
    thread t5(add_condition_variable_f2);
    thread t6(add_condition_variable_f3);
    t4.join();
    t5.join();
    t6.join();
}

