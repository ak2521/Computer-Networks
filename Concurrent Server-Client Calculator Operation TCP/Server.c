#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#define MAXSZ 100
char msg[MAXSZ],msg1[MAXSZ],msg2[MAXSZ],ms[1024];
int main()
{
 int sockfd;
 int newsockfd;
 struct sockaddr_in serverAddress;
 struct sockaddr_in clientAddress;
 int n;
 int PORT;
 int buffer[MAXSZ];
 socklen_t clientAddressLength;
 int pid;
 printf("Enter port No:");
 scanf("%d",&PORT);
 printf("\n");
 sockfd=socket(AF_INET,SOCK_STREAM,0);
 printf("[+]TCP server socket created.\n");
 memset(&serverAddress,0,sizeof(serverAddress));
 serverAddress.sin_family=AF_INET;
 serverAddress.sin_addr.s_addr=htonl(INADDR_ANY);
 serverAddress.sin_port=htons(PORT);
 bind(sockfd,(struct sockaddr *)&serverAddress, sizeof(serverAddress));
 printf("[+]Bind to the port number: %d\n", PORT);
 listen(sockfd,5);
 printf("Listening...\n");
 while(1)
 {
  int i=0;
  clientAddressLength=sizeof(clientAddress);
  newsockfd=accept(sockfd,(struct sockaddr*)&clientAddress,&clientAddressLength);
  printf("connected to client: %s\n",inet_ntoa(clientAddress.sin_addr));
  pid=fork();
  if(pid==0)
  {
   
   while(1)
   {
    if(n==1)
    {
     recv(newsockfd,msg,MAXSZ,0);
     strcpy(ms,msg);
     printf("\nClient1\n");
     printf("Message :%s\n",msg);
     printf("Message 2 :%s\n",ms);
     FILE *fptr;
     fptr = fopen("msg1.txt", "w");
     if(fptr == NULL) 
     {
     printf("file can't be opened\n");
     exit(1);
     }
     fprintf(fptr,"%s",&msg[0]);
     close(newsockfd);
     break;
    }
    if(n==2)
    {recv(newsockfd,msg,MAXSZ,0);
     printf("\nClient2\n");
     printf("Message :%s\n",msg);
     printf("Message 2 :%s\n",ms);
     FILE *fptr;
     fptr = fopen("msg2.txt", "w");
     if(fptr == NULL) {
     printf("file can't be opened\n");
     exit(1);
     }
     fprintf(fptr,"%s",msg);
     close(newsockfd);
     break;
    }
     if(n==3)
    {
     recv(newsockfd,msg,MAXSZ,0);
     printf("\nClient3\n");
     printf("Message :%s\n",msg);
     FILE *fptr;
     fptr = fopen("msg3.txt", "w");
     if(fptr == NULL) {
     printf("file can't be opened\n");
     exit(1);
     }
     fprintf(fptr,"%s",msg);
     close(newsockfd);
     break;
    }
    if(n==4)
    {
      FILE *ptr1,*ptr2,*ptr3;
      char f1[10],f2,f3[10];
      int x,y,op=0;
      ptr1=fopen("msg1.txt","r");
      ptr2=fopen("msg2.txt","r");
      ptr3=fopen("msg3.txt","r");
        if(ptr1==NULL && ptr2==NULL && ptr3==NULL)
        {
            printf("\nFile Cannot Opened\n");
            exit(0);
        }
        fgets(f1,10,ptr1);
        f2=fgetc(ptr2);
        fgets(f3,10,ptr3);
        x=atoi(f1);
        y=atoi(f3);
        printf("\nNumber 1 :%d\n",x);
        printf("\nOperator :%c\n",f2);
        printf("\nNumber 2  :%d\n",y);
        if(f2=='+')
        {
            op=x+y;
        }
       else if(f2=='-')
        {
            op=x-y;
        }
       else if(f2=='/')
        {
            op=x/y;
        }
       else if(f2=='*')
        {
            op=x*y;
        }
       else if(f2=='%')
        {
            op=x%y;
        }
       
        printf("\nComputation:%d\n",op);
        buffer[0]=op;
        printf("\n[+] Message Sent To Client 4 :%d\n",buffer[0]);
        send(newsockfd,buffer,MAXSZ,0);
       fclose(fopen("msg1.txt", "w")); 
       fclose(fopen("msg2.txt", "w"));
       fclose(fopen("msg3.txt", "w"));
       close(newsockfd);
       break;
    }    
   }      
  exit(0);      
  }  
  else
  {
   close(newsockfd);
  }     
     n++;
     i++;
     if(n>4)
     {
         n=1;
     }
 }
  return 0;
}