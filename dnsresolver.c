#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main (int argc, char *argv[]) {

    printf("################################ \n");
    printf("#       DNS Resolver in C      # \n");
    printf("################################ \n");

    if(argc != 2)
	printf("How to use: %s <url>\n", argv[0]);
     else {
        struct hostent *target = gethostbyname(argv[1]);

        if (target == NULL)
            printf("An error has ocurred.\n");
        else
            printf("%s  -------->  %s", argv[1], inet_ntoa (*((struct in_addr *)target->h_addr))); 
    }
    return 0;
}
