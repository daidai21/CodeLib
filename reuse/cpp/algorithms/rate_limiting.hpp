// all algorithm support thread safe here.


#include <iostream>
#include <ctime>
#include <mutex>
#include <algorithm>


namespace rate_limiting {


// counter algorithm
class Counter {
 public:
  // limit is the number of times within an interval
  // interval is interval size, the unit is ms
  Counter(const unsigned long long int& limit, const unsigned long long int& interval);

  // dose not limit the flow to return true
  bool grant();

 private:
  std::time_t            timestamp;
  unsigned long long int req_cnt;
  unsigned long long int limit;
  unsigned long long int interval;
  std::mutex             mtx;
};

Counter::Counter(const unsigned long long int& limit, const unsigned long long int& interval) {
  this->limit     = limit;
  this->interval  = interval;
  this->req_cnt   = 0;
  this->timestamp = std::time(nullptr);
  // std::cout << this->timestamp << std::endl;
}

bool Counter::grant() {
  this->mtx.lock();
  std::time_t now = std::time(nullptr);
  if (now < this->timestamp + this->interval) {
    this->req_cnt++;
    return this->req_cnt <= this->limit;
  } else {
    this->timestamp = std::time(nullptr);
    this->req_cnt = 1;
    return true;
  }
  this->mtx.unlock();
}


// leaky bucket algorithm
// https://en.wikipedia.org/wiki/Leaky_bucket
class LeakyBucket {
 public:
  LeakyBucket(const unsigned long long int& cap, const unsigned long long int& leak_rate);

  bool consume(const unsigned long long int& drop);

 private:
  void leak();

 private:
  unsigned long long int cap; // capacity
  unsigned long long int leak_rate;
  std::time_t            last_leak_timestamp;
  unsigned long long int used;
  std::mutex             mtx;
};

LeakyBucket::LeakyBucket(const unsigned long long int& cap, const unsigned long long int& leak_rate) {
  this->cap                 = cap; // capacity
  this->leak_rate           = leak_rate; // leak space every ms
  this->last_leak_timestamp = std::time(nullptr);
  this->used                = 0;
}

bool LeakyBucket::consume(const unsigned long long int& drop) {
  this->mtx.lock();
  this->leak();
  if (this->used + drop > this->cap)
    return false;
  this->used += drop;
  return true;
  this->mtx.unlock();
}

void LeakyBucket::leak() {
  std::time_t now = std::time(nullptr);
  if (now > this->last_leak_timestamp) {
    unsigned long long int leaks = (unsigned long long int)(now - this->last_leak_timestamp) / this->leak_rate;
    if (leaks > 0) {
      if (this->used <= leaks) {
        this->used = 0;
      } else {
        this->used -= (unsigned long long int) leaks;
      }
      this->last_leak_timestamp = std::time(nullptr);
    }
  }
}


// token bucket algorithm
// https://en.wikipedia.org/wiki/Token_bucket
class TokenBucket {
 public:
  TokenBucket(const unsigned long long int& cap, const unsigned long long int& refill_tokens, 
              const unsigned long long int& refill_period_ms);

  bool consume(const unsigned long long int& num_tokens);

 private:
  void refill();

 private:
  unsigned long long int cap; // capacity
  double                 refill_rate; // refill tokens one ms
  unsigned long long int available_tokens;
  std::time_t            last_refill_timestamp;
  std::mutex             mtx;
};

TokenBucket::TokenBucket(const unsigned long long int& cap, const unsigned long long int& refill_tokens, 
                         const unsigned long long int& refill_period_ms) {
  this->cap                   = cap; // capacity
  this->refill_rate           = refill_tokens / refill_period_ms;
  this->available_tokens      = cap;
  this->last_refill_timestamp = std::time(nullptr);
}

bool TokenBucket::consume(const unsigned long long& num_tokens) {
  this->mtx.lock();
  this->refill();
  if (this->available_tokens < num_tokens) {
    return false;
  } else {
    this->available_tokens -= num_tokens;
    return true;
  }
  this->mtx.unlock();
}

void TokenBucket::refill() {
  std::time_t now = std::time(nullptr);
  if (now > this->last_refill_timestamp) {
    double refill_tokens = (now - this->last_refill_timestamp) * this->refill_rate;
    this->available_tokens = std::min(this->cap, 
                                      this->available_tokens + (unsigned long long int)refill_tokens);
    this->last_refill_timestamp = std::time(nullptr);
  }
}


} // namespace rate_limiting

