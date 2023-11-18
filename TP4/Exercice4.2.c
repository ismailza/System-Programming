#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "Exercice4.2"

// Structure pour stocker les données à passer aux threads
typedef struct
{
  FILE *file;
  int start;
} data;

// Prototypes

void *print_100k_numbers_from(void *);
FILE *open_file(char *, char *);

/**
 * main - Fonction principale du programme qui ouvre un fichier en écriture,
 *        crée deux threads pour écrire des nombres dans le fichier, les attend,
 *        ferme le fichier, puis consulte le fichier ainsi créé.
 *
 * Return: 0 en cas de succès.
 */
int main()
{
  pthread_t tid1, tid2; // Identifiants des threads.
  // Ouvrir le fichier en mode écriture ("w") pour le créer ou le vider.
  FILE *file = open_file(FILE_NAME, "w");
  data data1 = {file, 0};       // Paramètres pour le premier thread
  data data2 = {file, 1000000}; // Paramètres pour le deuxième thread

  // Créer le premier thread pour écrire les nombres de 0 à 100000.
  if (pthread_create(&tid1, NULL, print_100k_numbers_from, (void *)&data1))
  {
    perror("Error");
    exit(EXIT_FAILURE);
  }

  // Créer le deuxième thread pour écrire les nombres de 1000000 à 1100000.
  if (pthread_create(&tid2, NULL, print_100k_numbers_from, (void *)&data2))
  {
    perror("Error");
    exit(EXIT_FAILURE);
  }

  // Attendre la fin des threads
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

  // Fermer le fichier
  fclose(file);

  // Ouvrir le fichier en mode lecture pour afficher son contenu
  file = open_file(FILE_NAME, "r");
  int num;
  printf("Contenu du fichier :\n");
  while (fscanf(file, "%d ", &num) != EOF)
    printf("%d ", num);
  fclose(file);

  return 0;
}

/**
 * print_100k_numbers_from - Fonction exécutée par les threads pour écrire 100k nombres dans un fichier.
 * @args: Structure contenant les paramètres du thread.
 */
void *print_100k_numbers_from(void *args)
{
  data *data1 = (data *)args;
  int end = data1->start + 100000;

  for (int i = 0; i <= end; i++)
    fprintf(data1->file, "%d ", i);

  pthread_exit(NULL);
}

/**
 * open_file - Ouvre un fichier avec un mode spécifié.
 * @file_name: Nom du fichier à ouvrir.
 * @mode: Mode d'ouverture du fichier.
 *
 * Return: Pointeur vers le fichier ouvert.
 */
FILE *open_file(char *file_name, char *mode)
{
  FILE *file = fopen(file_name, mode);
  if (!file)
  {
    printf("Erreur lors de l'ouverture du fichier");
    exit(EXIT_FAILURE);
  }
  return file;
}