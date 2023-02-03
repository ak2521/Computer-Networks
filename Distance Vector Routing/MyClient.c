#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include<sys/types.h>
#include <string.h>
#include <arpa/inet.h>
struct node
{
    unsigned dist[20];
    unsigned from[20];
}rt[10];
int main(){
    int socket_desc;
    struct sockaddr_in server_addr;
    printf("Enter port Number:");
    int port;
    scanf("%d",&port);
    printf("\n");
    int distance[20];
    int via[20];
    socklen_t server_struct_length = sizeof(server_addr);
    socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(socket_desc < 0){
        printf("Error while creating socket\n");
        return -1;
    }
    int x,y;
    printf("Socket created successfully\n");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    int node[2],i,j,k,req[2];
    
    printf("Enter Required Routing Table No:");
    scanf("%d",&req[0]);
    printf("\nRouting Table Required:%d\n",req[0]);
    if(sendto(socket_desc, req,sizeof(req), 0,(struct sockaddr*)&server_addr, server_struct_length) < 0){
        printf("Unable to send message\n");
        return -1;
    }
      if (recvfrom(socket_desc, distance, sizeof(distance), 0,
         (struct sockaddr*)&server_addr, &server_struct_length) < 0){
        printf("Couldn't receive\n");
        return -1;
    }
      if (recvfrom(socket_desc, via, sizeof(via), 0,
         (struct sockaddr*)&server_addr, &server_struct_length) < 0){
        printf("Couldn't receive\n");
        return -1;
    }
    if (recvfrom(socket_desc, node, sizeof(node), 0,
         (struct sockaddr*)&server_addr, &server_struct_length) < 0){
        printf("Couldn't receive\n");
        return -1;
    }
    int nodes=node[0];
    printf("\n\n For router %d\n",req[0]);
            for(j=0;j<nodes;j++)
            {
                printf("\t\nnode %d via %d Distance %d ",j+1,via[j],distance[j]);
            }
}

