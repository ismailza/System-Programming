#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

void print_process_characteristics();

/**
 * main - Créer un processus fils, et affiche pour les deux processus les caractéristiques générales d’un processus.
 *
 * Return: Toujours 0.
 */
int main()
{
  if (fork()) // Créer un processus fils et tester si on est dans le processus père.
  {
    printf("\nLe processus père :");
    print_process_characteristics();
    wait(NULL); // Attendre la fin du fils s'il est le premier éxécuté.
  }
  else // On est dans le processus fils.
  {
    printf("\nLe processus fils :");
    print_process_characteristics();
  }
  return 0;
}

/**
 * print_process_characteristics - Affiche les caractéristiques générales d’un processus.
 */
void print_process_characteristics()
{
  printf("\n%d\t: Identifiant du processus", getpid());
  printf("\n%d\t: Identifiant du processus père", getppid());
  printf("\n%d\t: Propriétaire réel", getuid());
  printf("\n%d\t: Propriétaire effectif", geteuid());
  printf("\n%d\t: Groupe propriétaire réel", getgid());
  printf("\n%d\t: Groupe propriétaire effectif", getegid());
  printf("\n");
}