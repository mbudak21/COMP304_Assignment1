#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void print_info(int level){
    printf("Process ID: %d, Parent ID: %d, level: %d\n", getpid(), getppid(), level);
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


  // Main Section
  int level = 0;
  int mainPID = getpid();
  printf("Main Process ID: %d, level: %d\n", mainPID, level);

  pid_t pid;
  int numOfChils = 0;
  for (int i=0; i<n; i++){
    pid = fork();
    if (pid == 0){
      level += 1;
      printf("Process ID: %d, Parent ID: %d, level: %d\n", getpid(), getppid(), level);
    }
    else{
      numOfChils += 1;
    }
  }

  for (int i=0; i<numOfChils; i++){
    wait(NULL);
  }
}



