#include <stdio.h>
#include <pthread.h>
#include <assert.h>

int main() {
  pthread_mutex_t m;
  pthread_mutexattr_t attr;
  int r;

  printf("Hello Unikraft\n");
  fflush(stdout);

  r = pthread_mutexattr_init(&attr);
  assert(r == 0);
  r = pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
  assert(r == 0);
  r = pthread_mutex_init(&m, &attr);
  assert(r == 0);
  pthread_mutexattr_destroy(&attr);

  r = pthread_mutex_lock(&m);
  assert(r == 0);

  printf("With mutex!\n");
  fflush(stdout);

  r = pthread_mutex_unlock(&m);
  assert(r == 0);

  printf("Without mutex!\n");
  fflush(stdout);

  return 0;
}
