#include <unistd.h>
#include <stdio.h>

int main()
{
  int i;
  for (i = 0; i < 3; i++)
    if (fork())
      i++;
  sleep(5);
  return i;
}