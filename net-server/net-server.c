#define _XOPEN_SOURCE
#define _XOPEN_SOURCE_EXTENDED

#include <stdlib.h>
#include <string.h>

#include <netinet/in.h>

#include "net-server.h"

net_server_t * net_server_new(void) {
	net_server_t * this = malloc(sizeof(net_server_t));
	if (this == NULL) {
		return NULL;
	}
	this->in_addr = inet_addr("127.0.0.1");
	return this;
}

void net_server_delete(net_server_t * this) {
	if (this == NULL) {
		return;
	}
	free(this);
}

int net_server_set_port(net_server_t * this, unsigned int port) {
	if (this == NULL) {
		return EXIT_FAILURE;
	}

	if (port > 65535) {
		return EXIT_FAILURE;
	}

	this->port = port;

	return EXIT_SUCCESS;
}

int net_server_start(net_server_t * this) {
	if (this == NULL) {
		return EXIT_FAILURE;
	}

	if (this->port > 65535) {
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
	addr.sin_port = htons(this->port);
	addr.sin_addr.s_addr = this->in_addr;

	if (bind(this->socket, (struct sockaddr *) &addr , sizeof(addr)) == -1) {
		this->socket = 0;
		return -1;
	}

	return EXIT_SUCCESS;
}

