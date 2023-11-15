#include <unistd.h>
#include "Exercice2.h"

int main(int argc, char *argv[])
{
  if (argc != 4)
    handle_error("Erreur, nombre d'arguments est incorrect!!\n");
  
  if (!strcmp(argv[2], "+"))
    if (execlp("./plus", "plus", argv[1], argv[3], NULL) == -1)
      handle_error("Erreur lors de l'execution d'une operation\n");
  if (!strcmp(argv[2], "-"))
    if (execlp("./moins", "moins", argv[1], argv[3], NULL) == -1)
      handle_error("Erreur lors de l'execution d'une operation\n");
  if (!strcmp(argv[2], "*"))
    if (execlp("./fois", "fois", argv[1], argv[3], NULL) == -1)
      handle_error("Erreur lors de l'execution d'une operation\n");
  if (!strcmp(argv[2], "/"))
    if (execlp("./div", "div", argv[1], argv[3], NULL) == -1)
      handle_error("Erreur lors de l'execution d'une operation\n");
  if (!strcmp(argv[2], "%"))
    if (execlp("./mod", "mod", argv[1], argv[3], NULL) == -1)
      handle_error("Erreur lors de l'execution d'une operation\n");
  handle_error("Erreur, operateur inconnu!\n");

  return 0;
}