#include <unistd.h> //pour sleep
#include <pthread.h>
#include <stdio.h>

int glob = 0;

void *decrement(void *x)
{
    int dec = 1;
    sleep(1);
    glob = glob - dec;
    printf("ici decrement[%ld], glob = %d\n", pthread_self(), glob);
    pthread_exit(NULL);
}

void *increment(void *x)
{
    int inc = 2;
    sleep(10);
    glob = glob + inc;
    printf("ici increment[%ld], glob = %d\n", pthread_self(), glob);
    pthread_exit(NULL);
}

int main()
{
    pthread_t tid1, tid2;
    printf("ici main[%d], glob = %d\n", getpid(), glob);
    // creation d'un thread pour increment
    if (pthread_create(&tid1, NULL, increment, NULL) != 0)
        return -1; 
    printf("ici main: creation du thread[%ld] avec succes\n", tid1);
    // creation d'un thread pour decrement
    if (pthread_create(&tid2, NULL, decrement, NULL) != 0)
        return -1;
    printf("ici main: creation du thread [%ld] avec succes\n", tid2);
    // attendre la fin des threads
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("ici main : fin des threads, glob = %d \n", glob);
    return 0;
}