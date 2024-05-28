#include <stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<unistd.h>
int main()
{
	int serv_sockfd,cli_sockfd;
	int cli_len;
	char buf[100],a[100]
	struct sockaddr_in serv_addr,cli_addr;
	if((serv_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("cannot create socket\n");
		exit(0);
	}
	serv_addr.sin_family		= AF_INET;
	serv_addr.sin_addr.s_addr	= INADDR_ANY;
	serv_addr.sin_port		= 6000;
	if (bind(serv_sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
	{
		printf("Unable to bind local address\n");
		exit(0);
	}

    listen(serv_sockfd, 5);
    while(1)
    {
    	printf("Server is running....\n");
    	cli_len=sizeof(cli_addr);
    	cli_sockfd = accept(serv_sockfd, (struct sockaddr *) &cli_addr, &cli_len) ;
    	if(cli_sockfd<0)
    	{
    		printf("Accept error\n");
    		exit(0);
		}
		if(fork()==0)
		{
			close(serv_sockfd);
			while(1)
			{
				read(cli_sockfd,buf,sizeof(buf));
				printf("\nReading the message for client:%s\n",buf);
				write(cli_sockfd,buf,strlen(buf)+1);
			}
			close(cli_sockfd);
			exit(0);
		}
	}
	return 0;
}
