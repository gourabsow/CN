#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
int main(){
int sockfd,len,result;
struct sockaddr_in address;
char name[800];
sockfd=socket(AF_INET,SOCK_STREAM,0);
address.sin_family=AF_INET;
address.sin_port=5099;
address.sin_addr.s_addr=htonl(INADDR_ANY);
len=sizeof(address);
result=connect(sockfd,(struct sockaddr *)&address,len);
printf("Enter the message to be sent :");
fgets(name,800,stdin);
fputs(name,stdout);
while(name!="quit")
{
write(sockfd,name,sizeof(name));
printf("\n Message sent to server");
read(sockfd,name,sizeof(name));
printf("\n Reading from server : %s",name);
int i= strncmp("quit",name,4);
if(i==0)
break;
printf("\nType your message :\t");
fgets(name,800,stdin);
}
close(sockfd);
return(0);
}
