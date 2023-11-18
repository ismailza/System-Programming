#include "Exercice4.h"

#define QUESTION "cli2serv"
#define REPONSE "serv2cli"

int main(int argc, char *argv[])
{
  if (argc != 4)
    handle_error("Erreur, nombre d'arguments est incorrect!\n");
  
  if (!is_number(argv[1]) || !is_number(argv[3]))
    handle_error("Erreur, il faut que les arguments soient des nombres!\n");
  
  char op = is_operator(argv[2]);
  int fdR, fdW;
  double num1, num2, result;
  char req[MAX];

  
    // Ouverture du premier tube en écriture
    fdW = open(QUESTION, O_WRONLY);
    if (fdW == -1)
      handle_error("Erreur lors de la creation du premier tube!!\n");
    
    // printf("Entrer votre operation (ex. a + b) : ");

    // scanf("%lf %c %lf", &num1, &op, &num2);

    num1 = atof(argv[1]);
    num2 = atof(argv[3]);

    sprintf(req, "%lf %c %lf", num1, op, num2);
    
    printf("Envoi de l'operation au serveur...\n");

    write(fdW, &req, sizeof(req));

    close(fdW);
    
    // Ouverture du second tube en lecture
    fdR = open(REPONSE, O_RDONLY);
    if (fdR == -1)
      handle_error("Erreur lors de la creation du second tube!!\n");

    printf("Reception du resultat...\n");
    
    read(fdR, &result, sizeof(double));
    
    close(fdR);
    
    printf("Resultat de %.2f %c %.2f est : %.2f\n", num1, op, num2, result);

    printf("\n");
    
  

  return 0;
}