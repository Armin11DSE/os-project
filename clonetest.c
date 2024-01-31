
// #define NULL          0

// void
// printf(int fd, const char *s, ...)
// {
//   write(fd, s, strlen(s));
// }

// int stack[4096] __attribute__ ((aligned (4096)));
// int main(int argc, char *argv[])
// {
//     printf(1, "Stack ", stack);
//     int tid = clone(stack, NULL, NULL, NULL);
//     if (tid < 0)
//     {
//         printf(2, "Error!\n");
//     }
//     else if (tid == 0)
//     {

//     }
//     else
//     {

//     }
//     exit();
// }


#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#define SLEEP_TIME 100

struct lock* lk;

void f1(void* arg1, void* arg2) {
  int num = *(int*)arg1;
  if (num) lock_acquire(lk);
  printf(1, "1. this should print %s\n", num ? "first" : "whenever");
  printf(1, "1. sleep for %d ticks\n", SLEEP_TIME);
  sleep(SLEEP_TIME);
  if (num) lock_release(lk);
  exit();
}

void f2(void* arg1, void* arg2) {
  int num = *(int*)arg1;
  if (num) lock_acquire(lk);
  printf(1, "2. this should print %s\n", num ? "second" : "whenever");
  printf(1, "2. sleep for %d ticks\n", SLEEP_TIME);
  sleep(SLEEP_TIME);
  if (num) lock_release(lk);
  exit();
}

void f3(void* arg1, void* arg2) {
  int num = *(int*)arg1;
  if (num) lock_acquire(lk);
  printf(1, "3. this should print %s\n", num ? "third" : "whenever");
  printf(1, "3. sleep for %d ticks\n", SLEEP_TIME);
  sleep(SLEEP_TIME);
  if (num) lock_release(lk);
  exit();
}

int
main(int argc, char *argv[])
{
  lock_init(lk);
  int arg1 = 1, arg2 = 1;

  printf(1, "below should be sequential print statements:\n");
  thread_create(&f1, (void *)&arg1, (void *)&arg2);
  thread_create(&f2, (void *)&arg1, (void *)&arg2);
  thread_create(&f3, (void *)&arg1, (void *)&arg2);
  thread_join();
  thread_join();
  thread_join();

  arg1 = 0;
  printf(1, "below should be a jarbled mess:\n");
  thread_create(&f1, (void *)&arg1, (void *)&arg2);
  thread_create(&f2, (void *)&arg1, (void *)&arg2);
  thread_create(&f3, (void *)&arg1, (void *)&arg2);
  thread_join();
  thread_join();
  thread_join();
  
  exit();
}