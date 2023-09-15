#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void main() { // Changed from 'void' to 'int' for proper return type
    int fd[2], n;
    pid_t p;
    char buf[100];

    pipe(fd);

    p = fork();

    if (p < 0) { // Check for fork errors
        perror("fork");
        exit(1);
    }

    if (p > 0) { // Parent process // Close the read end of the pipe
        printf("Parent passing data to child\n");
        write(fd[1], "erripukanuvvu", 14); // Write data to the pipe
         // Close the write end of the pipe
        wait(NULL); // Wait for the child to finish
    } else { // Child process
         // Close the write end of the pipe
        printf("Child receiving data from parent\n");
        n = read(fd[0], buf, 100);
printf("%s hi\n",buf); // Read data from the pipe
        write(1, buf, n); // Write the data to stdout
         // Close the read end of the pipe
    }

    // Return 0 to indicate successful execution
}
