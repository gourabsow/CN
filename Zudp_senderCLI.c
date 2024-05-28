#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main()
{
int cfd,clen;
char ch='b';
struct sockaddr_in cadr;
cfd=socket(AF_INET, SOCK_DGRAM, 0);
cadr.sin_family=AF_INET;
cadr.sin_addr.s_addr=htonl(INADDR_ANY);
cadr.sin_port=htons(8888);
clen=sizeof(cadr);
bind(cfd,(struct sockaddr*)&cadr,clen);
sendto(cfd,&ch,1,0,(struct sockaddr*)&cadr,clen);
recvfrom(cfd,&ch,1,0,(struct sockaddr*)&cadr,&clen);
printf("character from server %c\n",ch);
//close(cfd);
return 0;
}
