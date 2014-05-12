#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* p=(char*)malloc(300);

    strncpy(p,"this should succeed",256);
    puts(p);

    free(p);

    exit(EXIT_SUCCESS);
}
