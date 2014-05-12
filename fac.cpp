#include <iostream>

int fac(int n) {
    if (n<2) {
        return 1;
    }
    return n*fac(n-1);
}
int main()
{
    for (int i=0; i<4; i++) {
        std::cout << i << ":" << fac(i) << std::endl;
    }
    return 0;
}
