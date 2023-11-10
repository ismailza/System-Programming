#include "Exercice3.h"

/**
 * main - Fonction principale du serveur
 *
 * Return: 0 en cas du succès.
 */
int main()
{
  int f_request, f_response;         // Descripteurs des files de messages
  key_t clef_request, clef_response; // Clés pour accéder aux files de messages
  msg message;                       // Structure pour le message

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

  printf("En attente d'une requête... \n");

  // Attend une requête dans la file de requêtes
  if (msgrcv(f_request, &message, sizeof(message), 0, 0) == -1)
    handle_error("Erreur lors de la reception de la requette au niveau de serveur!");

  // Calcule la réponse
  message.result = message.num1 + message.num2;

  // Envoie la réponse à la file de réponses
  if (msgsnd(f_response, &message, sizeof(message), 0) == -1)
    handle_error("Erreur lors de l'envoi de la reponse!");

  return 0;
}