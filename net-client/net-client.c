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

int net_client_connect(net_client_t * this) {
	if (this == NULL) {
		return EXIT_FAILURE;
	}

	if (this->port > 65535) {
		return EXIT_FAILURE;
	}

	if (this->target == NULL) {
		return EXIT_FAILURE;
	}

	this->socket = socket(AF_INET, SOCK_STREAM, 0);
	if (this->socket == -1) {
		this->socket = 0;
		return -1;
	}

	struct sockaddr_in addr;

	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = this->port;
	addr.sin_addr.s_addr = this->in_addr;

	if (connect(this->socket, (struct sockaddr *) &addr , sizeof(addr)) == -1) {
		this->socket = 0;
		return -1;
	}

	return EXIT_SUCCESS;
}

int net_client_disconnect(net_client_t * this) {

	if (this == NULL) {
		return EXIT_FAILURE;
	}

	if (shutdown(this->socket, SHUT_RDWR) != 0) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

