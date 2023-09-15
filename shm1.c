#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/shm.h>
#include<string.h>
void main(){
int id;
char str[20];
id=shmget((key_t)3118,1024,0666|IPC_CREAT);
void *sd=shmat(id,NULL,0);
printf("atta at %p\nenter string\n",sd);
scanf("%s",str);
strcpy(sd,str);
printf("sent%s\n",(char*)sd);
}
