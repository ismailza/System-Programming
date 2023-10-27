#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

// Prototypes
void print_process_characteristics(char *);

/**
 * main - Créer un processus fils, et affiche pour les deux processus les caractéristiques générales d’un processus.
 *
 * Return: Toujours 0.
 */
int main()
{
  pid_t pid;
  if ((pid = fork()) == -1) // Créer un processus fils et vérifier qu'il a bien été créé.
  {
    perror("Erreur lors de la creation du processus fils.");
    exit(-1);
  }
  else if (pid) // On est dans le processus père.
  {
    print_process_characteristics("Le processus père");
    wait(NULL); // Attendre la fin du fils s'il est le premier éxécuté.
  }
  else // On est dans le processus fils.
    print_process_characteristics("Le processus fils");
  return 0;
}

/**
 * print_process_characteristics - Affiche les caractéristiques générales d’un processus.
 */
void print_process_characteristics(char *name)
{
  printf("\n***\t%s", name);
  printf("\n%d\t: Identifiant du processus", getpid());
  printf("\n%d\t: Identifiant du processus père", getppid());
  printf("\n%d\t: Propriétaire réel", getuid());
  printf("\n%d\t: Propriétaire effectif", geteuid());
  printf("\n%d\t: Groupe propriétaire réel", getgid());
  printf("\n%d\t: Groupe propriétaire effectif", getegid());
  printf("\n");
}