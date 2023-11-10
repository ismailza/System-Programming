#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Crée un processus fils. Le processus père affiche les entiers pairs et
 * le processus fils les entiers impairs compris entre 1 et 100.
 *
 * Return: 0 en cas de succès.
 */
int main()
{
  pid_t pid;
  // Configuration des signaux SIGCONT et SIGSTOP pour le traitement par défaut
  signal(SIGCONT, SIG_DFL);
  signal(SIGSTOP, SIG_DFL);
  // Création d'un processus fils et vérifier qu'il a bien été créé.
  if ((pid = fork()) == -1)
  {
    perror("Erreur lors de la creation d'un processus fils");
    exit(1);
  }
  else if (!pid) // Processus fils
  {
    for (int i = 1; i < 100; i += 2)
    {
      printf("%d\t", i);
      fflush(stdout);           // Forcer l'affichage immédiat sans attente de saut de ligne
      kill(getppid(), SIGCONT); // Envoyer un signal de réveil au processus père
      raise(SIGSTOP);           // Suspendre le processus fils jusqu'à réception du signal SIGCONT
    }
  }
  else // Processus pere
  {
    for (int i = 2; i <= 100; i += 2)
    {
      raise(SIGSTOP); // Suspendre le processus père jusqu'à réception du signal SIGCONT
      printf("%d\t", i);
      fflush(stdout);     // Forcer l'affichage immédiat sans attente de saut de ligne
      kill(pid, SIGCONT); // Envoyer un signal de réveil au processus fils
    }
    printf("\n");
  }

  return 0;
}
