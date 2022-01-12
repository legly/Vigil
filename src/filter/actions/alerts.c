#include <stdio.h>
#include <stdlib.h>
#include "alerts.h"
#include "../../../globals.h"
#include "../../print_utils.h"
#include <time.h>
/*
  *-*-*-*- alerts.c -*-*-*-*
  @purpose Alert administrators of events
  @TODO: Add support for the following:
    - rsyslog
    - SNMP
    - Monitoring systems
    - Email
  
*/
void stdout_alert(const struct rule_data* __rule_data, const struct rule * __rule, int a_level){
  time_t t = time(NULL);
  struct tm __time = *localtime(&t);
  char time[64];
  sprintf(time,"%d-%02d-%02d %02d:%02d:%02d",
          __time.tm_year + 1900,
          __time.tm_mon + 1,
          __time.tm_mday,
          __time.tm_hour,
          __time.tm_min,
          __time.tm_sec);
  printf("%s at %s %s:%d -> %s:%d\n",__rule->message,
                            time,
														__rule_data->src_ip_addr,
														__rule_data->src_port,
														__rule_data->dest_ip_addr,
														__rule_data->dest_port);
//   ascii_hexdump(__rule_data->pkt,__rule_data->pkt_len);
  FILE * fp = fopen(def_log_file,"a");
  char logmsg[256];
  sprintf(logmsg,"%s at %s %s:%d -> %s:%d\n",__rule->message,
                            time,
														__rule_data->src_ip_addr,
														__rule_data->src_port,
														__rule_data->dest_ip_addr,
														__rule_data->dest_port);
  fputs(logmsg,fp);
  fclose(fp);



}
