#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int is_in_tab(int* tab, int length, int val) {
    int middle = length / 2;
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return -1;
    }

    if (pid == 0) {
        // Processus fils
        for (int i = middle; i < length; i++) {
            if (tab[i] == val) {
                return i;
            }
        }
        return -1;
    } else {
        // Processus père
        for (int i = 0; i < middle; i++) {
            if (tab[i] == val) {
                return i;
            }
        }

        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            int result = WEXITSTATUS(status);
            if (result != -1) {
                return result + middle;
            }
        }
    }
    return -1;
}

int main() {
    int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(tab) / sizeof(tab[0]);
    int val = 6;

    int position = is_in_tab(tab, length, val);

    if (position != -1) {
        printf("La valeur %d se trouve à la position %d dans le tableau.\n", val, position);
    } else {
        printf("La valeur %d n'a pas été trouvée dans le tableau.\n", val);
    }

    return 0;
}
