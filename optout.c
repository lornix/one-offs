int puts(const char* s);

static void do_something()
{
#ifdef DOIT
    puts("do_something");
#endif
}

int main()
{
    puts("One");
    do_something();
    puts("Two");
    return 0;
}

