#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

void sigchld_handler(int);

/**
 * main - Fonction principale du programme.
 * 
 * Return: 0 en cas de succès.
*/
int main(int argc, char *argv[])
{
  pid_t pid;
  // Définition du gestionnaire de signal pour SIGCHLD
  signal(SIGCHLD, sigchld_handler);
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

/**
 * sigchld_handler - Gestionnaire de signal pour SIGCHLD, elle permet d'attendre un processus fils
 *                  sans bloquer le processus pere.
 * @signal: Le signal capturé.
*/
void sigchld_handler(int signal)
{
  int status;
  // Récupérer le statut de sortie de processus fils pour eviter qu'il devienne un zombie.
  pid_t pid = wait(&status);
  // Afficher le pid du processus fils terminé
  printf("Processus fils avec PID : %d est termine\n", pid);
}