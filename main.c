#include <stddef.h>
#include <signal.h>

_Static_assert(sizeof(sigset_t) == 128);
_Static_assert(offsetof(struct sigaction, sa_mask) == 8);
_Static_assert(sizeof(((struct sigaction*)0)->sa_mask) == 128);
_Static_assert(offsetof(struct sigaction, sa_flags) == 136);
_Static_assert(sizeof(((struct sigaction*)0)->sa_flags) == 4);
_Static_assert(offsetof(struct sigaction, sa_restorer) == 144);
_Static_assert(sizeof(((struct sigaction*)0)->sa_restorer) == 8);
_Static_assert(sizeof(struct sigaction) == 152);

int main() {
  return 0;
}
