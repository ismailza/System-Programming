#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int status;
  if (!fork())
  {
    srand(time(NULL));
    exit(rand() % 101);
  }
  else
  {
    wait(&status);
    printf("%d\n", WEXITSTATUS(status));
  }
  return 0;
}