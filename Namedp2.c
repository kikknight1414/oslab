#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
void main(){
int res,n;
char str[30];
res=open("fifo1",O_RDONLY);
n=read(res,str,29);
printf("reciever process started %d\n",getpid());
printf("reciever process %d read the data %s",getpid(),str);
}
