/* =============================================================================
> File Name: thread_pool.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Fri 29 Nov 2019 03:28:03 PM CST
============================================================================= */


#include "thread_pool.h"

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/prctl.h>
#include <signal.h>
#include <stdlib.h>

#ifdef THREAD_POOL_DEBUG
#define THREAD_POOL_DEBUG 1
#else
#define THREAD_POOL_DEBUG 0
#endif


static volatile int g_threads_keep_alive;
static volatile int g_threads_on_hold;


/******************** STRUCTURES ********************/


/* Binary semaphore */
typedef struct bin_sem {
  pthread_mutex_t mutex;
  pthread_cond_t cond;
  int value;
} bin_sem;


/* Job */
typedef struct job {
  struct job* prev;
  void (* func)(void* arg);
  void* arg;
} job;


/* Jog queue */
typedef struct job_queue {
  pthread_mutex_t rwmutex;
  job* front;
  job* end;
  bin_sem* has_jobs;
  unsigned int len;
} job_queue;


/* Thread */
typedef struct thread {
  unsigned int id;
  pthread_t pthread;
  struct thread_pool_t* thread_pool_p;
} thread;


/* Threadpool */
struct thread_pool_t {
  thread** threads;
  volatile unsigned int num_threads_alive;
  volatile unsigned int num_threads_working;
  pthread_mutex_t thread_count_lock;
  pthread_cond_t threads_all_idle;
  job_queue job_queue;
} thread_pool_t;


/* */
typedef struct thread_pool_t* thread_pool_p;

/******************** PROTOTYPES ********************/

static int thread_init(thread_pool_p tp_p, struct thread** thread_p, int id);
static void* thread_do(struct thread* thread_p);
static void thread_hold(int sig_id);
static void thread_destroy(thread* thread_p);

static int job_queue_init(job_queue* job_queue_p);
static void job_queue_clear(job_queue* job_queue_p);
static void job_queue_push(job_queue* job_queue_p, struct job* new_job);
static struct job* job_queue_pull(job_queue* job_queue_p);
static int job_queue_destroy(job_queue* job_queue_p);

static void bin_sem_init(bin_sem* bin_sem_p, int value);
static void bin_sem_reset(bin_sem* bin_sem_p);
static void bin_sem_post(bin_sem* bin_sem_p);
static void bin_sem_post_all(bin_sem* bin_sem_p);
static void bin_sem_wait(bin_sem* bin_sem_p);

thread_pool_p thread_pool_init(unsigned int num_threads);
int thread_pool_add_work(thread_pool_p tp_p, void (* func)(void* ), void* arg_p);
void thread_pool_wait(thread_pool_p tp_p);
void thread_pool_destroy(thread_pool_p tp_p);
void thread_pool_puse(thread_pool_p tp_p);
void thread_pool_resume(thread_pool_p tp_p);


/******************** THREAD ********************/


/*  */
static int thread_init(thread_pool_p tp_p, struct thread** thread_p, int id) {
  *thread_p = (struct thread* ) malloc(sizeof(struct thread));
  if (* thread_p == NULL) {
    perror("thread_init(): Could not allocate memory for thread");
    return -1;
  }
  (* thread_p)->thread_pool_p = tp_p;
  (* thread_p)->id = id;
  pthread_create(&(* thread_p)->pthread, NULL, (void* )thread_do, (* thread_p));
  pthread_detach((* thread_p)->pthread);
  return 0;
}


/*  */
static void* thread_do(struct thread* thread_p) {
  char thread_name[128] = {0};
  sprintf(thread_name, "thread_pool--%d", thread_p->id);
#if defined(__linux__)
  prctl(PR_SET_NAME, thread_name);
#elif defined(__APPLE__) && defined(__MACH__)
	pthread_setname_np(thread_name);
#else
  fprintf(stderr, "thread_do(): pthread_setname_np() is not suported on this system");
#endif
  thread_pool_p tp_p = thread_p->thread_pool_p;
  struct sigaction act;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;
  act.sa_handler = thread_hold;
  if (sigaction(SIGUSR1, &act, NULL) == -1)
    perror("thread_do(): Cannot handle SIGUSR1");
  pthread_mutex_lock(&tp_p->thread_count_lock);
  tp_p->num_threads_alive += 1;
  pthread_mutex_unlock(&tp_p->thread_count_lock);
  while (g_threads_keep_alive) {
    bin_sem_wait(tp_p->job_queue.has_jobs);
    if (g_threads_keep_alive) {
      pthread_mutex_lock(&tp_p->thread_count_lock);
      tp_p->num_threads_working++;
      pthread_mutex_unlock(&tp_p->thread_count_lock);
      void (*func_buff)(void* );
      void* arg_buff;
      job* job_p = job_queue_pull(&tp_p->job_queue);
      if (job_p) {
        func_buff = job_p->func;
        arg_buff = job_p->arg;
        func_buff(arg_buff);
        free(job_p);
      }
      pthread_mutex_lock(&tp_p->thread_count_lock);
      tp_p->num_threads_working--;
      if (!tp_p->num_threads_working)
        pthread_cond_signal(&tp_p->threads_all_idle);
      pthread_mutex_unlock(&tp_p->thread_count_lock);
    }
  }
  pthread_mutex_lock(&tp_p->thread_count_lock);
  tp_p->num_threads_alive--;
  pthread_mutex_unlock(&tp_p->thread_count_lock);
  return NULL;
}


