//Affichage de lettres minuscules et majuscules avec deux threads
#include <stdio.h>
#include <pthread.h>

void *printLowercase(void *arg) {
    for (char c = 'a'; c <= 'z'; ++c) {
        printf("%c ", c);
    }
    return NULL;
}

void *printUppercase(void *arg) {
    for (char c = 'A'; c <= 'Z'; ++c) {
        printf("%c ", c);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, printLowercase, NULL);
    pthread_create(&thread2, NULL, printUppercase, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("\n");

    return 0;
}
