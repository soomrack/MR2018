#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(i = 1; i < n; i++) {
        int tmp_value = f;
        f = f + f_previous;
        f_previous = tmp_value;
    }
    printf("Fib(%d) = %d\n", n, f);
    return 0;
}
