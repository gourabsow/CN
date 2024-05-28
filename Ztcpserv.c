#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){

int serv_sockfd, cli_sockfd;
int serv_len, cli_len;
struct sockaddr_in serv_address, cli_address;
char a[800], b[800];
serv_address.sin_family =AF_INET;
serv_address.sin_port =5099;
serv_address.sin_addr.s_addr = htonl(INADDR_ANY);
serv_len = sizeof(serv_address);
serv_sockfd= socket(AF_INET,SOCK_STREAM,0);
bind(serv_sockfd,(struct sockaddr*)&serv_address,serv_len);
listen(serv_sockfd,5);
printf("server ready........");
cli_len= sizeof(cli_address);
cli_sockfd = accept(serv_sockfd,(struct sockaddr*)&cli_address,&cli_len);
printf("\n connect to client");
read(cli_sockfd,a, sizeof(a));
while(1)
{
printf("\n reading messege bfrom client:");
fputs(a,stdout);
printf("\n type your messege:");
fgets(a,800,stdin);
write(cli_sockfd,a,sizeof(a));
printf("\n");
read(cli_sockfd,a,sizeof(a));
}
close(cli_sockfd);
return 0;
}
