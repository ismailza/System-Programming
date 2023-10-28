#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

//erreur de creation du processus
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Nous sommes dans le processus fils
        printf("Processus Fils:\n");
    } else {
        // Nous sommes dans le processus père
        printf("Processus Père:\n");
    }

    // les informations du processus actuel
    printf("PID : %d\n", getpid());
    printf("PPID : %d\n", getppid());
    printf("UID réel : %d\n", getuid());
    printf("UID effectif : %d\n", geteuid());
    printf("GID réel : %d\n", getgid());
    printf("GID effectif : %d\n", getegid());

    return 0;
}