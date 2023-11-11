#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Fonction principale du programme.
 * 
 * Return: 0 en cas de succès.
*/
int main(int argc, char *argv[])
{
  pid_t pid;
  // Ignorer le signal SIGCHLD pour éviter que le fils ne devienne un zombie
  signal(SIGCHLD, SIG_IGN);
  // Création du processus fils
  if ((pid = fork()) == -1)
  {
    perror("Erreur lors de la creation du processus fils");
    exit(1);
  }
  else if (!pid) // Processus fils
  {
    for (int i = 0; i < 10; i++)
      ; // Simule un petit calcul
    exit(1);
  }
  while (1)
    ; // Simule un calcul infini

  return 0;
}