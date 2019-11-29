/* =============================================================================
> File Name: ThreadPool.hpp
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Fri 29 Nov 2019 05:59:08 PM CST
============================================================================= */


#ifndef THREADPOOL_HPP_
#define THREADPOOL_HPP_


#include <vector>
#include <queue>
#include <functional>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <stdexcept>
#include <future>
#include <memory>


class ThreadPool {
 public:
  ThreadPool(std::size_t threads) : stop(false) {
    for (std::size_t i = 0; i < threads; ++i) {
      workers.emplace_back(
        [this] {
          for(;;) {
            std::function<void()> task;
            {
              std::unique_lock<std::mutex> lock(this->queue_mutex);
              this->condition.wait(lock, [this]{ return this->stop || !this->tasks.empty(); });
              if (this->stop && this->tasks.empty())
                return ;
              task = std::move(this->tasks.front());
              this->tasks.pop();
            }
            task();
          }
        }
      );
    }
  }

  ~ThreadPool() {
    {
      std::unique_lock<std::mutex> lock(queue_mutex);
      this->stop = true;
    }
    this->condition.notify_all();
    for (std::thread& worker : workers)
      worker.join();
  }

  template <class F, class... Args>
  auto submit(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type> {
    using return_type = typename std::result_of<F(Args...)>::type;
    auto task = std::make_shared<std::packaged_task<return_type()>> (
      std::bind(std::forward<F>(f), std::forward<Args>(args)...)
    );
    std::future<return_type> result = task->get_future();
    {
      std::unique_lock<std::mutex> lock(this->queue_mutex);
      if (stop)
        throw std::runtime_error("submit() on stopped ThreadPool.");
      tasks.emplace([task]() { (*task)(); });
    }
    this->condition.notify_all();
    return result;
  }

  // TODO:
  // stop(); // stop thread ppol
  // join();
  // destroy();
  // shutdown();

 private:
  std::vector<std::thread> workers;
  std::queue<std::function<void()>> tasks;
  std::mutex queue_mutex;
  std::condition_variable condition;
  bool stop;

};

#endif // THREADPOOL_HPP_

