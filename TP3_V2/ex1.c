#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void print_numbers(int start, int end) {
    for (int i = start; i <= end; i++) {
        printf("%d ", i);

    }
}

int main() {
    int pid1, pid2;

    // Créer le premier fils
    if ((pid1 = fork()) == 0) {
        // Dans le fils 1, afficher les entiers de 1 à 50
        print_numbers(1, 50);
     
        exit(0);
    }
   
    // Créer le deuxième fils
    if ((pid2 = fork()) == 0) {
        // Dans le fils 2, afficher les entiers de 51 à 100
        print_numbers(51, 100);
     

        exit(0);
    }

    // Attendre que les deux fils se terminent
      waitpid(pid1, NULL, 0);
      waitpid(pid2, NULL, 0);
   
    printf("\n");

    return 0;
}
