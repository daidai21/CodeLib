// g++ snowflake_test.cpp -std=c++11 -D DEBUG;./a.out


#include "snowflake.hpp"

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>


using namespace std;


void generate_uuid(int thread_id, SnowFlake& sf) {
  for (int i = 0; i < 20; ++i) {
    cout << thread_id << " " << i << " " << sf.next_id() << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
  }
}

int main() {
  SnowFlake sf(3, 4);
  vector<thread> tasks;
  for (int i = 0; i < 5; ++i) {
    tasks.push_back(thread(generate_uuid, i, ref(sf)));
  }
  for (auto& t : tasks) {
    t.join();
  }

  return 0;
}

