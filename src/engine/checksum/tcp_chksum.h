#ifndef TCP_CHKSUM_H
#define TCP_CHKSUM_H
#include "../../packets/tcp.h"


bool tcp_check_sum_passed(struct __tcp *, int);


#endif /* TCP_CHKSUM_H */