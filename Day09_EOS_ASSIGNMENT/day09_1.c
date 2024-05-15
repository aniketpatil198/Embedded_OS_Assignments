
/*1. Input signal number and a process id from user. Send given signal to the given process using kill() syscall.*/
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>

int main()
{
    int pid,ret, sig;

    printf("Enter the process id: ");
    scanf("%d", &pid);

    printf("Enter the signal number: ");
    scanf("%d", &sig);

    ret=kill(pid, sig);

    if(ret==0)
        printf("Signal sent successfully\n");

    else
        printf("Signal sending failed\n");

    if(ret==-1)
        perror("kill");

    return 0;

}

