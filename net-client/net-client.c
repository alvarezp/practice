#define _XOPEN_SOURCE
#define _XOPEN_SOURCE_EXTENDED

#include <stdlib.h>
#include <string.h>

#include <netinet/in.h>

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

int net_client_set_target(net_client_t * this, const char * target) {
	if (this == NULL) {
		return EXIT_FAILURE;;
	}

	in_addr_t in_addr;
	in_addr = inet_addr(target);

	if (in_addr == (in_addr_t)(-1)) {
		return EXIT_FAILURE;
	}

	this->in_addr = in_addr;

	char *targetdup = strdup(target);
	if (targetdup == NULL) {
		return EXIT_FAILURE;
	}

	this->target = targetdup;
	return EXIT_SUCCESS;
}

int net_client_set_port(net_client_t * this, unsigned int port) {
	if (this == NULL) {
		return EXIT_FAILURE;
	}

	if (port > 65535) {
		return EXIT_FAILURE;
	}

	this->port = port;

	return EXIT_SUCCESS;
}


