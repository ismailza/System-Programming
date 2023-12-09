#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

// Déclaration des fonctions des threads

void *print_lower_letters(void *);
void *print_upper_letters(void *);

/**
 * main - Fonction principale du programme qui lance deux threads. L'un affiche les 26 lettres minuscules, tandis que l'autre affiche les 26 lettres majuscules.
 *
 * Return: 0 en cas de succès.
 */
int main()
{
  // Identifiants des threads
  pthread_t tid1, tid2;

  // Création du premier thread pour afficher les lettres minuscules
  if (pthread_create(&tid1, NULL, print_lower_letters, NULL))
  {
    perror("Erreur lors de la creation du thread pour afficher les lettres minuscules!\n");
    exit(EXIT_FAILURE);
  }

  // Création du deuxième thread pour afficher les lettres majuscules
  if (pthread_create(&tid2, NULL, print_upper_letters, NULL))
  {
    perror("Erreur lors de la creation du thread pour afficher les lettres majuscules!\n");
    exit(EXIT_FAILURE);
  }

  // Attendre la fin des threads
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

  // Afficher une nouvelle ligne à la fin pour une sortie bien formatée
  printf("\n");

  return 0;
}

/**
 * print_lower_letters - Fonction du thread pour afficher les lettres minuscules.
 */
void *print_lower_letters(void *)
{
  // Boucle pour afficher les lettres minuscules de 'a' à 'z'
  for (char c = 'a'; c <= 'z'; c++)
    printf("%c ", c);

  // Indiquer la fin du thread
  pthread_exit(NULL);
}

/**
 * print_upper_letters - Fonction du thread pour afficher les lettres majuscules.
 */
void *print_upper_letters(void *)
{
  // Boucle pour afficher les lettres majuscules de 'A' à 'Z'
  for (char c = 'A'; c <= 'Z'; c++)
    printf("%c ", c);

  // Indiquer la fin du thread
  pthread_exit(NULL);
}
