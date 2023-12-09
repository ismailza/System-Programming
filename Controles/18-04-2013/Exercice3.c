#include <unistd.h>
#include <threads.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define File "Fich" // Fichier de sortie
#define R 0
#define W 1

void handle_error(char *);

int main()
{
  int pipe1[2];
  int file;
  char c;
  pid_t pid1, pid2;

  // Création du tube
  if (pipe(pipe1) == -1)
    handle_error("Erreur lors de la creation du tube!\n");

  // Création du premier processus fils
  if ((pid1 = fork()) == -1)
    handle_error("Erreur lors de creation du premier processus!\n");
  else if (!pid1) // P1 - Le premier processus fils
  {
    close(pipe1[R]);
    // Lecture de caractères depuis l'entrée standard
    while ((c = getchar()) != -1)
      write(pipe1[W], &c, sizeof(c));
    close(pipe1[W]);

    exit(EXIT_SUCCESS);
  }

  // Création du second processus fils
  if ((pid2 = fork()) == -1)
    handle_error("Erreur lors de creation du second processus!\n");
  else if (!pid2) // P2 - Le second processus fils
  {
    close(pipe1[R]);
    // Lecture de caractères depuis l'entrée standard
    while ((c = getchar()) != -1)
      write(pipe1[W], &c, sizeof(c));
    close(pipe1[W]);

    exit(EXIT_SUCCESS);
  }

  // P0 - Processus pere

  // Ouverture (création s'il n'existe pas) du fichier de sortie en écriture seule avec les droits de lecture et écriture
  if ((file = open(File, O_WRONLY | O_CREAT, 0666)) == -1)
    handle_error("Erreur lors de l'ouverture du fichier!\n");

  close(pipe1[W]);
  dup2(pipe1[R], STDIN_FILENO); // Redirection de l'entrée standard vers l'extrémité de lecture du tube
  close(pipe1[R]);
  // Lecture de caractères depuis le tube et écriture dans le fichier
  while ((read(STDIN_FILENO, &c, 1)) > 0)
    write(file, &c, 1);
  // Attente de la fin des processus fils
  while (wait(NULL) > 0)
    ;
  // Fermeture du fichier de sortie
  close(file);

  return 0;
}

/**
 * handle_error - Fonction pour afficher des messages d'erreur et quitter
 * @msg: Le message d'erreur à afficher
 */
void handle_error(char *msg)
{
  perror(msg);
  exit(EXIT_FAILURE);
}