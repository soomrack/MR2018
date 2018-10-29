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
    Point A[10];
    for(int i = 0; i < 10; i++){
        A[i].x = i;
        A[i].y = 10 - i;
    }
    for(int i = 0; i < 10; i++) {
        printf("A[%d]: ", i);
        print_point(A[i]);
    }
    printf("\n");

    //сортировка массива
    for (int prohod = 1; prohod < 10; prohod++) {
        for (int i = 0; i < 10 - prohod; i++) {
                if (A[i].x < A[i+1].x) {
                    Point tmp;
                    tmp = A[i];
                    A[i] = A[i+1];
                    A[i+1] = tmp;
                }
        }
    }
    for(int i = 0; i < 10; i++) {
        printf("A[%d]: ", i);
        print_point(A[i]);
    }
    printf("\n");

    return 0;
}
