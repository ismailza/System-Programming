#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
  if (argc < 2)
  {
    perror("Erreur, nombre d'arguments est insuffisant!\n");
    exit(1);
  }

  signal(SIGHUP, SIG_IGN); // Ignorer le signal SIGHUP

  while (1)
    sleep(1);

  // Exécuter la commande passée en argument
  execvp(argv[1], argv + 1);
  perror("Erreur lors de l'execution de la commande au niveau de pere!\n");
  exit(1);
}