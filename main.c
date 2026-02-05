#include <stddef.h>
#include <sys/socket.h>

_Static_assert(sizeof(socklen_t) == 4);
_Static_assert(sizeof(sa_family_t) == 2);
_Static_assert(offsetof(struct sockaddr, sa_family) == 0);
_Static_assert(sizeof(((struct sockaddr*)0)->sa_family) == 2);
_Static_assert(offsetof(struct sockaddr, sa_data) == 2);
_Static_assert(sizeof(((struct sockaddr*)0)->sa_data) == 14);
_Static_assert(sizeof(struct sockaddr) == 16);
_Static_assert(offsetof(struct sockaddr_storage, ss_family) == 0);
_Static_assert(sizeof(((struct sockaddr_storage*)0)->ss_family) == 2);
_Static_assert(sizeof(struct sockaddr_storage) == 128);
_Static_assert(offsetof(struct msghdr, msg_name) == 0);
_Static_assert(sizeof(((struct msghdr*)0)->msg_name) == 8);
_Static_assert(offsetof(struct msghdr, msg_namelen) == 8);
_Static_assert(sizeof(((struct msghdr*)0)->msg_namelen) == 4);
_Static_assert(offsetof(struct msghdr, msg_iov) == 16);
_Static_assert(sizeof(((struct msghdr*)0)->msg_iov) == 8);
_Static_assert(offsetof(struct msghdr, msg_iovlen) == 24);
_Static_assert(sizeof(((struct msghdr*)0)->msg_iovlen) == 8);
_Static_assert(offsetof(struct msghdr, msg_control) == 32);
_Static_assert(sizeof(((struct msghdr*)0)->msg_control) == 8);
_Static_assert(offsetof(struct msghdr, msg_controllen) == 40);
_Static_assert(sizeof(((struct msghdr*)0)->msg_controllen) == 8);
_Static_assert(offsetof(struct msghdr, msg_flags) == 48);
_Static_assert(sizeof(((struct msghdr*)0)->msg_flags) == 4);
_Static_assert(sizeof(struct msghdr) == 56);
_Static_assert(offsetof(struct cmsghdr, cmsg_len) == 0);
_Static_assert(sizeof(((struct cmsghdr*)0)->cmsg_len) == 8);
_Static_assert(offsetof(struct cmsghdr, cmsg_level) == 8);
_Static_assert(sizeof(((struct cmsghdr*)0)->cmsg_level) == 4);
_Static_assert(offsetof(struct cmsghdr, cmsg_type) == 12);
_Static_assert(sizeof(((struct cmsghdr*)0)->cmsg_type) == 4);
_Static_assert(sizeof(struct cmsghdr) == 16);
_Static_assert(offsetof(struct linger, l_onoff) == 0);
_Static_assert(sizeof(((struct linger*)0)->l_onoff) == 4);
_Static_assert(offsetof(struct linger, l_linger) == 4);
_Static_assert(sizeof(((struct linger*)0)->l_linger) == 4);
_Static_assert(sizeof(struct linger) == 8);
_Static_assert(offsetof(struct osockaddr, sa_family) == 0);
_Static_assert(sizeof(((struct osockaddr*)0)->sa_family) == 2);
_Static_assert(offsetof(struct osockaddr, sa_data) == 2);
_Static_assert(sizeof(((struct osockaddr*)0)->sa_data) == 14);
_Static_assert(sizeof(struct osockaddr) == 16);

int main() {
  return 0;
}
