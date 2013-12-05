#include "net-client.c"

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int connect(int socket, const struct sockaddr *address,
	socklen_t address_len)
{
	assert(socket != 0);
	assert(address != NULL);
	assert(address_len != 0);

	return EXIT_SUCCESS;
}

int shutdown(int socket, int how)
{
	assert(socket != 0);
	assert(how != 0);

	return EXIT_SUCCESS;
}


int main(void) {

	printf("Test #1: for a successful connect/disconnect...\n");
	net_client_t * client = NULL;
	assert(client == NULL);

	client = net_client_new();
	assert(client != NULL);

	assert(net_client_set_target(client, "127.0.0.1") == EXIT_SUCCESS);

	assert(net_client_set_port(client, 4000) == EXIT_SUCCESS);

	assert(net_client_connect(client) == EXIT_SUCCESS);

	assert(net_client_disconnect(client) == EXIT_SUCCESS);

	net_client_delete(client);

	printf("Test #2: Test for an improper target name...\n");
	client = net_client_new();
	assert(client != NULL);

	assert(net_client_set_target(client, "localhost") == EXIT_FAILURE);

	assert(net_client_set_port(client, 4000) == EXIT_SUCCESS);

	assert(net_client_connect(client) == EXIT_FAILURE);

	net_client_delete(client);

	return EXIT_SUCCESS;
}
