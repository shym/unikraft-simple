#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>

/* Position of the TSD field in the pthread_t struct */
#define TSD_OFFSET 0x80

#define DEBUG_TSD(prefix) do {                        \
    void *tmp, *tmp2;                                 \
    tmp = (void*)pthread_self();                      \
    tmp2 = tmp + TSD_OFFSET;                          \
    printf("%s: pthread_t: %p, TSD: %p, TSD[0]=%p\n", \
      prefix, tmp, *(void**)tmp2, **(void***)tmp2);   \
  } while(0)

pthread_key_t key;

void log_value(char *prefix, void *value) {
  if (value) {
    printf("%s: set the value\n", prefix);
    assert(pthread_setspecific(key, value) == 0);
  }
  printf("%s: current value: %p\n", prefix, pthread_getspecific(key));
  DEBUG_TSD(prefix);
}

void *thrd_main(void * prefix) {
  int *t_value = NULL;
  log_value(prefix, t_value);
  t_value = malloc(sizeof(int));
  log_value(prefix, t_value);
  return NULL;
}

int main() {
  pthread_t th;

  DEBUG_TSD("main");
  printf("main: create a key\n");
  assert(pthread_key_create(&key, NULL) == 0);

  thrd_main("main");
  printf("main: create a thread\n");
  assert(pthread_create(&th, NULL, &thrd_main, "thread") == 0);
  log_value("main", NULL);
  printf("main: join the thread\n");
  assert(pthread_join(th, NULL) == 0);
  log_value("main", NULL);

  fflush(stdout);

  return 0;
}
