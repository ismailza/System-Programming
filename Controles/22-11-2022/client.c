#include "Exercice4.h"

#define TUBE1 "cli2serv"
#define TUBE2 "serv2cli"

int main(int argc, char *argv[])
{
  if (argc != 3)
    handle_error("Erreur, nombre d'arguments est incorrect!\n");
  
  if (!is_number(argv[1]) || !is_number(argv[2]))
    handle_error("Erreur, il faut que les arguments soient des nombres!\n");
  
  int fdR, fdW;
  double num1, num2, result;

  // Création du premier tube s'il n'existe pas
  if (access(TUBE1, F_OK) == -1)
    if (mkfifo(TUBE1, 0666) == -1)
      handle_error("Erreur lors de la creation du premier tube!\n");

  // Ouverture du premier tube en écriture
  fdW = open(TUBE1, O_WRONLY);
  if (fdW == -1)
    handle_error("Erreur lors de la creation du premier tube!!\n");

  num1 = atof(argv[1]);
  num2 = atof(argv[2]);

  printf("Envoi de la requette au serveur...\n");

  write(fdW, &num1, sizeof(num1));
  write(fdW, &num2, sizeof(num2));

  close(fdW);

  // Création du second tube s'il n'existe pas
  if (access(TUBE2, F_OK) == -1)
    if (mkfifo(TUBE2, 0666) == -1)
      handle_error("Erreur lors de la creation du second tube!\n");

  // Ouverture du second tube en lecture
  fdR = open(TUBE2, O_RDONLY);
  if (fdR == -1)
    handle_error("Erreur lors de la creation du second tube!!\n");
  
  printf("Reception du resultat...\n");
  read(fdR, &result, sizeof(double));
  
  close(fdR);

  printf("Resultat de %.2f + %.2f est : %.2f\n", num1, num2, result);

  return 0;
}