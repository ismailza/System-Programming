#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Créer un processus fils et exécute la commande ps -l avec la fonction execl.
 *
 * Return: Toujours 0.
 */
int main()
{
  pid_t pid;
  int status;
  if ((pid = fork()) == -1) // Créer un processus fils et vérifier qu'il a bien été créé.
  {
    perror("Erreur lors de la creation du processus fils.");
    exit(-1);
  }
  else if (!pid)  // On est dans le processus fils.
    exit(execl("/bin/ps", "ps", "-l", NULL));  // On exécute la commande ps -l.
  else  // On est dans le processus père.
  {
    wait(&status);  // On attend la fin du processus fils.
    printf("Le processus fils s'est terminé avec le code de retour %d.\n", WEXITSTATUS(status));
  }

  return 0;
}