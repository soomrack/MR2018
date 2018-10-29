#include <stdio.h>

typedef struct {
    int x, y, color;
} Point;

void print_point(Point pt)
{
    printf("x = %d, y = %d, color = %d\n", pt.x, pt.y, pt.color);
}

int main()
{
    Point A;
    A.x = 1;
    A.y = 2;
    A.color = 17;

    Point B;
    B.x = 3;
    B.y = 4;
    B.color = 19;

    print_point(A);
    print_point(B);

    Point tmp;
    tmp = A;
    A = B;
    B = tmp;

    print_point(A);
    print_point(B);

    return 0;
}
