#include <stdio.h>

int main()
{
                        //алгоритм Евклида
                        int gcd; //grand common divisor -- НОД
                        int a, b;
                        scanf("%d%d", &a, &b);
l_loop_start:
                        if (a == b) goto l_print;
                        if (a < b) goto l_a_lesser_b;
                        a -= b;
                        goto l_loop_start;
l_a_lesser_b:
                        b -= a;
                        goto l_loop_start;
l_print:
                        gcd = a;
                        printf("gcd = %d\n", gcd);
                        return 0;
}
