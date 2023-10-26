#include <unistd.h>
#include <stdio.h>

#define N 3
int main()
{
  int i = 1;
  while (fork() == 0 && i <= N)
    i++;
  printf("%d\n", i);
  return 0;
}