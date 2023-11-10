#include <pthread.h>
#include <stdio.h>

int compteur[3];
/* fonction executee par chaque thread */
void *fonc_thread(void *k)
{
    printf("Thread numero %d : mon tid est %ld\n ", (int)k, pthread_self());
    for (;;)
        compteur[(int)k]++;
}
main()
{
    int i, num;
    pthread_t pth_id[3];
    /* creation des threads */
    for (num = 0; num < 3; num++)
    {
        pthread_create(pth_id + num, 0, fonc_thread, (void *)num);
        printf("Main: thread numero %d creee : id = %ld\n ", num, pth_id[num]);
    }
    usleep(10000); /* attente de 10 ms */
    printf("Affichage des compteurs\n");
    for (i = 0; i < 20; i++)
    {
        printf("%d \t%d \t%d\n", compteur[0], compteur[1], compteur[2]);
        usleep(1000);
        /* attente de 1 ms entre 2 affichages */
    }
    return 0;
}