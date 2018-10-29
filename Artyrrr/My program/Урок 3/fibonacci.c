#include <stdio.h>

int main()
{
    int n_max;
    scanf("%d", &n_max);
    int f_previous = -5;
    int f = 1;
    printf("Fib(0) = 0\n");
    printf("Fib(1) = 1\n");
    for(int i = 2; i < n_max; i++) {
        int tmp_value = f;
        f = f + f_previous;
        f_previous = tmp_value;
    printf("Fib(%d) = %d\n", i, f);
    }
    return 0;
}
