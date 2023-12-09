#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void afficherBONJOUR(int);

int main()
{
  pid_t pid, ppid = getpid();
  
  if ((pid = fork()) == -1)
  {
    perror("Erreur lors de la creation du processus fils\n");
    exit(1);
  }
  else if (!pid)  // Processus fils
  {
    raise(SIGSTOP);
    printf("fils: Je suis le processus %d\n", getpid());
    kill(ppid, SIGCONT);
    raise(SIGSTOP);
    kill(ppid, SIGUSR1);
    sleep(1);
    printf("fils: Fin du processus\n");
    exit(0);
  }
  // Processus pere
  signal(SIGUSR1, afficherBONJOUR);

  printf("pere: Je suis le processus %d\n", ppid);
  kill(pid, SIGCONT);
  raise(SIGSTOP);
  printf("pere: J'attends un signal\n");
  kill(pid, SIGCONT);
  wait(NULL);
  printf("pere: Fin du processus\n");

  return 0;
}

void afficherBONJOUR(int signal)
{
  printf("Bonjours\n");
}