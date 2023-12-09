#ifndef EXERCICE3_H
#define EXERCICE3_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
// Nom des fichiers utilisés pour générer les clés
#define FILE1 "client"
#define FILE2 "server"
#define PROJECT 1
// Structure du message
typedef struct
{
  long m_type;       // Type du message (PID du client dans ce cas)
  double num1, num2; // Deux nombres à additionner
  double result;     // Résultat de l'addition
} msg;

/**
 * handle_error - afficher le message d'erreur et quitter.
 * @msg: le message de l'erreur
 */
void handle_error(const char *msg)
{
  perror(msg);
  printf("\n");
  exit(EXIT_FAILURE);
}

#endif