#include <stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<unistd.h>
int main()
{
	int	sockfd,len,result;
	struct sockaddr_in	serv_addr;
	char name[100], ser[100];
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	serv_addr.sin_family		= AF_INET;
	serv_addr.sin_addr.s_addr	= inet_addr("144.16.202.221");
	serv_addr.sin_port		= 6000;
	len=sizeof(	serv_addr);
	result=connect(sockfd, (struct sockaddr *) &serv_addr, len);
	if(result==-1)
	{
		perror("Unable to connect");
		exit(1);
	}
	while(1){
	printf("Enter the message:");
	gets(name);
	write(sockfd,name,sizeof(name));
	read(sockfd,ser,sizeof(ser));
	printf("\nReading from server:%c\n");
	puts(ser);
	
}
close(sockfd);
return 0;
	
}
