#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
void main(){
int res,n;
res=open("fifo1",O_WRONLY);
write(res,"hello",5);
printf("sender process %d sent the data\n",getpid());
}
