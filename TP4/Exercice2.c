#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

#define R 0 // Indice pour la lecture de l'extrémité du tube
#define W 1 // Indice pour l'écriture de l'extrémité du tube

/**
 * main - Execute la commande ps -uax | grep root | wc –l
 *
 * Return: 0 en cas de succès.
 */
int main()
{
  int fd1[2], fd2[2];
  pid_t pid1, pid2;
  // Création de deux tubes
  if ((pipe(fd1) == -1) || (pipe(fd2) == -1))
  {
    perror("Erreur lors de la création des tubes");
    exit(1);
  }
  // Créer le 1er processus fils et vérifier qu'il a bien été créé.
  if ((pid1 = fork()) == -1)
  {
    perror("Erreur lors de la creation du processus fils");
    exit(1);
  }
  else if (!pid1) // 1er processus fils
  {
    close(fd1[R]);   // Fermeture de descripteur de lecture du premier tupe
    dup2(fd1[W], 1); // Redirection de la sortie standard vers le premier tube
    close(fd1[W]);   // Fermeture de descripteur d'ecriture du premier tupe
    // Execution la commande ps -uax
    execlp("ps", "ps", "-uax", NULL);
    perror("Erreur lors de l'execution de la commande ps -uax");
    exit(1);
  }

  // Fermeture du côté d'écriture du premier tube dans le processus parent
  close(fd1[W]);
  // Créer le 2ème processus fils et vérifier qu'il a bien été créé.
  if ((pid2 = fork()) == -1)
  {
    perror("Erreur lors de la creation du processus fils");
    exit(1);
  }
  else if (!pid2) // 2ème processus fils
  {
    close(fd1[W]);   // Fermeture de descripteur d'ecriture du premier tupe
    dup2(fd1[R], 0); // Redirection de l'entrée standard depuis le premier tube
    close(fd1[R]);   // Fermeture de descripteur de lecture du premier tupe

    close(fd2[R]);   // Fermeture de descripteur de lecture du deuxième tupe
    dup2(fd2[W], 1); // Redirection de la sortie standard vers le deuxième tube
    close(fd2[W]);   // Fermeture de descripteur d'ecriture du deuxième tupe
    // Execution la commande grep root
    execlp("grep", "grep", "root", NULL);
    perror("Erreur lors de l'execution de la commande grep root");
    exit(1);
  }

  // Fermeture du côté de lecture du premier tube dans le processus parent
  close(fd1[R]);

  close(fd2[W]);   // Fermeture de descripteur d'ecriture du deuxième tupe
  dup2(fd2[R], 0); // Redirection de l'entrée standard depuis le deuxième tube
  close(fd2[R]);   // Fermeture de descripteur de lecture du deuxième tupe
  // Execution de la commande wc -l
  execlp("wc", "wc", "-l", NULL);
  perror("Erreur lors de l'execution de la commande wc -l");
  exit(1);

  return 0;
}