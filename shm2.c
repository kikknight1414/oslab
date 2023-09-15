#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/shm.h>
#include<string.h>
void main(){
int id,n;
id=shmget((key_t)3118,1024,0666|IPC_CREAT);
void *sd=shmat(id,NULL,0);
printf("recev%s\n",(char*)sd);
}


