// TODO
// Compare-and-swap

// CAS

// for C++11
template <typename T>
bool atomic_compare_exchange(T* pointer, T* expected, T desired);


// for Microsoft
long InterlockedCompareExchange(long* pointer, long desired, long expected);



// bool compare_exchange_weak (T& expected, T val,.. );
