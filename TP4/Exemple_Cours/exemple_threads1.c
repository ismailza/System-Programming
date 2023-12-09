#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void afficher(int n, char lettre)
{
    int i, j;
    for (j = 1; j < n; j++)
    {
        for (i = 1; i < 10000000; i++)
            ;
        printf("%c", lettre);
        fflush(stdout);
    }
}
void *threadA(void *inutilise)
{
    afficher(100, 'A');
    printf("\n Fin du thread A\n");
    fflush(stdout);
    pthread_exit(NULL);
}

void *threadC(void *inutilise)
{
    afficher(150, 'C');
    printf("\n Fin du thread C\n");
    fflush(stdout);
    pthread_exit(NULL);
}
void *threadB(void *inutilise)
{
    pthread_t thC;
    pthread_create(&thC, NULL, threadC, NULL);
    afficher(100, 'B');
    printf("\n Le thread B attend la fin du thread C\n");
    pthread_join(thC, NULL);
    printf("\n Fin du thread B\n");
    fflush(stdout);
    pthread_exit(NULL);
}

int main()
{
    int i;
    pthread_t thA, thB;
    printf("Creation du thread ");
    pthread_create(&thA, NULL, threadA, NULL);
    pthread_create(&thB, NULL, threadB, NULL);
    sleep(1);
    // attendre que les threads aient termine
    printf("\nLe thread principal attend que les autres se terminent\n");
    pthread_join(thA, NULL);
    pthread_join(thB, NULL);
    return 0;
}