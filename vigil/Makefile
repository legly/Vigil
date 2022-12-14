     
#  This file is part of Vigil.
#  Vigil is free software: you can redistribute it and/or modify it under the terms of the 
#  GNU General Public License as published by the Free Software Foundation, either version 3 
#  of the License, or (at your option) any later version.
#  
#	 Vigil is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
#  without  even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
#  
#	 See the GNU General Public License for more details.
#  You should have received a copy of the GNU General Public License along with Vigil. 
#  If not, see <https://www.gnu.org/licenses/>. 


CC = gcc
CFLAGS = -Wall
all: vigil clean

print_utils.o:
	$(CC) $(CFLAGS) -c print_utils.c 
globals.o:
	$(CC) $(CFLAGS) -c globals.c 
main.o:
	$(CC) $(CFLAGS) -c main.c 
tcp_chksum.o:
	$(CC) $(CFLAGS) -c engine/checksum/tcp_chksum.c

igmp_dsct.o:
	$(CC) $(CFLAGS) -c capture/protocols/igmp_dsct.c 
icmpdsct.o:
	$(CC) $(CFLAGS) -c capture/icmpdsct.c 
l2pktmgr.o:
	$(CC) $(CFLAGS) -c capture/l2pktmgr.c 
l3pktmgr.o:
	$(CC) $(CFLAGS) -c capture/l3pktmgr.c 
pktmgr.o:
	$(CC) $(CFLAGS) -c capture/pktmgr.c 
rule_parser.o:
	$(CC) $(CFLAGS) -c filter/parsing/rule_parser.c 
utils.o:
	$(CC) $(CFLAGS) -c utils.c 
tcpmgr.o:
	$(CC) $(CFLAGS) -c capture/tcpmgr.c 
udpmgr.o: 
	$(CC) $(CFLAGS) -c capture/udpmgr.c  

http_disect.o:
	$(CC) $(CFLAGS) -c capture/protocols/http_disect.c 
tls.o:
	$(CC) $(CFLAGS) -c capture/tls.c
dns_disect.o:
	$(CC) $(CFLAGS) -c capture/protocols/dns_disect.c 

alerts.o:
	$(CC) $(CFLAGS) -c filter/actions/alerts.c 

packet_parser.o:
	$(CC) $(CFLAGS) -c filter/parsing/packet_parser.c 
#rule_parser.o:
#	$(CC) $(CFLAGS) -c filter/parsing/rule_parser.c
rule.o:
	$(CC) $(CFLAGS) -c filter/parsing/rule.c 
# vrmc.o:
# 	$(CC) $(CFLAGS) -c vrmc/vrmc.c 


arpcache.o:
	$(CC) $(CFLAGS) -c statistics/arpcache.c 

update_db.o:
	$(CC) $(CFLAGS) -c database/update_db.c 

ftp-disect.o:
	$(CC) $(CFLAGS) -c capture/protocols/ftp-disect.c 
spi.o:
	$(CC) $(CFLAGS) -c engine/spi.c

debug.o:
	$(CC) $(CFLAGS) -c debug.c 

forward.o:
	$(CC) $(CFLAGS) -c engine/firewall/forward.c 

logging.o:
	$(CC) $(CFLAGS) -c logging.c 

line_parser.o:
	$(CC) $(CFLAGS) -c filter/parsing/line_parser.c 

rule_init.o:
	$(CC) $(CFLAGS) -c filter/parsing/rule_init.c 

dp_size.o:
	$(CC) $(CFLAGS) -c filter/parsing/dp_size.c 
homenet.o:
	$(CC) $(CFLAGS) -c filter/parsing/homenet.c 

lua_engine.o:
	$(CC) $(CFLAGS) -c lua/lua_engine.c
ip6decode.o:
	$(CC) $(CFLAGS) -c capture/ip6decode.c
backtrace.o:
	$(CC) $(CFLAGS) -c backtrace/backtrace.c
load_fn_map.o:
	$(CC) $(CFLAGS) -c backtrace/load_fn_map.c
# process_opcode.o:
# 	$(CC) $(CFLAGS) -c vrmc/process_opcode.c
pps_monitor.o:
	$(CC) $(CFLAGS) -c monitoring/pps_monitor.c
# handle_client.o:
# 	$(CC) $(CFLAGS) -c vrmc/handle_client.c
monitoring.o:
	$(CC) $(CFLAGS) -c monitoring/monitoring.c
# base64.o:
# 	$(CC) $(CFLAGS) -c vrmc/base64.c

netif.o:
	$(CC) $(CFLAGS) -c netif/netif.c
uptcp.o:
	$(CC) $(CFLAGS) -c engine/uptcp.c

vigil: globals.o pktmgr.o l2pktmgr.o utils.o l3pktmgr.o icmpdsct.o\
			tcpmgr.o udpmgr.o igmp_dsct.o print_utils.o\
			alerts.o packet_parser.o rule_parser.o rule.o main.o\
			arpcache.o tls.o \
			update_db.o http_disect.o dns_disect.o debug.o\
			forward.o spi.o logging.o line_parser.o rule_init.o dp_size.o \
			homenet.o tcp_chksum.o ip6decode.o backtrace.o \
			load_fn_map.o pps_monitor.o monitoring.o \
			netif.o uptcp.o lua_engine.o
	set environment MALLOC_CHECK_ 2
	$(CC) -g -o vigil.exe $^ -l pthread -l ssl -l crypto -l sqlite3  -l lua5.3

	objdump -D vigil.exe -M intel > objdump.txt
	python ../tools/gen_mem_map.py -f objdump.txt
	mv memmap.txt /usr/share/vigil/memmap.txt
	# rm objdump.txt 
	# strip vigil.exe

clean:
	rm *.o
