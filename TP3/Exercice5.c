#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Crée deux processus fils qui exécutent respectivement les commandes ls -l et ps -l.
 * 
 * Return: Toujours 0.
*/
int main()
{
  pid_t pid;

  if ((pid = fork()) == -1) // On crée le premier processus fils et on vérifie qu'il a bien été créé.
  {
    perror("Erreur lors de la creation du premier processus fils.");
    exit(-1);
  }
  else if (!pid)  // On est dans le premier processus fils.
    exit(execlp("ls", "ls", "-l", NULL));
  else            // On est dans le processus père.
  {
    if ((pid = fork()) == -1) // On crée le second processus fils et on vérifie qu'il a bien été créé.
    {
      perror("Erreur lors de la creation du second processus fils.");
      exit(-1);
    }
    else if (!pid)  // On est dans le second processus fils.
      exit(execlp("ps", "ps", "-l", NULL));
    
    pid = wait(NULL); // On attend que le premier processus fils se termine.
    wait(NULL); // On attend que le second processus fils se termine.
    printf("\nLe premier processus fils s'est terminé est le processus avec le PID %d.\n", pid);
  }

  return 0;
}