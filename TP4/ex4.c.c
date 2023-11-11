//Incrémentation d'une variable globale avec deux threads
#include <stdio.h>
#include <pthread.h>

#define N 100000

int variableglobale = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//pour gerer l'acces a cette variable et non pas avoir des resultsts impresible on utilise mutex
void *incrementVariable(void *arg) {
    for (int i = 0; i < N; ++i) {
        pthread_mutex_lock(&mutex);
        variableglobale++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, incrementVariable, NULL);
    pthread_create(&thread2, NULL, incrementVariable, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Valeur finale de la variable globale : %d\n", variableglobale);

    return 0;
}

/*REMARQUE:
 Lorsqu'on incrémente une variable partagée entre plusieurs threads sans protection,
 des conditions de course peuvent survenir, entraînant des résultats imprévisibles.
 Dans ce programme, on utilise le verrouillage (`pthread_mutex_lock` et `pthread_mutex_unlock`) 
 pour éviter ces conditions de course. 
 Cependant, à mesure que N (le nombre d'itérations de l'incrémentation) augmente,
 le verrou peut devenir un goulot d'étranglement, ralentissant les performances et entraînant un résultat
 inférieur à 2xN en raison du temps passé à attendre le verrou.


*/