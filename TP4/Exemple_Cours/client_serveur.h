#ifndef CLIENT_SERVEUR_H
#define CLIENT_SERVEUR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define FICHIER1 "client"
#define FICHIER2 "serveur"
#define PROJET 1
#define LG_MAX 512

struct msgform
{
  long mtype;
  char mtext[LG_MAX];
} msg;

#endif