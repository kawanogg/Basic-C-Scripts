#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>

int main (int argc, char *argv[]) {

        printf("################################ \n");
        printf("#         PortScan in C        # \n");
        printf("################################ \n");

	if (argc != 2)
		printf("How to use: %s <target ip addr>", argv[0]);
	else {

		int sckt;
		int cnnct;
		char *trgt_ip = argv[1];
		struct sockaddr_in target;

		for(int port = 0; port <= 443; port++) {

			sckt = socket(AF_INET, SOCK_STREAM, 0);
        		target.sin_family = AF_INET;
       			target.sin_port = htons(port);
	        	target.sin_addr.s_addr = inet_addr(trgt_ip);

        		cnnct = connect (sckt, (struct sockaddr *) &target, sizeof target);

			if (cnnct == 0) {
				printf("Port %d: OPEN", port);
				close(sckt);
				close(cnnct);
			} else
				close(sckt);
				close(cnnct);
		}
	}
	return 0;
}
