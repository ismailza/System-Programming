#ifndef EXERCICE2_H
#define EXERCICE2_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * handle_error - Affiche un message d'erreur et quitte
 * @msg: Le message à afficher
*/
void handle_error(char *msg)
{
  perror(msg);
  exit(EXIT_FAILURE);
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

#endif