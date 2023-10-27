#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Ouvrir avec la commande cat un fichier dont le nom est passé en argument 
 *       de la ligne de commande en utilisant la fonction system().
 * @argc: Nombre d'arguments passés à la ligne de commande.
 * @argv: Arguments passés à la ligne de commande.
 * 
 * Return: Toujours 0.
*/
int main(int argc, char **argv)
{
  if (argc != 2)  // On vérifie qu'un seul argument a été passé à la ligne de commande.
  {
    printf("Il faut passer un seul argument à la ligne de commande.\n");
    exit(1);
  }

  printf("Ouverture du fichier %s avec la commande cat.\n", argv[1]);
  // On alloue la mémoire nécessaire pour stocker la commande.
  char *commande = malloc(sizeof(char) * (strlen("cat ") + strlen(argv[1]) + 1));
  strcpy(commande, "cat ");
  // On concatène la commande avec le nom du fichier et on l'exécute.
  system(strcat(commande, argv[1]));

  return 0;
}