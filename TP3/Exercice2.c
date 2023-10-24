#include <unistd.h>
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
  }
  else      // On est dans le processus fils.
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
  printf("\nIdentifiant du processus \t:\t%d", getpid());
  printf("\nIdentifiant du processus père \t:\t%d", getppid());
  printf("\nPropriétaire réel \t:\t%d", getuid());
  printf("\nPropriétaire effectif \t:\t%d", geteuid());
  printf("\nGroupe propriétaire réel \t:\t%d", getgid());
  printf("\nGroupe propriétaire effectif \t:\t%d", getegid());
  printf("\n");
}