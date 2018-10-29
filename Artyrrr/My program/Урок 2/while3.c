#include <stdio.h>

int main()
{
    int x = 0;
    scanf("%d", &x);
    while(x > 0)
    {
        printf("x\%10 = %d, x = %d \n", x%2, x);
        x = x / 2; //целочисленное деление на 10!
    }
    printf("x = %d", x);
    return 0;
}
