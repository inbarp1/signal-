#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

static void sighandler(int signo){
  if (signo == SIGINT){
    printf("I’ve been interrupted by SIGINT signal how rude!\n");
    exit(1);
  }
  if(signo == SIGUSR1){
    printf("parent pid: %d", getppid());
  }
}
 int main(){
   signal(SIGINT, sighandler);
   signal(SIGUSR1,sighandler);
   while(1){
     printf("Pid # is: %d\n",getpid());
     sleep(1);
   }
 }
