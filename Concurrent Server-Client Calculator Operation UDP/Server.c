#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
struct sockaddr_in server,client1,client2,client3;
void process(int);
int main()
{
 int i,f=0,sd,b,pid,h;
char s2[100],s1[40];
sd=socket(AF_INET,SOCK_DGRAM,0);
server.sin_family=AF_INET;
printf("==============================\n");
printf("enter the port number:");
scanf("%d",&h);
printf("==============================\n");
server.sin_port=htons(h);
int cc=0;
server.sin_addr.s_addr=htonl(INADDR_ANY);
b=bind(sd,(struct sockaddr*)&server,sizeof(server));
if(b==0)
printf("\nbinding successful");
else
printf("\n binding  not successful");
pid=fork();

if(pid<0)
{
	printf("\nchild not created");
	close(sd);
	exit(1);
}
else if(pid>=0)
{
	printf("\nchild process created");
	process(sd);
}

close(sd);
}
void process(int sd)
{
printf("\ngoing inside process\n");
printf("==============================\n");
int i;
float n;
char ss[50],s1[40],s2[50],s3[50];
for( i=0;i<3;i++)
{
if(i==0)
{
int dd=sizeof(client1);
printf("Wait for input 1:\n");
recvfrom(sd,s1,sizeof(s1),0,(struct sockaddr *)&client1,&dd);
printf("\none=%s\n",s1);
printf("==============================\n");
}
if(i==1)
{
int ee=sizeof(client2);
printf("Wait for input 2:\n");
recvfrom(sd,s3,sizeof(s3),0,(struct sockaddr *)&client2,&ee);
printf("two=%s\n",s3);
printf("==============================\n");
}
if(i==2)
{
int dd=sizeof(client3);
printf("Wait for operator\n");
printf("==============================\n");

recvfrom(sd,s2,sizeof(s2),0,(struct sockaddr *)&client3,&dd);
if(!strcmp(s2,"+"))
{
n = atoi(s1)+atoi(s3);
gcvt(n,3,s2);
}
if(!strcmp(s2,"-"))
{
n = atoi(s1)-atoi(s3);
gcvt(n,3,s2);
}
if(!strcmp(s2,"*"))
{
n = atoi(s1)*atoi(s3);
gcvt(n,3,s2);
}
if(!strcmp(s2,"/"))
{
float n1 = atoi(s1)/atoi(s3);
gcvt(n1,6,s2);
} 
printf("\nanswer=%s\n",s2);
printf("==============================\n");
sendto(sd,s2,sizeof(s2),0,(struct sockaddr *)&client3,sizeof(client3));
}
}
}

