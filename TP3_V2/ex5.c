#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid_ls, pid_ps;
    int status;

    // Créer le processus pour la commande "ls -l"
    pid_ls = fork();

    if (pid_ls == -1) {
        perror("fork");
        return 1;
    }

    if (pid_ls == 0) {
        // Nous sommes dans le processus fils pour "ls -l"
        execl("/bin/ls", "ls", "-l", NULL);
        perror("execl");
        exit(1);
    }

    // Créer le processus pour la commande "ps -l"
    pid_ps = fork();

    if (pid_ps == -1) {
        perror("fork");
        return 1;
    }

    if (pid_ps == 0) {
        // Nous sommes dans le processus fils pour "ps -l"
        execl("/bin/ps", "ps", "-l", NULL);
        perror("execl");
        exit(1);
    }

    // Nous sommes dans le processus père
    int first_terminated;

    // Attendre la fin des deux fils
    pid_t first_pid = wait(&status);

    if (first_pid == pid_ls) {
        printf("Le processus ls -l s'est terminé en premier.\n");
        first_terminated = 1;
    } else if (first_pid == pid_ps) {
        printf("Le processus ps -l s'est terminé en premier.\n");
        first_terminated = 2;
    }

    // Attendre le second fils
    pid_t second_pid = wait(&status);

    // Afficher le résultat pour le second fils
    if (first_terminated == 1 && second_pid == pid_ps) {
        printf("Le processus ps -l s'est terminé en second.\n");
    } else if (first_terminated == 2 && second_pid == pid_ls) {
        printf("Le processus ls -l s'est terminé en second.\n");
    }

    return 0;
}