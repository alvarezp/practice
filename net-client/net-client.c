#define _XOPEN_SOURCE
#define _XOPEN_SOURCE_EXTENDED

#include <stdlib.h>
#include <string.h>

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

	char *targetdup = strdup(target);
	if (targetdup == NULL) {
		return EXIT_FAILURE;
	}

	this->target = targetdup;
	return EXIT_SUCCESS;
}
