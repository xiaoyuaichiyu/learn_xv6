#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/param.h"

int 
main(int argc,char*argv[])
{
    if(argc<2){printf("error\n");exit(1);}
    if(argc>=MAXARG-1){printf("out of maxarg\n");exit(1);}

    char *cmd=argv[1];
    char *arg[MAXARG];int argCount=argc;
    //将argv   复制到 arg
    for (int i = 1; i < argc; i++)arg[i-1]=argv[i];
    arg[argCount]=0;
    char buffer[100];int index=0;
    memset(buffer,0,100);
    while (read(0,&buffer[index],1)!=0)
    {
        if(buffer[index]=='\n')
        {
            buffer[index]=0;
            char  temp[100];
            printf("%p\n",temp);
            memcpy(temp,buffer,index+1);
            printf("%s\n",buffer);
            arg[argCount++]=temp;
            memset(buffer,0,100);
            index=0;
        }
        index++;
    }
    //arg[argc];   sh < xargstest.sh
    
    int pid =fork();
    if(pid==0)
    {//son
    printf(cmd);
    printf("%s\n",arg[0]); printf("%s\n",arg[1]); printf("%s\n",arg[2]);printf("%s\n",arg[3]);
        //exec(cmd,arg);  
        exit(0);      
    }
    wait(0);
    exit(0);
}

