#ifndef __SNOWFLAKE_HPP__
#define __SNOWFLAKE_HPP__


#include <cstdint>
#include <mutex>
#include <cstdlib>

#include <sys/time.h>

#ifdef DEBUG
#  include <iostream>
#endif


/**
 * ID: 0 - 41 bits timestamp - 5 bits data center id - 5 bits machine id - 12 bits sequence number
 * support thread safe
 */
class SnowFlake {
 public:
  SnowFlake(const int data_center_id, const int machine_id);

  std::uint64_t next_id();

 private:
  std::uint64_t get_next_ms();
  std::uint64_t get_curr_timestamp();

 private:
  static const std::uint64_t start_timestamp = 1480166465631;

  static const std::uint64_t sequence_bit    = 12;
  static const std::uint64_t machine_bit     = 5;
  static const std::uint64_t data_center_bit = 5;

  static const std::uint64_t sequence_max_val    = -1 ^ (std::uint64_t(-1) << sequence_bit);
  static const std::uint64_t machine_max_val     = -1 ^ (std::uint64_t(-1) << machine_bit);
  static const std::uint64_t data_center_max_val = -1 ^ (std::uint64_t(-1) << data_center_bit);

  static const std::uint64_t machine_left     = sequence_bit;
  static const std::uint64_t data_center_left = sequence_bit + machine_bit;
  static const std::uint64_t timestamp_left   = data_center_left + data_center_bit;

  std::uint64_t data_center_id;
  std::uint64_t machine_id;
  std::uint64_t sequence_id;
  std::uint64_t last_timestamp;

  std::mutex mtx;
};

SnowFlake::SnowFlake(const int data_center_id, const int machine_id) {
  if ((std::uint64_t) data_center_id > this->data_center_max_val || data_center_id < 0) {
    throw "data_center_id can't be greater than this->data_center_max_val or less than 0";
    std::exit(1);
  }
  if ((std::uint64_t) machine_id > this->machine_max_val || machine_id < 0) {
    throw "machine_id can't be greater than this->machine_max_val or less than 0";
    std::exit(1);
  }

  this->data_center_id = data_center_id;
  this->machine_id     = machine_id;
  this->sequence_id = 0;
  this->last_timestamp = 0;

#ifdef DEBUG
  std::cout << "sequence_max_val:    " << this->sequence_max_val    << std::endl;
  std::cout << "machine_max_val:     " << this->machine_max_val     << std::endl;
  std::cout << "data_center_max_val: " << this->data_center_max_val << std::endl;
#endif
}

std::uint64_t SnowFlake::next_id() {
#ifdef DEBUG
  std::cout << "last_timestamp: " << this->last_timestamp << std::endl;
  std::cout << "sequence_id:    " << this->sequence_id    << std::endl;
#endif

  std::unique_lock<std::mutex> lock(this->mtx);

  std::uint64_t curr_timestamp = this->get_curr_timestamp();
  // judge the clock to go back
  if (curr_timestamp < this->last_timestamp) {
    throw "Clock moved backwards. Refusing to generate id";
    std::exit(1);
  }
  // the same as ms, using sequence_id++
  if (curr_timestamp == this->last_timestamp) {
    this->sequence_id = (this->sequence_id + 1) & this->sequence_max_val;
    if (this->sequence_id == 0) {
      curr_timestamp = this->get_next_ms();
    }
  } else {
    this->sequence_id = 0;
  }
  this->last_timestamp = curr_timestamp;
  // join 64 bits, return result
  return ((curr_timestamp - this->start_timestamp) << this->timestamp_left) // timestamp segment
         | this->data_center_max_val << this->data_center_left              // data center segment
         | this->machine_id << this->machine_left                           // machine segment
         | this->sequence_id;                                               // sequence segment
}

std::uint64_t SnowFlake::get_next_ms() {
  std::uint64_t mill = this->get_curr_timestamp();
  while (mill <= this->last_timestamp) {
    mill = this->get_curr_timestamp();
  }
  return mill;
}

std::uint64_t SnowFlake::get_curr_timestamp() {
  struct timeval tv;
  gettimeofday(&tv, NULL);

  std::uint64_t now = tv.tv_usec;
  now /= 1000;
  now += (tv.tv_sec * 1000);
  return now;
}


#endif // __SNOWFLAKE_HPP__

