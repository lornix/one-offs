#include <stdio.h>

#define DPRINT(format, ...) printf("DEBUG: " format "\n", ##__VA_ARGS__) 

int main()
{
    DPRINT("hello world");
    return 0;
}
