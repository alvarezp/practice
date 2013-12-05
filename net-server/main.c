#include <stdio.h>
#include <stdlib.h>

#include "net-server.h"

int main(void) {

	net_server_t * server = NULL;

	server = net_server_new();
	if (server == NULL) {
		perror("net-server");
		return EXIT_FAILURE;
	}

	if(net_server_set_target(server, "127.0.0.1") != EXIT_SUCCESS) {
		perror("net-server");
		return EXIT_FAILURE;
	}

	if(net_server_set_port(server, 4000) != EXIT_SUCCESS) {
		perror("net-server");
		return EXIT_FAILURE;
	}

/*
	if(net_server_start(server) != EXIT_SUCCESS) {
		perror("net-server");
		return EXIT_FAILURE;
	}
*/

	net_server_delete(server);


	return EXIT_SUCCESS;
}
