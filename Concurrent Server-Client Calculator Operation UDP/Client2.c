#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include<sys/types.h>
#include <string.h>
#include <arpa/inet.h>
void main(){
        char buf[1024],msg[1024];
        int sd,port,len;
printf("==============================\n");
        printf("Enter the Port Number: \n");
        scanf("%d",&port);
printf("==============================\n");
        struct sockaddr_in server,client;
        server.sin_family=AF_INET;
        server.sin_port=htons(port);
        server.sin_addr.s_addr = INADDR_ANY;
        sd = socket(AF_INET,SOCK_DGRAM,0);
        if (sd<0){
                printf("Error in Socket Creation\n");
                exit(0);
        }
        printf("Socket Created Successfully\n");
printf("==============================\n");
                printf("Enter the Operator\n(+) -> ADD==== (-) -> SUB==== (*) -> MUL==== (/) -> DIV\n\n ENTER YOUR CHOICE: \n ");
                scanf("%s",msg);
printf("==============================\n");
	len = sizeof(server);
        sendto(sd,msg,sizeof(msg),0,(struct sockaddr*)&server,len);
	recvfrom(sd,msg,sizeof(msg),0,(struct sockaddr*)&server,&len);
	printf("The result is %s\n",msg);

printf("==============================\n");
        printf("Disconnected...\n");
}

