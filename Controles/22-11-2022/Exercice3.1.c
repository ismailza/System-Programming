#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

void sigusr1_handler(int);
void sigusr2_handler(int);

int main()
{
  pid_t pid1, pid2;

  printf("Pere : Je suis le processus pere\n");
  // Création du premier processus fils
  if ((pid1 = fork()) == -1)
  {
    perror("Erreur lors de la creation du premier fils!\n");
    exit(1);
  }
  if (!pid1) // Premier processus fils (fils ainé)
  {
    signal(SIGUSR2, sigusr2_handler);
    printf("Fils aine : Attent du signal SIGUSR2...\n");
    while (1) // Simule un calcul infini
      sleep(1);
  }

  // Création du second processus fils
  if ((pid2 = fork()) == -1)
  {
    perror("Erreur lors de la creation du second fils!\n");
    exit(1);
  }
  if (!pid2) // Second processus fils (fils cadet)
  {
    signal(SIGUSR1, sigusr1_handler);
    printf("Fils cadet : Attent du signal SIGUSR1...\n");
    pause();
    printf("Fils cadet : Envoi de signal SIGUSR2 au fils aine dont le pid est %d\n", pid1);
    kill(pid1, SIGUSR2);
    raise(SIGSTOP); // Attendre la fin du processus fils ainé
    exit(EXIT_SUCCESS);
  }

  // Processus pere
  sleep(1);
  printf("Pere : Envoi du signal SIGUSR1 au fils cadet dont le pid est %d\n", pid2);
  kill(pid2, SIGUSR1);

  if (waitpid(pid1, NULL, 0) != -1) // Attendre la fin du fils ainé
    kill(pid2, SIGCONT);
  printf("Fin du processus aine!\n");

  wait(NULL); // Attendre la fin du fils cadet
  printf("Fin du processus cadet!\n");

  return 0;
}

/**
 * sigusr1_handler - Gère le signal SIGUSR1 reçu par le fils cadet.
 * @signal: Le numéro du signal reçu.
 *
 * Réactive le processus aîné en envoyant SIGCONT.
 */
void sigusr1_handler(int signal)
{
  raise(SIGCONT);
}

/**
 * sigusr2_handler - Gère le signal SIGUSR2 reçu par le fils aîné.
 * @signal: Le numéro du signal reçu.
 *
 * Termine le processus aîné avec exit.
 */
void sigusr2_handler(int signal)
{
  exit(EXIT_SUCCESS);
}