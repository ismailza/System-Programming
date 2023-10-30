#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Lancer la commande passée en argument de la ligne de commande.
 * @argc: Nombre d'arguments passés à la ligne de commande.
 * @argv: Arguments passés à la ligne de commande.
 * 
 * Return: Toujours 0.
*/
int main(int argc, char **argv)
{
  if (argc < 2)  // On vérifie qu'un seul argument a été passé à la ligne de commande.
  {
    printf("Il faut passer un seul argument à la ligne de commande.\n");
    exit(1);
  }
  // On lance la commande passée en argument de la ligne de commande.
  if (execvp(argv[1], argv + 1) == -1)
  {
    perror("Erreur lors de l'exécution de la commande");
    exit(1);
  }

  return 0;
}