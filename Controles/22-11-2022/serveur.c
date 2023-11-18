#include "Exercice4.h"

#define QUESTION "cli2serv"
#define REPONSE "serv2cli"

int main(int argc, char *argv[])
{
  int fdR, fdW;
  double num1, num2, result;
  char op;
  char req[MAX];

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
      handle_error("Erreur lors de la creation du premier tube!!\n");

    printf("Reception de la requette...\n");

    read(fdR, req, MAX);

    sscanf(req, "%lf %c %lf", &num1, &op, &num2);

    close(fdR);

    // Ouverture du second tube en lecture
    fdW = open(REPONSE, O_WRONLY);
    if (fdW == -1)
      handle_error("Erreur lors de la creation du second tube!!\n");
    
    result = calculate(num1, op, num2);

    printf("Envoi du resultat au client...\n");

    write(fdW, &result, sizeof(double));
    
    close(fdW);


  return 0;
}