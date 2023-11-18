#include "Exercice3.h"

int isnumber(const char *);

/**
 * main - Fonction principale du client.
 * @param argc: Nombre d'arguments passés en ligne de commande
 * @param argv: Tableau d'arguments passés en ligne de commande
 *
 * Return: 0 en cas du succès.
 */
int main(int argc, char *argv[])
{
  int f_request, f_response;         // Descripteurs des files de messages
  key_t clef_request, clef_response; // Clés pour accéder aux files de messages
  msg message;                       // Structure pour le message

  // Vérifie le nombre d'arguments
  if (argc != 3)
    handle_error("Il faut specifier 2 nombres");
  // Vérifie que les arguments sont des nombres
  if (!isnumber(argv[1]) || !isnumber(argv[2]))
    handle_error("Erreur, il faut que les arguments soient des nombres");
  // Obtient la clé de la file de requêtes
  if ((clef_request = ftok(FILE1, PROJECT)) == -1)
    handle_error("Erreur lors de l'obtention de la cle de la requette!");
  // Obtient la clé de la file de réponses
  if ((clef_response = ftok(FILE2, PROJECT)) == -1)
    handle_error("Erreur lors de l'obtention de la cle de la requette!");
  // Obtient ou crée la file de requêtes
  if ((f_request = msgget(clef_request, 0700 | IPC_CREAT)) == -1)
    handle_error("msgget request error");
  // Obtient ou crée la file de réponses
  if ((f_response = msgget(clef_response, 0700 | IPC_CREAT)) == -1)
    handle_error("msgget response error");
  // Prépare le message à envoyer
  message.m_type = getpid();
  message.num1 = atof(argv[1]);
  message.num2 = atof(argv[2]);
  // Envoie le message à la file de requêtes
  if (msgsnd(f_request, &message, sizeof(message), 0) == -1)
    handle_error("Erreur lors de l'envoi de la requette!");
  // Attend la réponse dans la file de réponses
  if (msgrcv(f_response, &message, sizeof(message), getpid(), 0) == -1)
    handle_error("Erreur lors de la reception de la reponse!");
  // Affiche le résultat
  printf("Le resultat de %.2f + %.2f est : %.2f\n", message.num1, message.num2, message.result);

  return 0;
}

/**
 * isnumber - Vérifie si une chaîne de caractères représente un nombre.
 * @num: Chaîne de caractères à vérifier.
 *
 * Return: 1 si @num est un nombre, 0 sinon.
 */
int isnumber(const char *num)
{
  char *endptr;
  // Convertir la chaîne en un nombre à virgule flottante (double).
  strtod(num, &endptr);
  // Vérifie si le pointeur de fin pointe à la fin de la chaîne et que la chaîne n'est pas vide
  return (*endptr == '\0' || isspace((unsigned char)*endptr)) && (endptr != num);
}