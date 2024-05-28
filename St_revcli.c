#include <stdio.h> 
Client Side program: 
#include<stdlib.h> 
#include<unistd.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include<string.h> 
#include<arpa/inet.h> 
int main() 
{ 
int sockfd, portno, n,addr_len; 
struct sockaddr_in serv_addr; 
char buffer[1024]; 
if((sockfd = socket(AF_INET , SOCK_STREAM,0))==-1) 
{ 
perror("socket"); 
exit(1);      
} 
serv_addr.sin_family=AF_INET; 
serv_addr.sin_port=9002; 
serv_addr.sin_addr.s_addr=INADDR_ANY; 
bzero(&serv_addr.sin_zero,8); 
addr_len=sizeof(serv_addr); 
if((connect(sockfd, (struct sockaddr *) &serv_addr, addr_len)==-1)) 
{ 
perror("connect"); 
} 
printf("enter the message\n"); 
//while(1){ 
scanf("%s",buffer); 
write(sockfd,buffer,sizeof(buffer)); 
read(sockfd,buffer,sizeof(buffer)); 
printf("%s",buffer); 
//} 
close(sockfd); 
}
