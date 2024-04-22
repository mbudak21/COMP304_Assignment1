#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int fork_it(int n, int level){
  if (n == 0){
    return 0;
  }

  pid_t pid = fork();
  if (pid == 0){
    level++;
    printf("Process ID: %d, Parent ID: %d, Level: %d\n", getpid(), getppid(), level);
  }
  fork_it(n-1, level);
}

int main(int argc, char *argv[]){
  // Input Section
  if (argc < 2){
    printf("Usage: %s <number>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  if (n < 1) {
    printf("Error: 'number' must be a positive integer.\n");
    return 1;
  }

  // Main Process
  printf("Main Process ID: %d, level: %d\n", getpid(), 0);
  fork_it(n, 0);
}