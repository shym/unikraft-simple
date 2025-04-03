#include <pthread.h>
#include <assert.h>

int main() {
  pthread_mutex_t m;
  pthread_mutexattr_t attr;

  pthread_mutexattr_init(&attr);
  pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
  pthread_mutex_init(&m, &attr);
  pthread_mutexattr_destroy(&attr);

  pthread_mutex_lock(&m);
  assert(0); // ^ Previous line triggered a segfault

  return 0;
}
