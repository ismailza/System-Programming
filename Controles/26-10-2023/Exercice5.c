#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  (fork() || fork() || fork()) && fork();
  fork();
  exit(0);
}

// 13 processus sont créés
// 14 processus au total