#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=17;
    int b;
    asm("movl %1, %%eax;"
        "addl %%eax,%%eax;"
        "movl %%eax, %0;"
        :"=r" (b)
        :"r" (a)
        :"%eax"
       );
    printf("a=%d, b=%d\n",a,b);
    return 0;
}

