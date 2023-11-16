#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
  if (argc < 3)
  {
    perror("Erreur, nombre d'arguments est insuffisant!\n");
    exit(1);
  }

  pid_t pid;

  signal(SIGHUP, SIG_IGN);  // Ignorer le signal SIGHUP

  if ((pid = fork()) == -1) // Créer un processus fils
  {
    perror("Erreur lors de la creation du processus fils!\n");
    exit(1);
  }
  else if (!pid)  // Processus fils
  {
    // Exécuter la deuxième commande passée en argument avec ses arguments
    execvp(argv[2], argv + 2);
    perror("Erreur lors de l'execution de la commande au niveau du fils!\n");
    exit(1);
  }
  // Processus pere
  // Exécuter la première commande passée en argument
  execlp(argv[1], argv[1], NULL);
  perror("Erreur lors de l'execution de la commande au niveau de pere!\n");
  exit(1);

}