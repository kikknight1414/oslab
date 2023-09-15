#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
void main(){
int res,n;
mkfifo("fifo1",0777);
printf("created\n");
}
