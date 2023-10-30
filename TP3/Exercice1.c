#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

void print_50(int);

/**
 * main - Créer deux processus fils, l'un affiche les entiers de 1 à 50, l'autre de 51 à 100.
 *
 * Return: Toujours 0.
 */
int main()
{
  pid_t pid;
  if ((pid = fork()) == -1) // Créer un processus fils et vérifier qu'il a bien été créé.
  {
    perror("Erreur lors de la creation du premier processus fils.");
    exit(-1);
  }
  else if (!pid)    // Si on est dans le processus fils.
    print_50(1);    // Afficher les 50 premiers nombres.
  else              // Si on est dans le processus père.
  {
    wait(NULL);     // Attendre la fin du premier fils.
    if ((pid = fork()) == -1) // Créer un deuxième processus fils et vérifier qu'il a bien été créé.
    {
      perror("Erreur lors de la creation du deuxieme processus fils.");
      exit(-1);
    }
    else if (!pid)  // Si on est dans le deuxième processus fils.
      print_50(51); // Afficher les 50 nombres suivants.
    else            // Si on est dans le processus père.
    {
      wait(NULL); // Attendre la fin du deuxième fils.
      printf("\n");
    }
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
}
