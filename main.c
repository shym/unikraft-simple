#include <pthread.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>

void *thrd(void * _placeholder) {
  return NULL;
}

int main() {
  pthread_key_t key;
  pthread_t th;
  int *value;

  value = malloc(sizeof(int));
  assert(value != NULL);

  assert(pthread_key_create(&key, NULL) == 0);
  assert(pthread_setspecific(key, value) == 0);
  assert(pthread_getspecific(key) == value);
  assert(pthread_create(&th, NULL, &thrd, NULL) == 0);
  assert(pthread_getspecific(key) == value);
  assert(pthread_join(th, NULL) == 0);
  assert(pthread_getspecific(key) == value);

  return 0;
}