/*  */
static void thread_hold(int sig_id) {
  (void)sig_id;
  g_threads_on_hold = 1;
  while (g_threads_on_hold)
    sleep(1);
}


/*  */
static void thread_destroy(thread* thread_p) {
  free(thread_p);
}


/******************** JOB QUEUE ********************/


/*  */
static int job_queue_init(job_queue* job_queue_p) {
  job_queue_p->len = 0;
  job_queue_p->front = NULL;
  job_queue_p->end = NULL;
  job_queue_p->has_jobs = (struct bin_sem* ) malloc(sizeof(struct bin_sem));
  if (job_queue_p->has_jobs == NULL)
    return -1;
  pthread_mutex_init(&(job_queue_p->rwmutex), NULL);
  bin_sem_init(job_queue_p->has_jobs, 0);
}


/*  */
static void job_queue_clear(job_queue* job_queue_p) {
  while (job_queue_p->len)
    free(job_queue_pull(job_queue_p));
  job_queue_p->front = NULL;
  job_queue_p->end = NULL;
  bin_sem_reset(job_queue_p->has_jobs);
  job_queue_p->len = 0;
}


/*  */
static void job_queue_push(job_queue* job_queue_p, struct job* new_job) {
  pthread_mutex_lock(&job_queue_p->rwmutex);
  new_job->prev = NULL;
  switch (job_queue_p->len) {
  case 0:
    job_queue_p->front = new_job;
    job_queue_p->end = new_job;
    break;
  default:
    job_queue_p->end->prev = new_job;
    job_queue_p->end = new_job;
    break;
  }
  job_queue_p->len++;
  bin_sem_post(job_queue_p->has_jobs);
  pthread_mutex_unlock(&job_queue_p->rwmutex);
}


/*  */
static struct job* job_queue_pull(job_queue* job_queue_p) {
  pthread_mutex_lock(&job_queue_p->rwmutex);
  job* job_p = job_queue_p->front;
  switch (job_queue_p->len) {
  case 0:
    break;
  case 1:
    job_queue_p->front = NULL;
    job_queue_p->end = NULL;
    job_queue_p->len = 0;
    break;
  default:
    job_queue_p->front = job_p->prev;
    job_queue_p->end--;
    bin_sem_post(job_queue_p->has_jobs);
    break;
  }
  pthread_mutex_unlock(&job_queue_p->rwmutex);
  return job_p;
}


/*  */
static int job_queue_destroy(job_queue* job_queue_p) {
  job_queue_clear(job_queue_p);
  free(job_queue_p->has_jobs);
}


/******************** SYNCHRONISATION ********************/


/*  */
static void bin_sem_init(bin_sem* bin_sem_p, int value) {
  if (value < 0 || value > 1) {
    perror("bin_sem_init(): Binary semaphore can take only values 1 or 0");
    exit(1);
  }
  pthread_mutex_init(&(bin_sem_p->mutex), NULL);
  pthread_cond_init(&(bin_sem_p->cond), NULL);
  bin_sem_p->value = value;
}


/*  */
static void bin_sem_reset(bin_sem* bin_sem_p) {
  bin_sem_init(bin_sem_p, 0);
}


/*  */
static void bin_sem_post(bin_sem* bin_sem_p) {
  pthread_mutex_lock(&bin_sem_p->mutex);
  bin_sem_p->value = 1;
  pthread_cond_signal(&bin_sem_p->cond);
  pthread_mutex_unlock(&bin_sem_p->mutex);
}


