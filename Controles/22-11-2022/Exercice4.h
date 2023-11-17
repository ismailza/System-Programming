#ifndef EXERCICE4_H
#define EXERCICE4_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>


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
 * is_number - Vérifie si une chaîne de caractères représente un nombre.
 * @chaine: Chaîne de caractères à vérifier.
 *
 * Return: 1 si @chaine est un nombre, 0 sinon.
 */
int is_number(const char *chaine)
{
  char *endptr;
  // Convertir la chaîne en un nombre à virgule flottante (double).
  strtod(chaine, &endptr);
  // Vérifie si le pointeur de fin pointe à la fin de la chaîne et que la chaîne n'est pas vide
  return (*endptr == '\0' || isspace((unsigned char)*endptr)) && (endptr != chaine);
}

#endif // EXERCICE4_H