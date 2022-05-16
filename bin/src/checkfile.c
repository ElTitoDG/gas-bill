#include "../include/checkfile.h"
#include<stdio.h>
#include<sys/stat.h>

int checkIfFileExists(const char* filename)
{
  struct stat buffer;
  int exist = stat(filename, &buffer);
  if(exist == 0)
  {
    return 1;
  }
  else 
  {
    printf("File doesn't exists\n");
    return 0;
  }
}