/*  */
static void bin_sem_post_all(bin_sem* bin_sem_p) {
  pthread_mutex_lock(&bin_sem_p->mutex);
  bin_sem_p->value =1;
  pthread_cond_broadcast(&bin_sem_p->cond);
  pthread_mutex_unlock(&bin_sem_p->mutex);
}


/*  */
static void bin_sem_wait(bin_sem* bin_sem_p) {
  pthread_mutex_lock(&bin_sem_p->mutex);
  while (bin_sem_p->value != 1)
    pthread_cond_wait(&bin_sem_p->cond, &bin_sem_p->mutex);
  bin_sem_p->value = 0;
  pthread_mutex_unlock(&bin_sem_p->mutex);

}


/******************** THREADPOOL ********************/


/*  */
thread_pool_p thread_pool_init(unsigned int num_threads) {
  g_threads_keep_alive = 1;
  g_threads_on_hold = 0;


  struct thread_pool_t* tp_p;
  tp_p = (struct thread_pool_t* ) malloc(sizeof(struct thread_pool_t));
  if (tp_p == NULL) {
    perror("thread_pool_init(): Could not allocate memory for thread pool");
    return NULL;
  }

  tp_p->num_threads_alive = 0;
  tp_p->num_threads_working = 0;

  if (job_queue_init(&tp_p->job_queue) == -1) {
    perror("thread_pool_init(): Could not allocate memory for job queue");
    free(tp_p);
    return NULL;
  }

  tp_p->threads = (struct thread** ) malloc(num_threads * sizeof(struct thread* ));
  if (tp_p->threads == NULL) {
    perror("thread_pool_init(): Could not allocate memory for threads");
    job_queue_destroy(&tp_p->job_queue);
    free(tp_p);
    return NULL;
  }

  pthread_mutex_init(&(tp_p->thread_count_lock), NULL);
  pthread_cond_init(&(tp_p->threads_all_idle), NULL);

  for (int n = 0; n < num_threads; ++n) {
    thread_init(tp_p, &tp_p->threads[n], n);
#if THREAD_POOL_DEBUG
    printf("THREAD_POOL_DEBUG: Created thread %d in thread pool.\n", n);
#endif
  }

  while (tp_p->num_threads_alive != num_threads);

  return tp_p;
}


/*  */
int thread_pool_add_work(thread_pool_p tp_p, void (* func)(void* ), void* arg_p) {
  job* new_job = (struct job* ) malloc(sizeof(struct job));
  if (new_job == NULL) {
    perror("thread_pool_add_work(): Could not allocate memory for new job");
    return -1;
  }
  new_job->func = func;
  new_job->arg = arg_p;
  job_queue_push(&tp_p->job_queue, new_job);
  return 0;
}


/*  */
void thread_pool_wait(thread_pool_p tp_p) {
  pthread_mutex_lock(&tp_p->thread_count_lock);
  while (tp_p->job_queue.len || tp_p->num_threads_working)
    pthread_cond_wait(&tp_p->threads_all_idle, &tp_p->thread_count_lock);
  pthread_mutex_unlock(&tp_p->thread_count_lock);
}


/*  */
void thread_pool_destroy(thread_pool_p tp_p) {
  if (tp_p == NULL)
    return ;
  volatile int threads_total = tp_p->num_threads_alive;
  g_threads_keep_alive = 0;
  double TIMEOUT = 1.0;
  time_t start, end;
  double tpassed = 0.0;
  time(&start);
  while (tpassed < TIMEOUT && tp_p->num_threads_alive) {
    bin_sem_post_all(tp_p->job_queue.has_jobs);
    time(&end);
    tpassed = difftime(end, start);
  }
  while (tp_p->num_threads_alive) {
    bin_sem_post_all(tp_p->job_queue.has_jobs);
    sleep(1);
  }
  job_queue_destroy(&tp_p->job_queue);
  for (int n = 0; n < threads_total; ++n)
    thread_destroy(tp_p->threads[n]);
  free(tp_p->threads);
  free(tp_p);
}


/*  */
void thread_pool_puse(thread_pool_p tp_p) {
  for (int n = 0; n < tp_p->num_threads_alive; ++n)
    pthread_kill(tp_p->threads[n]->pthread, SIGUSR1);
}


/*  */
void thread_pool_resume(thread_pool_p tp_p) {
  (void)tp_p;
  g_threads_on_hold = 0;
}


/*  */
unsigned int thread_pool_num_threads_working(thread_pool_p tp_p) {
  return tp_p->num_threads_working;
}

