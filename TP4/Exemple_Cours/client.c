#include "client_serveur.h"

int main(void)
{
  int res;
  int frequete, freponse;
  key_t clef_requetes, clef_reponses;

  clef_requetes= ftok(FICHIER1, PROJET);
  if (clef_requetes == -1)
  {
    perror("Problème pour obtenir la clé");
    exit(EXIT_FAILURE);
  }

  clef_reponses = ftok(FICHIER2, PROJET);
  if (clef_reponses == -1)
  {
    perror("Problème pour obtenir la clé");
    exit(EXIT_FAILURE);
  }

  frequete = msgget(clef_requetes, 0700 | IPC_CREAT);
  if (frequete == -1)
  {
    perror("msgget");
    return (EXIT_FAILURE);
  }

  freponse = msgget(clef_reponses, 0700 | IPC_CREAT);
  if (freponse == -1)
  {
    perror("msgget");
    return (EXIT_FAILURE);
  }

  msg.mtype = getpid();
  strcpy(msg.mtext, "Hello");
  res = msgsnd(frequete, &msg, strlen(msg.mtext) + 1, 0);
  if (res == -1)
  {
    perror("msgsnd");
    exit(0);
  }
  res = msgrcv(freponse, &msg, LG_MAX, getpid(), 0);
  if (res == -1)
  {
    perror("msgrcv");
    exit(0);
  }
  printf("result : %s\n", msg.mtext);

  return (EXIT_SUCCESS);
}