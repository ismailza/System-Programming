#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Variable globale
int glob = 0;
// Mutex pour assurer une opération atomique sur la variable globale
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Prototypes

void *increment_by(void *);
int isnum(char *);

/**
 * main - Fonction principale du programme qui crée deux threads, chacun incrémentant la variable un nombre spécifié de fois,
 *        puis affiche la valeur finale de la variable après l'exécution de chaque thread.
 *
 * Return: 0 en cas de succès.
 */
int main(int argc, char *argv[])
{
  pthread_t tid1, tid2;
  // Vérification du nombre d'arguments
  if (argc != 2)
  {
    perror("Il faut un seul argument entier!\n");
    exit(EXIT_FAILURE);
  }
  // Vérification si l'argument est un nombre
  if (!isnum(argv[1]))
  {
    perror("L'argument doit etre un entier!\n");
    exit(EXIT_FAILURE);
  }
  // Conversion de l'argument en un nombre entier
  int N = atoi(argv[1]);
  // Création du premier thread
  if (pthread_create(&tid1, NULL, increment_by, (void *)&N))
  {
    perror("Erreur lors de la creation de premier thread!\n");
    exit(EXIT_FAILURE);
  }
  // Création du deuxième thread
  if (pthread_create(&tid2, NULL, increment_by, (void *)&N))
  {
    perror("Erreur lors de la creation de deuxieme thread!\n");
    exit(EXIT_FAILURE);
  }
  // Attente de la fin des threads
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  // Affichage du résultat
  printf("%d\n", glob);

  return 0;
}

/**
 * increment_by - Fonction exécutée par les threads pour incrémenter une variable globale.
 * @n: Pointeur vers le nombre d'itérations d'incrémentation.
 */
void *increment_by(void *n)
{
  int *N = (int *)n;
  for (int i = 0; i < *N; i++)
  {
    // Verrouillage du mutex pour assurer une opération atomique
    pthread_mutex_lock(&mutex);
    glob++;
    // Déverrouillage du mutex après l'incrémentation
    pthread_mutex_unlock(&mutex);
  }

  pthread_exit(NULL);
}

/**
 * isnum - Vérifie si une chaîne de caractères est composée de chiffres.
 * @chaine: Chaîne de caractères à vérifier.
 *
 * Return: 1 si la chaîne est un nombre, 0 sinon.
 */
int isnum(char *chaine)
{
  int size = strlen(chaine);
  for (int i = 0; i < size; i++)
    if (!isdigit(chaine[i]))
      return 0;
  return 1;
}