#include<stdio.h>
#include<sys/types.h>//socket
#include<sys/socket.h>//socket
#include<string.h>//memset
#include<stdlib.h>//sizeof
#include<netinet/in.h>//INADDR_ANY
#include<unistd.h>
#include<arpa/inet.h>
#define SERVER_IP "127.0.0.1"
#define MAXSZ 100
int main()
{
 int sockfd;//to create socket

 struct sockaddr_in serverAddress;//client will connect on this

 int n,PORT;
 int msg1[MAXSZ];
 char msg2[MAXSZ];
 printf("Enter port No:");
 scanf("%d",&PORT);
 printf("\n");
 //create socket
 sockfd=socket(AF_INET,SOCK_STREAM,0);
 //initialize the socket addresses
 memset(&serverAddress,0,sizeof(serverAddress));
 serverAddress.sin_family=AF_INET;
 serverAddress.sin_addr.s_addr=inet_addr(SERVER_IP);
 serverAddress.sin_port=htons(PORT);

 //client  connect to server on port
 connect(sockfd,(struct sockaddr *)&serverAddress,sizeof(serverAddress));
 //send to sever and receive from server

  recv(sockfd,msg1,sizeof(msg1),0);
printf("\nFrom Server:%d",msg1[0]);
 return 0;
}