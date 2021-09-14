#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "../user/user.h"

void
childProcess(int pfd[2])
{
    close(pfd[1]);
    int buf;
    if(read(pfd[0],&buf,sizeof(int))==0)
    {close(pfd[0]);exit(0);}

    printf("prime %d\n",buf);
    int subFd[2];
    pipe(subFd);
    int pid=fork();
    if(pid>0)
    {
        close(subFd[0]);
        int subbuf;
        while (read(pfd[0],&subbuf,sizeof(int))==4)
        {
            if (subbuf % buf != 0) 
            {
                write(subFd[1],&subbuf,sizeof(int));
            }
        }  
        //sleep(1);
        close(pfd[0]);close(subFd[1]);
    }else
    {
        childProcess(subFd);
    }
   
    
    wait(0);exit(0);
}
int
main(int argc, char *argv[])
{
    int pfd[2];
    pipe(pfd);
    int pid=fork();
    if(pid>0)
    {
        //sleep(1);
        close(pfd[0]);
        for (int i = 2; i < 36; i++)
        {
            write(pfd[1],&i,sizeof(int));
        }
        close(pfd[1]);
    }else
    {
        childProcess(pfd);
    }
    wait(0);
    exit(0);
}