#include "Exercice4.h"

#define TUBE1 "cli2serv"
#define TUBE2 "serv2cli"

int main(int argc, char *argv[])
{
  int fdR, fdW;
  double num1, num2, result;

  // Création du premier tube s'il n'existe pas
  if (access(TUBE1, F_OK) == -1)
    if (mkfifo(TUBE1, 0666) == -1)
      handle_error("Erreur lors de la creation du premier tube!\n");

  // Ouverture du premier tube en écriture
  fdR = open(TUBE1, O_RDONLY);
  if (fdR == -1)
    handle_error("Erreur lors de la creation du premier tube!!\n");

  read(fdR, &num1, sizeof(num1));
  read(fdR, &num2, sizeof(num2));

  close(fdR);

  result = num1 + num2;

  // Création du second tube s'il n'existe pas
  if (access(TUBE2, F_OK) == -1)
    if (mkfifo(TUBE2, 0666) == -1)
      handle_error("Erreur lors de la creation du second tube!\n");

  // Ouverture du second tube en lecture
  fdW = open(TUBE2, O_WRONLY);
  if (fdW == -1)
    handle_error("Erreur lors de la creation du second tube!!\n");
  
  printf("Envoi du resultat au client...\n");

  write(fdW, &result, sizeof(double));
  
  close(fdW);

  return 0;
}