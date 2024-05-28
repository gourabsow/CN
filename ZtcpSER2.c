#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
int main()
{
int serv_sockfd, cli_sockfd;
int serv_len, cli_len;
struct sockaddr_in serv_address, cli_address;
char a[100], b[100];
serv_address.sin_family = AF_INET;
serv_address.sin_port = htons(9001);
serv_address.sin_addr.s_addr = htonl(INADDR_ANY);
serv_len = sizeof(serv_address);
serv_sockfd = socket(AF_INET,SOCK_STREAM,0);
bind(serv_sockfd, (struct sockaddr*)&serv_address, serv_len);
listen(serv_sockfd, 1);
while(1)
{
printf("SERVER IS WAITING...");
cli_len=sizeof(cli_address);
cli_sockfd = accept(serv_sockfd,(struct sockaddr*)&cli_address,&cli_len);
printf("connect to client");
read(cli_sockfd, a, sizeof(a));
printf("reading message from client :");
puts(a);
write(cli_sockfd, b,sizeof(b));
gets(b);
close(cli_sockfd);
}
return 0;
}

