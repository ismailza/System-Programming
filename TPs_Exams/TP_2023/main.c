#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  pid_t pid;

  for (int i = 1; i < argc; i++)
  {
    if ((pid = fork()) == -1)
    {
      perror("Erreur lors de la creation d'un processus fils!\n");
      exit(1);
    }
    else if (!pid) // Processus fils
    {
      printf("Je suis le fils charge de faire %s\n", argv[i]);
      execlp(argv[i], argv[i], NULL);
      perror("Erreur lors de l'execution d'une commande!\n");
      exit(1);
    }
  }

  // Attendre tous les fils
  while ((pid = wait(NULL)) != -1)
    printf("%d se charge du boulot\n", pid);

  return 0;
}