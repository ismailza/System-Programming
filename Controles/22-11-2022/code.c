#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int is_number(char *);

void main(int argc, char *argv[])
{
  if (argc != 2)
  {
    perror("Erreur, nombre d'arguments est incorrect!\n");
    exit(1);
  }
  if (!is_number(argv[1]))
  {
    perror("Erreur, l'argument fourni doit etre un entier!\n");
    exit(1);
  }

  printf("PID : %d", getpid());

  exit(atoi(argv[1]));
}

/**
 * is_number - Vérifie si une chaine est un nombre entier
 * @chaine: La chaine à vérifier
 * 
 * Return: 1 si la chaine est un entier, 0 sinon.
*/
int is_number(char *chaine)
{
  int size = strlen(chaine);
  for (int i = 0; i < size; i++)
    if (!isdigit(chaine[i])) return 0;
  return 1;
}