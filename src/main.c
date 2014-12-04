#include <stdio.h>
#include <stdlib.h>

#include <config.h>

int main(int argc, char *argv[])
{
  int i;

  printf("%s for %d\n", PROG, FORCEMAJOR);
  for (i = 0; i < argc; i++)
    printf("%-3d : %s\n", i, argv[i]);

  return 0;
}
