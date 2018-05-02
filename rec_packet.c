#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define EXAMPLE_PORT 2333
#define EXAMPLE_GROUP "226.5.1.32"

int main(int argc)
{
    struct __attribute__((packed)) sendbuf_t{
        uint32_t header;
        uint8_t dev_no;
        uint16_t sensor_no;
        uint16_t length_event;
        uint32_t ccount_struc;
    } sendbuf;

   struct sockaddr_in addr;
   int sock, cnt;
   socklen_t addrlen;
   struct ip_mreq mreq;
   // char message[50];

   /* set up socket */
   sock = socket(AF_INET, SOCK_DGRAM, 0);

   if (sock < 0) {
     perror("socket");
     exit(1);
   }
   bzero((char *)&addr, sizeof(addr));
   addr.sin_family = AF_INET;
   addr.sin_addr.s_addr = htonl(INADDR_ANY);
   addr.sin_port = htons(EXAMPLE_PORT);
   addrlen = sizeof(addr);

    if (bind(sock, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
          perror("bind");
	        exit(1);
      }
      mreq.imr_multiaddr.s_addr = inet_addr(EXAMPLE_GROUP);
      mreq.imr_interface.s_addr = htonl(INADDR_ANY);
    if (setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq)) < 0) {
	       perror("setsockopt mreq");
	       exit(1);
      }
    while (1) {
 	    cnt = recvfrom(sock, (char *) &sendbuf, sizeof(sendbuf), MSG_DONTWAIT | MSG_NOSIGNAL ,	(struct sockaddr *) &addr, &addrlen);
	     if (cnt < 0) {
	        // perror("recvfrom");
	        //  exit(1);
          continue;
	        } else if (cnt == 0) {
            continue;
 	          // break;
	        }
	     printf("On %s: Header - %s | Device_Number - %d | Sensor_no - %d | Event_length - %5d | Ccount - %u \n", inet_ntoa(addr.sin_addr), (char *) &sendbuf.header, sendbuf.dev_no, sendbuf.sensor_no, sendbuf.length_event, sendbuf.ccount_struc);
    }
}
