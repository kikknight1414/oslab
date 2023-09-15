#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {  // Change to int main()
    int fd1, fd2;
    char buf;

    // Open file1 and file2 with appropriate permissions
    fd1 = open("file1", O_RDONLY);
    if (fd1 == -1) {
        perror("Error opening file1");
        return 1;
    }

    fd2 = open("file5", O_WRONLY | O_CREAT);
    if (fd2 == -1) {
        perror("Error opening file2");
        close(fd1);  // Close file1 before exiting
        return 1;
    }

    while (read(fd1, &buf, 1)){
        write(fd2, &buf, 1);
    }

    close(fd1);
    close(fd2);
    printf("Success\n");

    return 0;
}
