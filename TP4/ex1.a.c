#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Cree un processus fils, le pere affiche les entiers pair et le fils les impairs compris entre 1 et 100.
 * 
 * Return: Toujours 0
 * Remarque : on doit utiliser fflush pour un affichage imediat [vider tompon de sortie standard] faire ecriture avant de continuer l'execution
*/
int main()
{
  pid_t pid;
  //configuration des signaux par ses  taches en defaut
  signal(SIGCONT, SIG_DFL);
  signal(SIGSTOP, SIG_DFL);
  if ((pid = fork()) == -1)
  {
    perror("Erreur lors de la creation d'un processus fils");
    exit(1);
  }
  else if (!pid)  // Processus fils
  {
    for (int i = 1; i < 100; i += 2)
    {
      printf("%d\t", i);
      fflush(stdout); //vider buffer
      kill(getppid(), SIGCONT);
      raise(SIGSTOP);
    }
  }
  else // Processus pere
  {
    for (int i = 2; i <= 100; i += 2)
    {
      raise(SIGSTOP);
      printf("%d\t", i);
      fflush(stdout);
      kill(pid, SIGCONT);
    }
    printf("\n");
  }

  return 0;
}