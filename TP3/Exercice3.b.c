#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

// Prototypes

int is_in_tab(int *, int, int);

/**
 * main - Créer un processus fils et vérifie si une valeur se trouve dans un tableau.
 * 
 * Return: Toujours 0.
*/
int main()
{
  pid_t pid;
  int tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int length = 10;
  int val, pos, status;
  printf("\nEntrer une valeur à chercher dans le tableau: ");
  scanf("%d", &val);
  if ((pid = fork()) == -1) // Créer un processus fils et vérifier qu'il a bien été créé.
  {
    perror("Erreur lors de la creation du processus fils.");
    exit(-1);
  }
  else if(pid)  // On est dans le processus père.
  {
    pos = is_in_tab(tab, (int)(length / 2), val);
    wait(&status);  // On attend la fin du processus fils.
    if (pos != -1) // On vérifie si la valeur se trouve dans la première moitié du tableau.
      printf("La valeur %d se trouve dans le tableau à la position %d.\n", val, pos);
    else if ((pos = WEXITSTATUS(status)) != 255) // On vérifie si la valeur se trouve dans la deuxième moitié du tableau.
      printf("La valeur %d se trouve dans le tableau à la position %d.\n", val, (pos + (int)(length / 2)));
    else  // La valeur ne se trouve pas dans le tableau.
      printf("La valeur %d ne se trouve pas dans le tableau.\n", val);
  }
  else  // On est dans le processus fils.
    exit(is_in_tab(tab + (int)(length / 2), (int)(length / 2), val));
  return 0;
}

/**
 * is_in_tab - Vérifie si une valeur se trouve dans un tableau.
 * @tab: Le tableau dans lequel chercher.
 * @length: La longueur du tableau.
 * @val: La valeur à chercher.
 * 
 * Return: la position de la valeur dans le tableau si elle s'y trouve, -1 sinon.
*/
int is_in_tab(int *tab, int length, int val)
{
  for (int i = 0; i < length; i++)
    if (tab[i] == val)
      return i;
  return -1;
}