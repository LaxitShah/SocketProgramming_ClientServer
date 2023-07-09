#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8094
int main(int argc, char **argv){

char str[100];
  char *ip = "127.0.0.1";
  int port = PORT;

  int sockfd;
  struct sockaddr_in server_addr, client_addr;
  char buffer[1024];
  socklen_t addr_size;
  int n;

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0){
    perror("[-]socket error");
    exit(1);
  }

    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    n = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (n < 0) {
        perror("[-]bind error");
        exit(1);
    }
    int i=4;
    while(i--)
    {
        bzero(buffer, 1024);
        addr_size = sizeof(client_addr);
        recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr*)&client_addr, &addr_size);
        printf("Client Message sent: %s\n", buffer);
        
        bzero(buffer, 1024);
        printf("Enter your message: \n");
        scanf("%s",buffer);
        strcpy(buffer,buffer );
        sendto(sockfd, buffer, 1024, 0, (struct sockaddr*)&client_addr, sizeof(client_addr));
       // printf("[+]Data send: %s\n", buffer);
    }
  return 0;
}