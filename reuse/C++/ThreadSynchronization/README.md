# Thread Synchronization


| Method | Describe | Applicable scenario | OS | Advantage | Shortcoming | Support(STL version is C++11) |
| - | - | - | - | - | - | - |
| Mutex |  |  |  |  | 性能慢 | STL, POSIX, Boost |
| Lock(锁) |  |  |  |  |  |  |
| 互斥锁 |  |  |  |  |  |  |
| 读写锁 |  |  |  |  |  |  |
| Semaphore(信号量) |  |  |  |  |  |  |
| Critical section(临界区) |  |  |  |  | 性能好 |  |
| Event |  |  |  |  |  |  |
| 条件变量 |  |  |  |  |  |  |
| Barrier(屏障) |  |  |  |  |  |  |
| sleep(线程休眠) + `while (1);` |  |  |  |  |  |
| `seched_yield();`(调整线程运行优先队列) + `while (1);` |  |  |  |  |  |
| Atomic variable + `while(1);` |  |  |  |  |  |
