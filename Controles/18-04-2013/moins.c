#include "Exercice2.h"

int main(int argc, char *argv[])
{
  if (argc != 3)
    handle_error("Erreur, nombre d'arguments est incorrect!!\n");
  
  if (!is_number(argv[1]) || !is_number(argv[2]))
    handle_error("Erreur, les arguments doivent etre des entiers!\n");

  printf("%d\n", atoi(argv[1]) - atoi(argv[2]));

  return 0;
}