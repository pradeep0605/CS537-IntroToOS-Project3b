#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  void *addr = 0;
  addr = shmgetat(2, 1);
  int *b = (int *) addr;
  *b = 06;
  printf(1, "pid = %d  addr = %p *b = %d refcount = %d \n",
    getpid(), addr, *b, shm_refcount(2));
  
  addr = shmgetat(1, 1);
  int *a = (int *) addr;
  *a = 05;
  printf(1, "pid = %d  addr = %p *a = %d refcount = %d\n",
    getpid(), addr, *a, shm_refcount(1));

  if (fork() == 0) {
    printf(1, "\nIn Child !\n");
    printf(1, "pid = %d  addr = %p *b = %d refcount = %d \n",
      getpid(), b, *b, shm_refcount(2));
    printf(1, "pid = %d  addr = %p *a = %d refcount = %d\n",
      getpid(), a, *a, shm_refcount(1));
      exit();
  } else {
    printf(1, "Parent ! Sleeping for 3 seconds\n");
    sleep(30);
  }
  exit();
}
