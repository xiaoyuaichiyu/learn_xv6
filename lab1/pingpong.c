#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "../user/user.h"

int
main(int argc, char *argv[])
{
    int pid=fork();
    int myPipe[2];
    pipe(myPipe);
    
    if(pid==0)
    {
        close(myPipe[1]);//必须关闭
        char mm[1];
        int count=read(myPipe[0],mm,1);
        if(count==1){close(myPipe[0]);}
        int pid=getpid ();
        printf("%d :received ping\n",pid);
    }else
    {
        close(myPipe[0]);
        char sou[2]="a\n";
        write(myPipe[1],&sou,1);
        close(myPipe[1]);
         int pid=getpid ();
        printf("%d : received pong\n",pid);
    }
    wait(0);
    exit(0);
}
