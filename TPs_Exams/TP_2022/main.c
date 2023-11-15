#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

int main()
{
  pid_t pid;
  int status;
  char arg[5];
  for (int i = 1; i <= N; i++)
  {
    if ((pid = fork()) == -1)
    {
      perror("Erreur lors de la creation de processus fils!\n");
      exit(1);
    }
    else if (!pid)  // Processus fils
    {
      sprintf(arg, "%d", i);
      execlp("./code.out", "code", arg, NULL);
      perror("Erreur lors de l'execution d'un processus!\n");
      exit(1);
    }
    wait(&status);
    printf("\nFin du processus %d\n", WEXITSTATUS(status));
  }

  return 0;
}