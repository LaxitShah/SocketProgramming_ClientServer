#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 8094
int main(int argc, char **argv){

 

  char *ip = "127.0.0.1";
  int port = PORT;

  int sockfd;
  struct sockaddr_in addr;
  char buffer[1024],msg[20];
  socklen_t addr_size;

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  memset(&addr, '\0', sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = inet_addr(ip);
  int i=4;

    while(i--)
    {
       // printf("Message From Client: \n");
	  //  scanf("%[^\n]%*c", msg);
        
        bzero(buffer, 1024);
        printf("Enter your message: \n");
        scanf("%s",buffer);
        strcpy(buffer, buffer);
        
        sendto(sockfd, buffer, 1024, 0, (struct sockaddr*)&addr, sizeof(addr));

        bzero(buffer, 1024);

        addr_size = sizeof(addr);
        recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr*)&addr, &addr_size);
        //printf("[+]Data recv: %s\n", buffer);
        printf("Server Message Sent: %s\n", buffer);

    }
  return 0;
}