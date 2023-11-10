#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define _REENTRANT

// à appeler pour libérer l'espace alloué
void free(void *arg){
    int *a = (int *)arg;
    printf("ici free %d\n", *a);
    free(a);
}

// à appeler si pas de libération
void notfree(void *arg){
    if (arg == NULL) printf("ici notfree\n");
}

// la fonction des threads
void *mon_thread(void *allocate)
{
    int *block;
    if (*((int *)allocate))
    {
        block = (int *)malloc(sizeof(int));
        *block = 123;
        pthread_cleanup_push(free, (void *)block);
        printf("push free\n");
        pthread_cleanup_pop(1);
    }
    else
    {
        block = NULL;
        pthread_cleanup_push(notfree, (void *)block);
        printf("push not free\n");
        pthread_cleanup_pop(1);
    }
    sleep(3);
    printf("fin du thread\n");
    pthread_exit(0);
}

int main()
{
    int allocate = 1;
    pthread_t th;
    // Creation d'un thread qui effectuera le block du if
    if (pthread_create(&th, NULL, mon_thread, (void *)&allocate))
        perror("Erreur dans la creation du thread");
    sleep(1);
    pthread_cancel(th);
    allocate = 0;
    // Creation d'un thread qui executera le else du if
    if (pthread_create(&th, NULL, mon_thread, (void *)&allocate) != 0)
        perror("Erreur dans la creation du thread");
    sleep(1);
    pthread_cancel(th);
    printf("fin du main\n");
    return 0;
}