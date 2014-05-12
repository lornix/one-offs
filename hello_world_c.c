#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/user.h>

int main()
{
    printf("Hello, World!\n");
    printf("Goodbye, Goodbye!\n");
    printf("      &main: %10p\n",&main);
    printf("       sbrk: %10p\n",sbrk(0));
    printf("getpagesize: %10p (%d)\n",(void*)sysconf(_SC_PAGESIZE),_SC_PAGESIZE);
    printf("   PAGESIZE: %10p\n",(void*)PAGE_SIZE);
    /* asm("int $0x3\n"); */
    return 0;
}
