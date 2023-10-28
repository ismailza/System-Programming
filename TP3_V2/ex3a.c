#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Nous sommes dans le processus fils
        // on  Génére un nombre aléatoire entre 0 et 100 on utilise time pour s'assurer d'avoir des nombres differents
        srand(time(NULL));
        int random_number = rand() % 101;
        // Retourner le nombre comme code de retour du fils
        exit(random_number);
    } else {
        // Nous sommes dans le processus père
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            // Vérifier si le fils s'est terminé normalement
            int child_exit_status = WEXITSTATUS(status);//terminaison normal donc retourner code de retour
            printf("Le fils a retourné le code : %d\n", child_exit_status);
        }
    }

    return 0;
}