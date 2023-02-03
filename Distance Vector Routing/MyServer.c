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
    struct sockaddr_in server_addr, client_addr;
    int costmat[20][20],req[2];
    int nodes,node[2],i,j,k,count=0;
    
    socklen_t client_struct_length = sizeof(client_addr);
    int port;
    printf("Enter Port No:");
    scanf("%d",&port);
    while(1)
    { 
    socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); 
    if(socket_desc < 0){
        printf("Error while creating socket\n");
        return -1;
    }
    printf("\nSocket created successfully\n");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if(bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        printf("Couldn't bind to the port\n");
        return -1;
    }
    printf("\nDone with binding\n");
    printf("\nListening for incoming messages...\n"); 
        
    recvfrom(socket_desc,req, sizeof(req), 0,
         (struct sockaddr*)&client_addr, &client_struct_length);
    printf("\nReceived message from IP: %s and port: %i\n",
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        printf("\nRequired Table: %d \n",req[0]);
        printf("\nEnter the number of nodes : ");
    scanf("%d",&node[0]);
        nodes=node[0];
    int distance[nodes];
    int via[nodes];
        printf("\nEnter the cost matrix :\n");
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            scanf("%d",&costmat[i][j]);
        }
    }
        printf("\nCost Matrix\n");
        int rq=req[0];
        
         for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<nodes;j++)
        {
            printf("%d ",costmat[i][j]);
        }
        printf("\n");
    }
        
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            costmat[i][i]=0;
            rt[i].dist[j]=costmat[i][j];
            rt[i].from[j]=j;
        }
    }
              do
        {
            count=0;
            for(i=0;i<nodes;i++)
            for(j=0;j<nodes;j++)
            for(k=0;k<nodes;k++)
                if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
                {
                    rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                    rt[i].from[j]=k;
                    count++;
                }
        }while(count!=0);
        for(i=rq-1;i<rq;i++)
        {
            printf("\n\n For router %d\n",i+1);
            for(j=0;j<nodes;j++)
            {
                printf("\t\nnode %d via %d Distance %d ",j+1,rt[i].from[j]+1,rt[i].dist[j]);
                distance[j]=rt[i].dist[j];
                via[j]=rt[i].from[j]+1;
            }
        }
    printf("\n\n");      
    sendto(socket_desc,distance, sizeof(distance), 0,
         (struct sockaddr*)&client_addr, client_struct_length);
     sendto(socket_desc,via, sizeof(via), 0,
         (struct sockaddr*)&client_addr, client_struct_length);
        sendto(socket_desc,node, sizeof(node), 0,
         (struct sockaddr*)&client_addr, client_struct_length);
    close(socket_desc);   
    }
    return 0;
}
