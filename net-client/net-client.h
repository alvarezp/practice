#ifndef __NET_CLIENT_H
#define __NET_CLIENT_H

typedef struct net_client {
	char * target;
} net_client_t;

net_client_t * net_client_new(void);
void net_client_delete(net_client_t * this);

#endif
