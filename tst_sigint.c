#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signum)
{
    printf("Received signal %d\n", signum);
}

int main()
{
    signal(SIGABRT, sig_handler);
    signal(SIGALRM, sig_handler);
    signal(SIGUSR1, sig_handler);
    alarm(1);
    sleep(2);
    raise(SIGUSR1);
    sleep(1);
    abort();
    printf("All done\n");
    return 0;
}
