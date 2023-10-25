#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define N 3
int main()
{
  int i = 1;
  while (fork() == 0 && i <= N)
    i++;
  printf("%d\n", i);
  exit(0);
}

// 5 process