#include "types.h"
#include "lock.h"
#include "x86.h"

int 
lock_init(struct lock *lk)
{
  lk->locked = 0;
  return 0;
}

void 
lock_acquire(struct lock *lk)
{
  // Spin until the lock is acquired
  while (xchg(&lk->locked, 1) != 0)
    ;
}

void 
lock_release(struct lock *lk)
{
  xchg(&lk->locked, 0);
}
