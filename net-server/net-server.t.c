#include "net-server.c"

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int connect(int socket, const struct sockaddr *address,
	socklen_t address_len)
{

	union {
		const struct sockaddr_in * sockaddr_in;
		const struct sockaddr * sockaddr;
	} usock;

	usock.sockaddr = address;

	assert(socket != 0);
	assert(address != NULL);
	assert(address_len != 0);
	assert(ntohs(usock.sockaddr_in->sin_port) == 4000);

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
	net_server_t * server = NULL;
	assert(server == NULL);

	server = net_server_new();
	assert(server != NULL);

	assert(net_server_set_port(server, 4000) == EXIT_SUCCESS);

	assert(net_server_start(server) == EXIT_SUCCESS);

	net_server_delete(server);

	return EXIT_SUCCESS;
}
