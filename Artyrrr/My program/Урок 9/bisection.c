#include <stdio.h>
#include <math.h> //математическая библиотека. В данной программе не используется

double f(double x)
{
    return x*x - 4*x;
}

int main()
{
    double a = 1;
    double b = 5;
    double epsilon = 1e-5;
    if (f(a)*f(b) >= 0) {
            printf("Wrong interval [a,b], f(a)*f(b) >= 0.\n");
    return 1;
    }

    while (b - a > 2*epsilon) {
        printf("a = %f, b = %f, f(a) = %f, f(b) = %f\n", a, b, f(a), f(b));
        double c = (a + b)/2;
        if (f(c) == 0){ //если вдруг нашёлся точный результат
        a = b = c;
        break;
    }
    else if (f(c)*f(a) < 0)
        b = c;
    else
        a = c;
    }
    printf("root of equation = %f +- %f\n", (a + b)/2, (b - a)/2);
    return 0;
}
