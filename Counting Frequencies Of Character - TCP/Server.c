#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){
 
  char *ip = "127.0.0.1";
  int port;
  char msg[100];
  int server_sock, client_sock;
  struct sockaddr_in server_addr, client_addr;
  socklen_t addr_size;
  char buffer[1024];
  int i,j,n,l=0;
     char s[1024],result[1024]={'\0'};
    int count=0,temp=0;
 printf("Enter The Port Number:");
    scanf("%d",&port);
  server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0){
    perror("[-]Socket error");
    exit(1);
  }
  printf("[+]TCP server socket created.\n");
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = port;
  server_addr.sin_addr.s_addr = inet_addr(ip);
 bzero(buffer,1024);
  n = bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
  if (n < 0){
    perror("[-]Bind error");
    exit(1);
  }
  printf("[+]Bind to the port number: %d\n", port);
 
  listen(server_sock, 5);
  printf("Listening...\n");
  while(1){
      l=0;
    addr_size = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_size);
    printf("[+]Client connected.\n");
    bzero(buffer, 1024);
      
    recv(client_sock, buffer, sizeof(buffer), 0);
    printf("Client: %s\n", buffer);
    for(j=0;buffer[j];j++);
	 n=j; 
    
	printf(" frequency count character in string:\n");
    for(i=0;i<n;i++)  
    {
     	count=1;
    	if(buffer[i])
    	{
		
 		  for(j=i+1;j<n;j++)  
	      {   
	    	
	        if(buffer[i]==buffer[j])
    	    {
                 count++;
                 buffer[j]='\0';
	     	}
              
	      }
	      result[l]=buffer[i];
        
        result[l+1]=count;
        l=l+2;
	      printf(" '%c' = %d \n",buffer[i],count);
       }	   
 	} printf("\n Counted:\n");
     for(int p=0;p<l-2;p=p+2){
 	       printf("%c%d",result[p],(int)result[p+1]);   
 	 }
      int len,temp;
      len=strlen(result);
          for (i = 0; i < len/2; i++)  
    {   
        temp = result[i];  
        result[i] = result[len - i - 1];  
        result[len - i - 1] = temp;  
    } 
      
 printf("\n Server:\n");
 for(int p=0;p<l-1;p=p+2){
 	       printf("%X%c",result[p],result[p+1]);                  }
    bzero(buffer, 1024);
      strcpy(buffer,result);
    send(client_sock,buffer, strlen(buffer), 0);
    close(client_sock);
    printf("\n[+]Client disconnected.\n\n");
  }
  return 0;
}

