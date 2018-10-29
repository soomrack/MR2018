#include <stdio.h>

int main()
{
    int x = 0;
    while(x < 11)
    {
        printf("Hello, World! x = %d \n", x);
        x = x + 1;
    }
    printf("x = %d", x);
    return 0;
}
