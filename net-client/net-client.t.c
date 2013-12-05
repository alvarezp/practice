#include "net-client.c"

#include <stdlib.h>
#include <assert.h>

int main(void) {

	net_client_t * client = NULL;
	assert(client == NULL);

	client = net_client_new();
	assert(client != NULL);

	assert(net_client_set_target(client, "127.0.0.1") == EXIT_SUCCESS);

	assert(net_client_set_port(client, 4000) == EXIT_SUCCESS);

	net_client_delete(client);

	return EXIT_SUCCESS;
}
