#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Nous sommes dans le processus fils
        execl("/bin/ps", "ps", "-l", NULL);

        // En cas d'échec de execl
        perror("execl");
        exit(1);
    } else {
        // Nous sommes dans le processus père
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            printf("Code de retour de ps : %d\n", exit_status);
        }
    }

    return 0;
}