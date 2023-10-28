#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Utilisation : %s <nom_du_fichier>\n", argv[0]);
        return 1;
    }

    char command[100];  // Une chaîne de caractères pour stocker la commande

    // Utiliser snprintf pour construire la commande avec le nom du fichier
    snprintf(command, sizeof(command), "cat %s", argv[1]);

    // Utiliser la fonction system() pour exécuter la commande
    int status = system(command);

    if (status == -1) {
        perror("system");
        return 1;
    }

    return 0;
}