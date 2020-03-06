


#define bool  int
#define false 0
#define true  1




#define tyte char



// TODO
#define CAS(val, oldval, newval) \
    __sync_bool_compare_and_swap((val), (oldval), (newval))


extern void bind_core(int64_t core_id);



#define MAX(a,b) ((a) > (b)) ? (a) : (b)
#define MIN(a,b) ((a) < (b)) ? (a) : (b)

