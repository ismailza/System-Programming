#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc < 3)
  {
    perror("Il faut au moins deaux arguments!\n");
    exit(EXIT_FAILURE);
  }

  int i = 1;
  int tube[2];
  int in = STDIN_FILENO;
  int out = STDOUT_FILENO;

  do
  {
    if (pipe(tube) == -1)
    {
      perror("Erreur lors de la creation du tube!\n");
      exit(EXIT_FAILURE);
    }
    if (!fork())
    {
      close(tube[1]);
      // in = tube[0];
      dup2(tube[0], in);
    }
    else
    {
      close(tube[0]);
      // out = tube[1];
      dup2(tube[1], out);

      break;
    }
    i++;
  } while (i < (argc - 1));
  
  execlp(argv[i], argv[i], NULL);
  printf("Erreur d'execution de la commande %s !\n", argv[i]);
  exit(EXIT_FAILURE);

  return 0;
}