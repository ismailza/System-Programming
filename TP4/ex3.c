#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <unistd.h>

#define MESSAGE_TYPE 1

// Structure pour le message
struct message {
    long type;
    int numbers[2];//les deux nombres requis
    pid_t client_pid;
};

int main() {
    key_t key;
    int msgid;

    // Génération de la clé pour la file de messages ,prend la reference et nombre 
    if ((key = ftok(".", 'a')) == -1) {
        perror("Erreur lors de la génération de la clé");
        exit(EXIT_FAILURE);
    }

    // Création de la file de messages droit e lecture et ecriture
    if ((msgid = msgget(key, IPC_CREAT | 0666)) == -1) {
        perror("Erreur lors de la création de la file de messages");
        exit(EXIT_FAILURE);
    }

    printf("Serveur prêt à recevoir des questions.\n");

    // Attente de messages
    while (1) {
        struct message msg;

        // Réception du message
        if (msgrcv(msgid, &msg, sizeof(msg.numbers), MESSAGE_TYPE, 0) == -1) {
            perror("Erreur lors de la réception du message");
            exit(EXIT_FAILURE);
        }

        printf("Serveur a reçu une question de %d : %d + %d\n",
               msg.client_pid, msg.numbers[0], msg.numbers[1]);

        // Calcul de la somme
        int sum = msg.numbers[0] + msg.numbers[1];

        // Préparation de la réponse
        struct message reply;
        reply.type = msg.client_pid;
        reply.client_pid = getpid();
        reply.numbers[0] = sum;

        // Envoi de la réponse
        if (msgsnd(msgid, &reply, sizeof(reply.numbers), 0) == -1) {
            perror("Erreur lors de l'envoi de la réponse");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}