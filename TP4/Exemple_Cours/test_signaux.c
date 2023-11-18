#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static void action(int sig)
{
  printf("On peut maintemant m'eliminer\n");
  signal(SIGTERM, SIG_DFL);
}

int main()
{
  if (signal(SIGTERM, SIG_IGN) == SIG_ERR)
    perror("Erreur de traitement du code de l'action\n");
  if (signal(SIGUSR2, action) == SIG_ERR)
    perror("Erreur de traitement du code de l'action\n");
  while (1)
    pause();
}