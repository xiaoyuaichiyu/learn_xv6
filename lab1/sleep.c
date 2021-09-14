#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if(argc!=2){printf("argv is error\n");exit(1);}
  //int i=10;
  printf("this is test%d\n",atoi(argv[1]));
  sleep(atoi(argv[1]));
  printf("this is test%d\n",atoi(argv[1]));
  exit(0);
}
