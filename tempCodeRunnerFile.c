#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
int pipe_fd[2]; pid_t pid;
char message[] = "Hello, child process!\n"; char read_buffer[100];
pipe(pipe_fd); pid = fork(); if (pid == 0) {
close(pipe_fd[1]);
read(pipe_fd[0], read_buffer, sizeof(read_buffer)); printf("Child Process: Received data from parent: %s",
read_buffer);
close(pipe_fd[0]);
} else {
close(pipe_fd[0]);
write(pipe_fd[1], message, sizeof(message)); close(pipe_fd[1]);
}
return 0; 
}