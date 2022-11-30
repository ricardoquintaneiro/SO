#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int ret;

    printf("Antes do fork: PID = %d, PPID = %d\n", getpid(), getppid());
    if ((ret = fork()) < 0) { 
        perror("erro na duplicação do processo");
        return EXIT_FAILURE;
    }
    if (ret > 0) sleep(1);
    char *who;
    if (getpid() < ret)
        who = "PAI\0";
    else
        who = "FILHO\0";
    printf("Quem sou eu?\nApós o fork: PID = %d, PPID = %d, Eu sou o %s\n",
           getpid(), getppid(), who);

    return EXIT_SUCCESS;
}
