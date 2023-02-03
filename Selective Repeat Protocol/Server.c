#include"Myhead.h"
#include<time.h>

int check(int a)
{
	if((a%10)==1)
		return 1;
	else
		return 0;
}

int main()
{
        int sd,b,l,ac,d,i,j,pos;
        char msg[100],n[10],temp,n1[10];
	int sms[10]; char ack1[2];
        printf("Client\n");
        struct sockaddr_in server,client;
        server.sin_family = AF_INET;
        server.sin_port = htons(2022);
        server.sin_addr.s_addr = inet_addr("127.0.0.1");
        sd = socket(AF_INET,SOCK_DGRAM,0);
        if(sd>0)
                printf("[+] Client Socket Created Successful\n");
        
        b=bind(sd,(struct sockaddr*)&server ,sizeof(server));
        
      socklen_t  len=sizeof(client);
        

		recvfrom(sd,n1,1,0,(struct sockaddr*)&client,&len);
	int ws=atoi(n1);	
	recvfrom(sd,n,1,0,(struct sockaddr*)&client,&len);

	printf("\n##############################################\n");
	int ps=atoi(n);  int num;
	for(i=0;i<ws;i++)
	{
		
		recvfrom(sd,(char *)n,1,0,(struct sockaddr*)&client,&len);
		recvfrom(sd,(char *)msg,100,0,(struct sockaddr*)&client,&len);
		pos=atoi(n);
	
		num=atoi(msg);
		printf("Message : %s received from position %d\n",msg,pos+1);
		
		int ack=check(num);
		sprintf(ack1,"%d",ack);
		sendto(sd,ack1,1,0,(struct sockaddr*)&client,sizeof(client));
		sendto(sd,n,1,0,(struct sockaddr*)&client,sizeof(client));
		sendto(sd,msg,100,0,(struct sockaddr*)&client,sizeof(client));
		if(ack==1)
		{
			recvfrom(sd,(char *)n,1,0,(struct sockaddr*)&client,&len);
		recvfrom(sd,(char *)msg,100,0,(struct sockaddr*)&client,&len);					
		printf("\n $ Corrected msg : %s received  from pos %d\n",msg,pos+1);

		}
		printf("\n#################################################\n");
		sleep(3);
 	}

	
	

	close(sd);
}
