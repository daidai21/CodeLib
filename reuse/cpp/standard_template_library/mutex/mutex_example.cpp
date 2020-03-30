

#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>


using namespace std;


mutex m;


void non_lock(int n, char c) {
    for (int i = 0; i < n; ++i) {
        cout << c;
        this_thread::sleep_for(chrono::seconds(1));

    }
    cout << endl;
}


void add_lock(int n, char c) {
    m.lock();
    for (int i = 0; i < n; ++i)
        cout << c;
    cout << endl;
    m.unlock();
}


int main() {
    cout << "non_lock" << endl;
    thread t1(non_lock, 5, '|');
    thread t2(non_lock, 5, '-');
    t1.join();
    t2.join();

    cout << "add_lock" << endl;
    thread t3(add_lock, 5, '|');
    thread t4(add_lock, 5, '-');
    t3.join();
    t4.join();

    return 0;
}
