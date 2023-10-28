#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Utilisation : %s <commande>\n", argv[0]);
        return 1;
    }

    char *command = argv[1];

    int status = system(command);

    if (status == -1) {
        perror("system");
        return 1;
    }

    return 0;
}