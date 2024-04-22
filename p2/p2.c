#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc, char *argv[]){
    // VARIABLES:
    int n;
    char *command;

    // Check if there are at least 3 arguments: the program name, a number, and a command
    if (argc < 3){
        printf("Usage: %s <number> <command>\n", argv[0]);
        return 1;
    }

    n = atoi(argv[1]);
    if (n < 1) {
        printf("Error: 'number' must be a positive integer.\n");
        return 1;
    }

    command = argv[2];

  // n parallel forks
  pid_t main_pid = getpid();
  for (int i=0; i<n; i++){
    if (main_pid == getpid()){
      fork();
    }
  }

  if (main_pid != getpid()){
    // Execute a process

  }
  
}