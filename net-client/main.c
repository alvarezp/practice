#include <stdio.h>
#include <stdlib.h>

#include "net-client.h"

int main(void) {

	net_client_t * client = NULL;

	client = net_client_new();
	if (client == NULL) {
		perror("net-client");
		return EXIT_FAILURE;
	}

	if(net_client_set_target(client, "127.0.0.1") != EXIT_SUCCESS) {
		perror("net-client");
		return EXIT_FAILURE;
	}

	if(net_client_set_port(client, 4000) != EXIT_SUCCESS) {
		perror("net-client");
		return EXIT_FAILURE;
	}

	if(net_client_connect(client) != EXIT_SUCCESS) {
		perror("net-client");
		return EXIT_FAILURE;
	}

	if(net_client_disconnect(client) != EXIT_SUCCESS) {
		perror("net-client");
		return EXIT_FAILURE;
	}

	net_client_delete(client);


	return EXIT_SUCCESS;
}
