#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>

void main(int argc, char *argv[])
{
  key_t cle;
  if (argc != 3)
  {
    fprintf(stderr, "%s: syntaxe:%s <ref_cle><nbr_cle>\n", argv[0], argv[0]);
    exit(1);
  }
  if ((cle = ftok(argv[1], atoi(argv[2]))) == -1)
  {
    fprintf(stderr, "Probleme de cle\n");
    exit(2);
  }
  printf("%d\n", cle);
}