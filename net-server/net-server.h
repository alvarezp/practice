#ifndef __NET_server_H
#define __NET_server_H

#include <arpa/inet.h>

typedef struct net_server {
	in_addr_t in_addr;
	int port;
	int socket;
} net_server_t;

net_server_t * net_server_new(void);
void net_server_delete(net_server_t * this);
int net_server_set_target(net_server_t * this, const char * target);
int net_server_set_port(net_server_t * this, unsigned int port);
int net_server_start(net_server_t * this);

#endif
