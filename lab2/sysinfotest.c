#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/param.h"
#include "kernel/sysinfo.h"
int main(int argc,char*argv[])
{
    struct sysinfo  kk;
    sysinfo(&kk);
    printf("proc=%d  freemem=%d\n",kk.nproc,kk.freemem);
    exit(0);
}

