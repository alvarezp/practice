#ifndef __NET_CLIENT_H
#define __NET_CLIENT_H

#include <arpa/inet.h>

typedef struct net_client {
	char * target;
	in_addr_t in_addr;
	int port;
	int socket;
} net_client_t;

net_client_t * net_client_new(void);
void net_client_delete(net_client_t * this);
int net_client_set_target(net_client_t * this, const char * target);
int net_client_set_port(net_client_t * this, unsigned int port);
int net_client_connect(net_client_t * this);
int net_client_disconnect(net_client_t * this);

#endif
