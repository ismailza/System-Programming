#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int compteur = 0;

void *MyCode(void *);

int main()
{
  pthread_t tid1, tid2, tid3;
  
  // Création des trois threads
  pthread_create(&tid1, NULL, MyCode, NULL);
  pthread_create(&tid2, NULL, MyCode, NULL);
  pthread_create(&tid3, NULL, MyCode, NULL);

  // Attendre la fin des trois threads
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  pthread_join(tid3, NULL);

  printf("La valeur du compteur : %d\n", compteur);

  return 0;
}

void *MyCode(void *args)
{
  // Traitement local
  // ...

  // Incrémentation du compteur
  compteur++;

  pthread_exit(NULL);
}