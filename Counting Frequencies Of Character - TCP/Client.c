#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
 
int main(){
 
  char *ip = "127.0.0.1";
  int port;
    printf("Enter The Port Number:");
    scanf("%d",&port);
  char msg[100];
  int sock;
  struct sockaddr_in addr;
  socklen_t addr_size;
  char buffer[1024];
  int n;
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0){
    perror("[-]Socket error");
    exit(1);
  }
  printf("[+]TCP server socket created.\n");
  addr.sin_family = AF_INET;
  addr.sin_port = port;
  addr.sin_addr.s_addr = inet_addr(ip);
  connect(sock, (struct sockaddr*)&addr, sizeof(addr));
  printf("Connected to the server.\n");
  bzero(buffer, 1024);
    printf("Enter String:");
    scanf("%s",msg);
  strcpy(buffer,msg);
  printf("Client: %s\n", buffer);
  send(sock, buffer, strlen(buffer), 0);
  bzero(buffer, 1024);
  recv(sock, buffer, sizeof(buffer), 0);
int l=strlen(buffer);
  printf("\n Message From Server:");  
  for(int p=0;p<l-1;p=p+2)
  {
 	       printf("%X%c",(int)buffer[p],buffer[p+1]);   
  }  
   bzero(buffer, 1024); 
  close(sock);
  printf("\nDisconnected from the server.\n");
 
  return 0;
}
