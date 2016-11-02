#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  void *addr = 0;

  addr = shmgetat(7, 3);
  printf(1, "Return address = %d, refcount = %d\n", (int) addr,
  shm_refcount(7));
  exit();
}
