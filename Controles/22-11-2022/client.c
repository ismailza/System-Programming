#include "Exercice4.h"

#define QUESTION "cli2serv"
#define REPONSE "serv2cli"

int main()
{
  int fdR, fdW;
  char result[10], req[MAX];

  // Ouverture du premier tube en écriture
  fdW = open(QUESTION, O_WRONLY);
  if (fdW == -1)
    handle_error("Erreur lors de l'ouverture du premier tube!\nVerifier que vous avez lancer le serveur!\n");

  // Ouverture du second tube en lecture
  fdR = open(REPONSE, O_RDONLY);
  if (fdR == -1)
    handle_error("Erreur lors de l'ouverture du premier tube!\nVerifier que vous avez lancer le serveur!\n");

  do
  {
    printf("Entrer votre operation (ex. a + b) : ");

    if (!gets(req))
      continue;

    printf("Client : Envoi de l'operation au serveur...\n");
    write(fdW, &req, sizeof(req));

    read(fdR, &result, sizeof(result));

    if (!strcmp(result, "ciao"))
    {
      printf("%s\n", result);
      break;
    }

    printf("Resultat de %s est : %.2f\n", req, atof(result));
    printf("--------------------------------------------------------\n");

  } while (1);

  close(fdW);
  close(fdR);

  return 0;
}