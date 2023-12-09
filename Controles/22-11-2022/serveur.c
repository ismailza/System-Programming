#include "Exercice4.h"

#define QUESTION "cli2serv"
#define REPONSE "serv2cli"

int main()
{
  int fdR, fdW;
  double num1, num2;
  char op;
  char result[10], req[MAX];

  // Création du premier tube s'il n'existe pas
  if (access(QUESTION, F_OK) == -1)
    if (mkfifo(QUESTION, 0666) == -1)
      handle_error("Erreur lors de la creation du premier tube!\n");

  // Création du second tube s'il n'existe pas
  if (access(REPONSE, F_OK) == -1)
    if (mkfifo(REPONSE, 0666) == -1)
      handle_error("Erreur lors de la creation du second tube!\n");

  // Ouverture du premier tube en écriture
  fdR = open(QUESTION, O_RDONLY);
  if (fdR == -1)
    handle_error("Erreur lors de l'ouverture du premier tube!!\n");

  // Ouverture du second tube en lecture
  fdW = open(REPONSE, O_WRONLY);
  if (fdW == -1)
    handle_error("Erreur lors de l'ouverture du second tube!!\n");

  do
  {
    read(fdR, req, MAX);

    if (!strcmp(req, "bye"))
    {
      write(fdW, "ciao", 5);
      break;
    }

    sscanf(req, "%lf %c %lf", &num1, &op, &num2);

    sprintf(result, "%lf", calculate(num1, op, num2));

    printf("Serveur : Envoi du resultat au client...\n");
    write(fdW, &result, sizeof(result));
  } while (1);

  close(fdR);
  close(fdW);

  return 0;
}