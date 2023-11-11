#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void handleSIGCHLD(int signal) {
    int status;
    waitpid(-1, &status, WNOHANG); // prevenire le processus pere d'attendre ses fils d'une maniaire blockante
}

int main(int argc, char *argv[]) {
    signal(SIGCHLD, handleSIGCHLD);//definir SIGCHLD

    if (!fork()) { //si fils
        for (int i = 0; i < 10; i++) {
            // Simulate a small calculation
        }
        exit(1);
    }

    while (1) {
        // Simulate an infinite calculation
    }
}