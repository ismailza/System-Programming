#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 256

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("monshell> ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }

        // Supprimer le saut de ligne à la fin de la commande
        size_t length = strlen(command);
        if (length > 0 && command[length - 1] == '\n') {
            command[length - 1] = '\0';
        }

        if (strcmp(command, "exit") == 0) {
            // Quitter le shell
            break;
        } else {
            pid_t pid = fork();

            if (pid == -1) {
                perror("fork");
                return 1;
            }

            if (pid == 0) {
                // Processus fils
                execl("/bin/sh", "sh", "-c", command, NULL);
                perror("execl");
                exit(1);
            } else {
                // Processus parent
                int status;
                wait(&status);
            }
        }
    }

    return 0;
}