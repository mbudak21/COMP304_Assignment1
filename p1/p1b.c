#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

int main(){
  pid_t pid = fork();
  printf("Pid: %d\n", pid);

  if (pid == 0){ // Child
    printf("hello");
    sleep(6);
    printf("Dead");
  }
  else {
    kill();
  }
}
