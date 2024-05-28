#include <stdio.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <arpa/inet.h> 
void reverse(char *input,char *output){ 
int i,n=0; 
for(i=0;input[i]!='\0';i++) 
n++; 
for(i=0;i<n;i++) 
output[n-i-1] = input[i]; 
output[n]='\0';  
} 
int main() 
{ 
int sockfd,addr_len; 
int clientfd; 
int bytes_read; 
char buf[1024],data[1024]; 
int struct_size; 
struct sockaddr_in server; 
struct sockaddr_in client; 
if((sockfd = socket(AF_INET, SOCK_STREAM, 0))==-1) 
{ 
perror("server socket:-  "); 
exit(1); 
} 
server.sin_family = AF_INET; 
    server.sin_port = 9002; 
    server.sin_addr.s_addr =INADDR_ANY; 
    bzero(&server.sin_zero, 8); 
 
   if((bind(sockfd, (struct sockaddr *)&server, sizeof(struct sockaddr_in))==-1)) 
 { 
  perror("bind:-  "); 
  exit(1); 
 } 
 
   if(listen(sockfd,5)==-1) 
 { 
  perror("listen:-  "); 
  exit(1); 
 } 
 while(1) 
 { 
  printf("server is waiting.............\n"); 
  addr_len=sizeof(client); 
      if((clientfd = accept(sockfd,(struct sockaddr *)&client, &addr_len)==
1)) 
  { 
   perror("accept :-  "); 
   exit(1); 
  } 
        printf("new client connected from port no %d and IP %s 
\n",client.sin_port,client.sin_addr); 
 read(client,buf,sizeof(buf)); 
 printf("reading message from client\n"); 
 printf("%s\n",buf); 
 reverse(buf,data); 
 write(client,data,sizeof(data)); 
 } 
     close(sockfd); 
     close(clientfd); 
} 

