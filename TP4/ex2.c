#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    //definir les descripteurs
    int descripteurpsgrep[2];
    int descripteurgrepwc[2];

    // Création des tubes anonymes
    if (pipe(descripteurpsgrep) == -1 || pipe(descripteurgrepwc) == -1) {
        perror("Erreur lors de la création des tubes");
        exit(EXIT_FAILURE);
    }

    // Création du processus ps
    pid_t pid_ps = fork();

    if (pid_ps == -1) {
        perror("Erreur lors de la création du processus ps");
        exit(EXIT_FAILURE);
    }

    if (pid_ps == 0) {
        // Code du processus ps

        // Redirection de la sortie standard vers l'extrémité d'écriture du tube descripteurpsgrep
        dup2(descripteurpsgrep[1], STDOUT_FILENO);

        // Fermeture des descripteurs de fichier non nécessaires
        close(descripteurpsgrep[0]);
        close(descripteurpsgrep[1]);
        close(descripteurgrepwc[0]);
        close(descripteurgrepwc[1]);

        // Exécution de la commande "ps -uax"
        execlp("ps", "ps", "-uax", (char *)NULL);

        // En cas d'échec de execlp
        perror("Erreur lors de l'exécution de ps");
        exit(EXIT_FAILURE);
    }

    // Création du processus grep
    pid_t pid_grep = fork();

    if (pid_grep == -1) {
        perror("Erreur lors de la création du processus grep");
        exit(EXIT_FAILURE);
    }

    if (pid_grep == 0) {
        // Code du processus grep

        // Redirection de l'entrée standard depuis l'extrémité de lecture du tube descripteurpsgrep
        dup2(descripteurpsgrep[0], STDIN_FILENO);

        // Redirection de la sortie standard vers l'extrémité d'écriture du tube descripteurgrepwc
        dup2(descripteurgrepwc[1], STDOUT_FILENO);

        // Fermeture des descripteurs de fichier non nécessaires
        close(descripteurpsgrep[0]);
        close(descripteurpsgrep[1]);
        close(descripteurgrepwc[0]);
        close(descripteurgrepwc[1]);

        // Exécution de la commande "grep root"
        execlp("grep", "grep", "root", (char *)NULL);

        // En cas d'échec de execlp
        perror("Erreur lors de l'exécution de grep");
        exit(EXIT_FAILURE);
    }

    // Fermeture des descripteurs de fichier non nécessaires pour le processus parent
    close(descripteurpsgrep[0]);
    close(descripteurpsgrep[1]);

    // Création du processus wc
    pid_t pid_wc = fork();

    if (pid_wc == -1) {
        perror("Erreur lors de la création du processus wc");
        exit(EXIT_FAILURE);
    }

    if (pid_wc == 0) {
        // Code du processus wc

        // Redirection de l'entrée standard depuis l'extrémité de lecture du tube descripteurgrepwc
        dup2(descripteurgrepwc[0], STDIN_FILENO);

        // Fermeture des descripteurs de fichier non nécessaires
        close(descripteurgrepwc[0]);
        close(descripteurgrepwc[1]);
        close(descripteurpsgrep[0]);
        close(descripteurpsgrep[1]);

        // Exécution de la commande "wc -l"
        execlp("wc", "wc", "-l", (char *)NULL);

        // En cas d'échec de execlp
        perror("Erreur lors de l'exécution de wc");
        exit(EXIT_FAILURE);
    }

    // Fermeture des descripteurs de fichier non nécessaires pour le processus parent
    close(descripteurgrepwc[0]);
    close(descripteurgrepwc[1]);

    // Attente de la fin des trois processus fils
    waitpid(pid_ps, NULL, 0);
    waitpid(pid_grep, NULL, 0);
    waitpid(pid_wc, NULL, 0);

    return 0;
}
