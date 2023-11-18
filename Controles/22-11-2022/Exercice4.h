#ifndef EXERCICE4_H
#define EXERCICE4_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

#define MAX 25

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

char is_operator(const char *chaine)
{
  if (strlen(chaine) == 1)
    if ((chaine[0] == '+') || (chaine[0] == '-') || (chaine[0] == '*') || (chaine[0] == '/'))
      return chaine[0];
  handle_error("Operateur inconnu!!\n");
}

/**
 * calculate - Effectuer le calcule d'une opération arithmétique.
 * @num1: Le premier opérande
 * @op: l'opérateur
 * @num2: Le second opérande
 * 
 * Return: Le résultat de l'opération.
*/
double calculate(double num1, char op, double num2)
{
  switch (op)
  {
    case '+':
      return num1 + num2;
    case '-':
      return num1 - num2;
    case '*':
      return num1 * num2;
    case '/':
      if (num2 == 0)
        handle_error("Erreur: Division par 0!\n");
      return num1 / num2;
    default:
      break;
  }
  return -1;
}

#endif // EXERCICE4_H