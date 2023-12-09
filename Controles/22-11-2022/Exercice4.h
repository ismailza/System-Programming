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