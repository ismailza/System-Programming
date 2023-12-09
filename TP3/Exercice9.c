#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LENGTH 10

// Prototypes

char *read_command_line();
char **split_command_line(char *);
void run_command(char **);

/**
 * main - Simule le fonctionnement d'un terminal de commande
 *
 * return: Toujours 0
 */
int main()
{
  char *command;            // La commande entrée par l'utilisateur
  char **splitted_command;  // La commande séparée en arguments
  do
  {
    printf("monshell> ");
    if (!(command = read_command_line())) // Si la lecture a échoué
      exit(1);
    splitted_command = split_command_line(command);
    if (!splitted_command[0])             // Si la commande est vide, on recommence
    {
      free(command);
      free(splitted_command);
      continue;
    }
    // Si la commande est "exit", on quitte le programme
    if (!strcmp(splitted_command[0], "exit"))
    {
      free(command);
      free(splitted_command);
      exit(0);
    }
    run_command(splitted_command);      // On exécute la commande
    free(command);
    free(splitted_command);
  } while (1);

  return 0;
}

/**
 * read_command_line - Lit la commande entrée par l'utilisateur
 *
 * return: La commande entrée par l'utilisateur
 */
char *read_command_line()
{
  // Allocation de la mémoire pour la commande
  char *command = (char *)malloc(sizeof(char) * MAX_CMD_LENGTH * 10);
  if (!command) // Si l'allocation a échoué
  {
    printf("Error while allocating memory\n");
    exit(1);
  }
  // Lecture de la commande
  if (!fgets(command, MAX_CMD_LENGTH * 10, stdin))
  {
    printf("Error while reading command\n");
    free(command);
    return NULL;
  }
  return command;
}

/**
 * split_command_line - Sépare la commande en plusieurs arguments
 * @command: La commande à séparer
 *
 * return: Un tableau contenant les arguments de la commande
 */
char **split_command_line(char *command)
{
  // Allocation de la mémoire pour le tableau des arguments
  char **splitted_command = (char **)malloc(sizeof(char *) * MAX_CMD_LENGTH);
  if (!splitted_command) // Si l'allocation a échoué
  {
    printf("Error while allocating memory\n");
    exit(1);
  }
  // Séparation de la commande en arguments
  char *token = strtok(command, " \n");
  int i = 0;
  while (token != NULL) // Tant qu'il y a des arguments
  {
    // Allocation de la mémoire pour l'argument
    splitted_command[i] = (char *)malloc(sizeof(char) * (strlen(token) + 1));
    if (!splitted_command[i]) // Si l'allocation a échoué
    {
      printf("Error while allocating memory\n");
      exit(1);
    }
    strcpy(splitted_command[i++], token); // On copie l'argument dans le tableau
    token = strtok(NULL, " \n");          // On passe à l'argument suivant
  }
  splitted_command[i] = NULL; // On termine le tableau par NULL
  return splitted_command;
}

/**
 * run_command - Exécute la commande
 * @splitted_command: La commande à exécuter
 */
void run_command(char **splitted_command)
{
  pid_t pid = fork(); // On crée un processus fils
  if (pid == -1)      // Si le fork a échoué
  {
    printf("Error while forking\n");
    exit(1);
  }
  else if (pid == 0) // Si on est dans le processus fils
  {
    // On exécute la commande
    execvp(splitted_command[0], splitted_command);
    printf("Error while executing command\n"); // Si l'exécution a échoué
    exit(1);
  }
  else // Si on est dans le processus père, on attend la fin du fils
    waitpid(pid, NULL, 0);
}