// Écriture de nombres dans un fichier avec deux threads
#include <stdio.h>
#include <pthread.h>

FILE *file;

void *writeNumbers(void *arg) {
    int start = *((int *)arg);
    for (int i = start; i < start + 100000; ++i) {
        fprintf(file, "%d\n", i);
    }
    return NULL;
}

int main() {
    file = fopen("numbers.txt", "w");

    pthread_t thread1, thread2;
    int start1 = 0;
    int start2 = 1000000;

    pthread_create(&thread1, NULL, writeNumbers, &start1);
    pthread_create(&thread2, NULL, writeNumbers, &start2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    fclose(file);

    

    return 0;
}