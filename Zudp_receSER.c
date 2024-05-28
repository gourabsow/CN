#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
int main()
{
int sfd,slen;
struct sockaddr_in c;
sfd=socket(AF_INET, SOCK_DGRAM, 0);
c.sin_family=AF_INET;
c.sin_addr.s_addr=htonl(INADDR_ANY);
c.sin_port=htons(8888);
slen=sizeof(c);
bind(sfd,(struct sockaddr*)&c,slen);
while(1)
{
char ch[30];
printf("server on \n");
recvfrom(sfd,&ch,30,0,(struct sockaddr*)&c,&slen);
int len = strlen(ch);
for(int i=0,j=len-1;i<=j;i++,j--){
char c=ch[i];
ch[i]=ch[j];
ch[j]=c;

}

sendto(sfd,&ch,30,0,(struct sockaddr*)&c,slen);
}
return 0;
}
