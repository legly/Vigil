#ifndef NET_IF_H
#define NET_IF_H
#include <pthread.h>
#include <stdbool.h>



typedef struct{
  char if_name[17];
  // pthread_t * thrd_id;
  unsigned long thrd_id;
  bool active;
  unsigned int a_family;
  char address[100];
  int fd;
  // unsigned int function;
} v_netif;

extern v_netif * net_interfaces;
extern int iface_detected;
void start_interface_cap(const char *);
void start_interface_cap_ex(void * );
void detect_interfaces();
void free_iface();
int iface_exists(const char *);

#endif /* NET_IF_H */