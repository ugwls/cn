#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

#include<math.h>
#include<complex.h>
#include<stdlib.h>
#include<netinet/if_ether.h>
#include<net/ethernet.h>

int main()
{
int sd;
char *ptr;
char ip[20];

struct sockaddr_in sin = {0};
struct arpreq myarp = {{0}};

sin.sin_family=AF_INET;

printf("Enter the IP address: ");
scanf("%s",ip);

memcpy(&myarp.arp_pa, &sin, sizeof(myarp.arp_pa));
strcpy(myarp.arp_dev, "echo");

printf("ARP request sent.");

ptr = &myarp.arp_pa.sa_data[0];

printf("Received ARP Reply\n");
printf("\nMAC Address for '%s' : ", ip);
printf("%p:%p:%p:%p:%p:%p\n",ptr, (ptr + 1), (ptr + 2), (ptr + 3), (ptr + 4), (ptr + 5));
return 0;

}
