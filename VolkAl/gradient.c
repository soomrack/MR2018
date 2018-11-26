// grad.c
#include <stdio.h>
#include <math.h>
// функция
#define f(x,y)      (-4. * x + x*x - y - x * y + y * y)
// частная производная функции по переменной X
#define dfdx(x,y) (-4+2.*x-y)
// частная производная функции по переменной Y
#define dfdy(x,y) (-1.-x+2.*y)

void search(double sigma,double epsilon);
void get_min(double epsilon, double sigma);
void get_sk();

double sk_x = 0., sk_y = 0.;
// начальное приближение
double p_x = 0., p_y = 0.;

double err;
double lambda;

void get_sk()
{
    // вычисляем норму вектора градиента
    double norm = sqrt(dfdx(p_x, p_y)*dfdx(p_x, p_y) + dfdy(p_x, p_y)*dfdy(p_x, p_y));
    // вычисляем S(k) - вектор единичной длины в направлении
    // противоположном направлению градиента
    sk_x = -dfdx(p_x, p_y) / norm;
    sk_y = -dfdy(p_x, p_y) / norm;
}

int main()
{
    // точность расчёта
    double sigma = 0.001;
    double epsilon = 0.001;
    search(sigma, epsilon);

    return 0;
}

void search(double sigma,double epsilon)
{
    int c = 0;
    lambda = 1.;
    err = 1.;

    while (c++ < 60 && (lambda > sigma || err > epsilon)) {
        get_sk();
        get_min(epsilon, sigma);
        printf("f[%g, %g] = %g\n", p_x, p_y, f(p_x, p_y));
    }

    printf("\n Min of function: -4*x + x*x - y - x*y + y*y\n");
    printf("f[%g, %g] = %g\n", p_x, p_y, f(p_x, p_y));
}

void get_min(double epsilon, double sigma)
{
    // значение f(px^k) ...
    double f0 = f(p_x, p_y);

    // значение шага приближения px^(k+1)
    double p1_x = p_x + 1. * lambda * sk_x;
    double p1_y = p_y + 1. * lambda * sk_y;
    // значение f(px^(k+1)) ...
    double f1 = f(p1_x, p1_y);

    // значение шага приближения px^(k+2)
    double p2_x = p_x + 2. * lambda * sk_x;
    double p2_y = p_y + 2. * lambda * sk_y;
    // значение f(px^(k+2)) ...
    double f2 = f(p2_x, p2_y);

    int j = 0, cond = 0;
    while (j < 60 && cond == 0) {
        // f(px^k) <= f(px^(k+1))
        if (f0 <= f1) {
            p2_x = p1_x;
            p2_y = p1_y;

            f2 = f1;
            lambda = lambda / 2.;

            p1_x = p_x + 1. * lambda * sk_x;
            p1_y = p_y + 1. * lambda * sk_y;
            f1 = f(p1_x, p1_y);
        }
            // f(px^(k+2)) < f(px^(k+1))
        else if (f2 < f1) {
            p1_x = p2_x;
            p1_y = p2_y;

            f1 = f2;
            lambda = lambda * 2.;

            p2_x = p_x + 2. * lambda * sk_x;
            p2_y = p_y + 2. * lambda * sk_y;
            f2 = f(p2_x, p2_y);
        }
        else
            cond = -1;

        j = j+1;
        if (lambda < sigma)
            cond = 1;
    }


    double lambda_min = (lambda/2)* (4 * f1 - 3* f0 - f2) / (2* f1 - f0 - f2);

    p_x = p_x + lambda_min * sk_x;
    p_y = p_y + lambda_min * sk_y;

    double lambda0 = fabs(lambda_min);
    double lambda1 = fabs(lambda_min - lambda);
    double lambda2 = fabs(lambda_min - 2.*lambda);

    if (lambda0 < lambda)
        lambda = lambda0;
    if (lambda1 < lambda)
        lambda = lambda1;
    if (lambda2 < lambda)
        lambda = lambda2;
    if (lambda == 0)
        lambda = lambda_min;

    if (lambda < sigma)
        cond = 1;

    double e0 = fabs(f0 - f(p_x, p_y));
    double e1 = fabs(f1 - f(p_x, p_y));
    double e2 = fabs(f2 - f(p_x, p_y));

    if (e0 != 0 && e0 < err)
        err = e0;
    if (e1 != 0 && e1 < err)
        err = e1;
    if (e2 != 0 && e2 < err)
        err = e2;
    if (e0 == 0 && e1 == 0 && e2 == 0)
        err = 0;
    if (err < epsilon)
        cond = 2;
}
