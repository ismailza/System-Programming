#include "client_serveur.h"

int main(void)
{
  int res, i;
  key_t clef_requetes, clef_reponses;
  int frequete, freponse;

  clef_requetes = ftok(FICHIER1, PROJET);
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

  printf("Waiting a request...\n");
  
  res = msgrcv(frequete, &msg, LG_MAX, 0, 0);
  if (res == -1)
  {
    perror("msgrcv");
    exit(0);
  }
  for (i = 0; i < strlen(msg.mtext); i++)
    msg.mtext[i] = toupper(msg.mtext[i]);
  res = msgsnd(freponse, &msg, strlen(msg.mtext) + 1, 0);
  if (res == -1)
  {
    perror("msgsnd");
    exit(0);
  }
  
  return (EXIT_SUCCESS);
}