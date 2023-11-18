#include <sys/types.h>  // pour les types
#include <unistd.h>     // pour fork, pipe, read, write, close
#include <stdio.h>      // pour printf
#include <string.h>     // pout strlen

#define R 0
#define W 1

int main()
{
    int fd[2];
    pipe(fd);          // création d'un tube sans nom
    char message[100]; // pour récupérer un message
    int nboctets;
    char *phrase = " message envoyé au père par le fils";
    if (fork() == 0) // création d'un processus fils
    {
        close(fd[R]); // Le fils ferme le descripteur non utilisé de lecture
        // dépôt dans le tube du message
        write(fd[W], phrase, strlen(phrase) + 1);
        close(fd[W]); // fermeture du descripteur d'écriture
    }
    else
    {   // Le père ferme le descripteur non utilisé d'écriture
        close(fd[W]);
        // extraction du message du tube
        nboctets = read(fd[R], message, 100);
        printf("Lecture %d octets : %s\n", nboctets, message);
        // fermeture du descripteur de lecture
        close(fd[R]);
    }
    return 0;
}
