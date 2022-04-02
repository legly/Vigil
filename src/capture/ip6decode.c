#include "ip6decode.h"
#include "../packets/ip6hdr.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/ether.h>
#include "icmpdsct.h"
#include <arpa/inet.h>
#include "../utils.h"

void ip6decode(const unsigned char * pkt,const  struct pcap_pkthdr * pkt_hdr){
  struct ip6hdr * ipv6_hdr = (struct ip6hdr *)(pkt + sizeof(struct ethhdr) );
  char dest_ip6[41];

  char src_ip6[41];
  strncpy(src_ip6,inet6_ntoa(ipv6_hdr->srcaddr),sizeof(src_ip6));
  strncpy(dest_ip6,inet6_ntoa(ipv6_hdr->dstaddr),sizeof(dest_ip6));
  // printf("IPv6 ");
  // printf("src=%p dst=%p",ipv6_hdr->srcaddr,ipv6_hdr->dstaddr);
  // printf("src=%s dst=%s\n", 
                      // src_ip6,dest_ip6);
  switch(ipv6_hdr->n_hdr){
    case 0:{
      ip6_icmp_decode(pkt,src_ip6,dest_ip6);
      break;
    }
    default:
      printf("IPv6 %s -> %s Protocol Number = %d\n",src_ip6,dest_ip6,ipv6_hdr->n_hdr);
      break;
  }
}