#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
int main()
{
int cfd,clen;
char ch[20];
printf("Enter the string: ");
scanf("%s",ch);
int len=strlen(ch);
struct sockaddr_in cadr;
cfd=socket(AF_INET , SOCK_DGRAM , 0);
cadr.sin_family=AF_INET;
cadr.sin_addr.s_addr=htonl(INADDR_ANY);
cadr.sin_port=htons(8888);
clen=sizeof(cadr);
bind(cfd,(struct sockaddr*)&cadr,clen);
sendto(cfd,&ch,len+1,0,(struct sockaddr*)&cadr,clen);
recvfrom(cfd,&ch,len+1,0,(struct sockaddr*)&cadr,&clen);
printf("Reverse String from server %s\n",ch);
//close(cfd);
return 0;
}
