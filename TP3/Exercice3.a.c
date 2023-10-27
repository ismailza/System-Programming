#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Créer un processus fils qui choisit un nombre aléatoire entre 0 et 100 et le retourne au père pour qu'il l'affiche.
 * 
 * Return: Toujours 0.
*/
int main()
{
  int status; // Variable qui contiendra le code de retour du fils.
  pid_t pid;  // Variable qui contiendra l'identifiant du processus fils.
  if ((pid = fork()) == -1) // Créer un processus fils et vérifier qu'il a bien été créé.
  {
    perror("Erreur lors de la creation du processus fils.");
    exit(-1);
  }
  else if (!pid)  // On est dans le processus fils.
  {
    srand(time(NULL));  // Initialiser le générateur de nombres aléatoires.
    exit(rand() % 101); // Quitter le processus fils en retournant un nombre aléatoire entre 0 et 100.
  }
  else          // On est dans le processus père.
  {
    wait(&status);  // Attendre la fin du fils et récupérer son code de retour.
    printf("%d\n", WEXITSTATUS(status));  // Afficher le code de retour du fils.
  }
  return 0;
}