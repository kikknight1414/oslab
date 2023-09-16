#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
void main(int argc,char *argv[]){
pid_t p,w;
int status;
p=fork();
if(p==0){
printf("child pid%d\n",getpid());
if(argc==1)
pause();
exit(atoi(argv[1]));
}
else{
do{
w=waitpid(p,&status,WUNTRACED|WCONTINUED);
if(WIFEXITED(status)){
printf("EXITED DUE TO SIG %d\n",WEXITSTATUS(status));
}
else if(WIFSIGNALED(status)){
printf("exit sig is %d\n",WTERMSIG(status));
}
else if(WIFSTOPPED(status)){
printf("exit sig %d\n",WSTOPSIG(status));
}
else if(WIFCONTINUED(status)){
printf("continued");
}
}while(!WIFEXITED(status) && !WIFSIGNALED(status));
}
}
