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
        char* args[] = {"ps", "-l", NULL};
        execv("/bin/ps", args);

        // En cas d'échec de execv
        perror("execv");
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