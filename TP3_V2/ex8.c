#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    // Créer un tableau pour stocker les commandes
    char* commands[] = {"who", "ps", "ls -l"};

    int num_commands = sizeof(commands) / sizeof(commands[0]);

    for (int i = 0; i < num_commands; i++) {
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(1);
        }

        if (pid == 0) {
            // Nous sommes dans le processus enfant
            printf("Exécution de la commande %s\n", commands[i]);
            execl("/bin/sh", "sh", "-c", commands[i], NULL);
            perror("execl");
            exit(1);
        }
    }

    // Attendre la fin de tous les processus enfants
    for (int i = 0; i < num_commands; i++) {
        int status;
        wait(&status);
    }

    return 0;
}