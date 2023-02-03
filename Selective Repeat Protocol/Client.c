#include"Myhead.h"
#include<time.h>
int stuff(int a,int ch)
{


	if(ch==1)
		a=(a*10)+1;
	else
		a=(a*10);

	return a;
}

int invert(int a)
{
	if((a%10)==1)
{
	a=a/10;
	a=(a*10);
}


return a;
}



int main()
{
        int sd,b,l,ac,ack,pos,cnt,temp,imsg;

	int ps,ws,i,j,k,ch;
        char msg1[100],n[10];
	char posi[3],wss[10];
        printf("Client\n");
        struct sockaddr_in server,client;
        socklen_t len=sizeof(server);
        socklen_t len1=sizeof(server);
        server.sin_family = AF_INET;
        int h;
        server.sin_port = htons(2022);
        server.sin_addr.s_addr = inet_addr("127.0.0.1");
        sd = socket(AF_INET,SOCK_DGRAM,0);
        if(sd>0)
                printf("Client Socket Created Successfully \n");
        else
                printf("socket Error\n");
        b=bind(sd,(struct sockaddr*)&client,len1);
       

printf("Enter Frame Size and Window Size:\n");
	scanf("%d",&ws);
	scanf("%d",&ps);
	int msg[ws];
	
	
	char pss[2];
	for(i=0;i<ws;i++)
	{
		printf("Enter The Message: %d\n",i+1);
		scanf("%d",&msg[i]);
		printf("1-Intro Error 2-No Error\n");
		scanf("%d",&ch);
		msg[i]=stuff(msg[i],ch);		
		printf("%d\n",msg[i]);
	}
		sprintf(pss,"%d",ps);
		sprintf(wss,"%d",ws);
		sendto(sd,wss,100,0,(struct sockaddr*)&server,sizeof(server));	
                sendto(sd,pss,100,0,(struct sockaddr*)&server,sizeof(server));	
		
	i=0;
	
	label:
	
		 cnt=0;	
	printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	for(;(cnt<ps)&&(i<ws);cnt++)
	{
		
		sprintf(msg1,"%d",msg[i]);	
		printf("%s\n",msg1);
		sprintf(posi,"%d",i);
		sendto(sd,posi,1,0,(struct sockaddr*)&server,sizeof(server));	
			 
		sendto(sd,msg1,100,0,(struct sockaddr*)&server,sizeof(server));	
		printf("Message: %d sent \n ",i+1);
		
	recvfrom(sd,(char *)n,1,0,(struct sockaddr*)&server,&len);
	recvfrom(sd,(char *)posi,1,0,(struct sockaddr*)&server,&len);
	recvfrom(sd,(char *)msg1,100,0,(struct sockaddr*)&server,&len);
	printf("\n[+] Message %s received with ACK as %s\n",msg1,n);
	imsg=atoi(msg1);
	ack=atoi(n);
	pos=atoi(posi);
	
	
	if(ack==1)
	{
		k=pos;
		msg[i]=invert(msg[i]);
		printf("\nRectified Message : %d\n",msg[i]);
		sprintf(msg1,"%d",msg[i]);
		sprintf(posi,"%d",i);
		sendto(sd,posi,1,0,(struct sockaddr*)&server,sizeof(server));
		sendto(sd,msg1,100,0,(struct sockaddr*)&server,sizeof(server));	
		
	}
	printf("\n          @@@@@@       \n");
		 i=i+1;
		 temp=i;

		
	}
	
	printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	sleep(3);
         i=temp;
	if(i<ws)
	{
	goto label;
	}
	
	
printf("\n----------------------\n");

        close(sd);
}
