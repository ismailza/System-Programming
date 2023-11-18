#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int count = 0;

static void action(int sig)
{
  ++count;
  write(1, "capture du signal SIGINT\n", 26);
}

int main()
{
  // Spécification de l'action du signal
  signal(SIGINT, action);
  printf("Debut:\n");
  do
  {
    sleep(1);
  } while (count < 3);
  return 0;
}