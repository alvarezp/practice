#ifndef __NET_CLIENT_H
#define __NET_CLIENT_H

typedef struct net_client {
	char * target;
	int port;
} net_client_t;

net_client_t * net_client_new(void);
void net_client_delete(net_client_t * this);
int net_client_set_target(net_client_t * this, const char * target);
int net_client_set_port(net_client_t * this, unsigned int port);

#endif
