#include <signal.h>
#include <stdio.h>

static void sighandler(int signo){
  if (signo == SIGINT){
    printf("I’ve been interrupted, how rude!\n");
    exit(1);
  }
  if(signo == SIGUSR1){
    printf("pid: %d", getppid());
  }
}
 int main(){
   while(1 == 1){
     signal(SIGINT, sighandler);
     printf("%d\n",getpid());
     sleep(1);
   }
 }
