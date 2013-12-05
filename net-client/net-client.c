#include <stdlib.h>

#include "net-client.h"

net_client_t * net_client_new(void) {
	net_client_t * this = malloc(sizeof(net_client_t));
	if (this == NULL) {
		return NULL;
	}
	this->target = NULL;
	return this;
}

void net_client_delete(net_client_t * this) {
	if (this == NULL) {
		return;
	}
	free(this->target);
	free(this);
}


