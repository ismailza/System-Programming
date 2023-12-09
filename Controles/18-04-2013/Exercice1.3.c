#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *com[] = {NULL};
  fork(); fork(); 
  execvp("./file.out", com);
  fork(); fork();
  return 0;
}