#include <stdio.h>

int main()
{
    for(int digit1 = 0; digit1 < 2; digit1++)
        for(int digit2 = 0; digit2 < 2; digit2++)
        for(int digit3 = 0; digit3 < 2; digit3++)
        printf("%d%d%d ", digit1, digit2, digit3);
        return 0;
}
