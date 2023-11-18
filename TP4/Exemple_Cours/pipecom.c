#include <unistd.h> //pour fork, close…
#include <stdio.h>
#define R 0
#define W 1
int main(int argc, char *argv[])
{
    int fd[2];
    pipe(fd);          // creation d'un tube sans nom
    char message[100]; // pour récupérer un message
    int nboctets;
    char *phrase = " message envoyé au père par le fils";
    if (fork() != 0)
    {
        close(fd[R]);   // Le père ferme le descripteur non utilisé de lecture
        dup2(fd[W], 1); // copie fd[W] dans le descripteur 1)
        close(fd[W]);   // fermeture du descripteur d'écriture
        if (execlp(argv[1], argv[1], NULL) == -1)
            ; // exécute le programme écrivain
        perror("error dans execlp");
    }
    else // processus fils (lecteur)
    {
        // fermeture du descripteur non utilisé d'écriture
        close(fd[W]);
        // copie fd[R] dans le descripteur 0)
        dup2(fd[R], 0);
        close(fd[R]); // fermeture du descripteur de lecture
        // exécute le programme lecteur
        execlp(argv[2], argv[2], NULL);
        perror("connect");
    }
    return 0;
}