#include <stdio.h>
#include <uk/blkdev.h>

int main() {
  printf("Hello Unikraft, with %d block devices!\n", uk_blkdev_count());
  fflush(stdout);
  return 0;
}
