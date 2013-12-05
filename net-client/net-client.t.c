#include "net-client.c"

#include <stdlib.h>
#include <assert.h>

int connect(int socket, const struct sockaddr *address,
	socklen_t address_len)
{
	assert(socket != 0);
	assert(address != NULL);
	assert(address_len != 0);

	return EXIT_SUCCESS;
}

int main(void) {

	net_client_t * client = NULL;
	assert(client == NULL);

	client = net_client_new();
	assert(client != NULL);

	assert(net_client_set_target(client, "127.0.0.1") == EXIT_SUCCESS);

	assert(net_client_set_port(client, 4000) == EXIT_SUCCESS);

	assert(net_client_connect(client) == EXIT_SUCCESS);

	net_client_delete(client);

	return EXIT_SUCCESS;
}
