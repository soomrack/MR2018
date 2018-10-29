#include <stdio.h>

int main()
{
    int x = 0;
    scanf("%d", &x);
    while(x > 0)
    {
        printf("x\%10 = %d, x = %d \n", x%10, x);
        x = x / 10; //целочисленное деление на 10!
    }
    printf("x = %d", x);
    return 0;
}
