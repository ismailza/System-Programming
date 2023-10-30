#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

// Prototypes
void run_command(char *, char **);

/**
 * main - Exécute la commande who & ps & ls -l.
 * 
 * Return: Toujours 0
*/
int main ()
{
  char *who_argv[] = {"who", NULL};     // Tableau d'arguments pour la commande who
  char *ps_argv[] = {"ps", NULL};       // Tableau d'arguments pour la commande ps
  char *ls_argv[] = {"ls", "-l", NULL}; // Tableau d'arguments pour la commande ls -l
  // On exécute les commandes who, ps et ls -l
  run_command("who", who_argv);
  run_command("ps", ps_argv);
  run_command("ls", ls_argv);
  // On attend la fin de l'exécution des processus fils
  while (wait(NULL) != -1);

  return 0;
}

/**
 * run_command - Exécute la commande name avec les arguments argv.
 * @name: Nom de la commande à exécuter
 * @argv: Tableau d'arguments pour la commande
*/
void run_command(char *name, char **argv)
{
  pid_t pid;
  // On crée le processus fils et on vérifie qu'il a bien été créé
  if ((pid = fork()) == -1)
  {
    perror("Erreur lors de la création du processus fils");
    exit(1);
  }
  // Si on est dans le processus fils. On exécute la commande
  else if (!pid)
  {
    execvp(name, argv);
    perror("Erreur lors de l'exécution de la commande");
    exit(1);
  }
}