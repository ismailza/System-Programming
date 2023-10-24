#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

void print_50(int);

/**
 * main - Créer deux processus fils, l'un affiche les entiers de 1 à 50, l'autre de 51 à 100.
 *
 * Return: Toujours 0.
 */
int main()
{
  if (!fork())      // Créer un premier fils.
    print_50(1);    // Afficher les 50 premiers nombres.
  else
  {
    wait(NULL);     // Attendre la fin du premier fils.
    if (!fork())    // Créer un deuxième fils.
      print_50(51); // Afficher les 50 nombres suivants.
  }
  return 0;
}

/**
 * print_50 - Affiche 50 nombres successifs à partir de @start.
 * @start: La valeur entière de départ.
 */
void print_50(int start)
{
  int end = start + 50;
  for (int i = start; i < end; i++)
    printf("%d ", i);
  printf("\n");
}
