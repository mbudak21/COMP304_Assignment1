#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

int main(){
  int seconds=6;
  pid_t pid = fork();
  printf("Pid: %d\n", pid);

  if (pid == 0){ // Child
    printf("Child Process started with PID: %d.\n", pid);
    printf("Child Process PID:% d exiting.\n", pid);
    exit(0);
  }
  else { // Parent
    printf("Parent process waiting for %d seconds.\n", seconds);
    sleep(seconds);
    printf("Parent process PID: %d exiting.\n", pid);
  }
}
