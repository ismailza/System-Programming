#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct
{
    int x, y;
} data;

/* fonction executee par chaque thread */
void *mul(data *ptrdata)
{
    pthread_exit((void *)((ptrdata->x) * (ptrdata->y)));
}
void main(int argc, char *argv[])
{
    int i;
    int a, b, c, d;
    pthread_t pth_id[2];
    data donnees1;
    data donnees2;
    int res1, res2;
    if (argc < 5)
    {
        perror("\007Nbre d'arguments incorrect");
        exit(1);
    }
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    c = atoi(argv[3]);
    d = atoi(argv[4]);
    donnees1.x = a;
    donnees1.y = b;
    donnees2.x = c;
    donnees2.y = d;
    /* creation des threads */
    pthread_create(pth_id, 0, (void *(*)())mul, &donnees1);
    pthread_create(pth_id + 1, 0, (void *(*)())mul, &donnees2);
    /* Attente de la fin de la thread 1 */
    pthread_join(pth_id[0], (void **)&res1);
    /* Attente de la fin de la thread 2 */
    pthread_join(pth_id[1], (void **)&res2);
    /* Affichage du resultat a*b + c*d */
    printf("Resultat =%d\n", res1 + res2);
    /* Suppression des ressources des threads */
    pthread_detach(&pth_id[0]);
    pthread_detach(&pth_id[1]);
    
    exit(0);
}