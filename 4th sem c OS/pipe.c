#include <unistd.h>
#include <stdio.h>

int main() {
    int fd[2];
    char buffer[20];
    
    // Create a pipe
    if (pipe(fd) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    // Fork a child process
    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {  // Child process
        close(fd[1]);  // Close the write end since the child is reading

        // Read from the pipe
        read(fd[0], buffer, sizeof(buffer));
        printf("Child process received: %s\n", buffer);

        close(fd[0]);
    } else {  // Parent process
        close(fd[0]);  // Close the read end since the parent is writing

        // Write to the pipe
        write(fd[1], "Hello, child!", 13);

        close(fd[1]);
    }

    return 0;
}

/* 
Simplest Form : 

#include<stdio.h>
#include<unistd.h>

int main(){
    pid_t pid;
    int fd[2];
    pipe(fd);
    char buffer[20];

    pid=fork();
    if(pid==0){ // child
        close(fd[1]);
        read(fd[0],buffer,sizeof(buffer));
        printf("Child process read : %s \n",buffer);
        close(fd[0]);
    }
    else{ // parent
        close(fd[0]);
        write(fd[1],"Hello!",sizeof("Hello!"));
        printf("Parent process wrote : Hello! \n");
        close(fd[1]);
    }
    return 0;
}

*/