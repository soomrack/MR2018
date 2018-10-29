#include <stdio.h>

int main()
{
    //найти три наибольших числа в потоке чисел
    //считать, что чисел больше двух
    int m1 = -1, m2 = -1, m3 = -1; //предполагаем, что вводимые числа больше нуля
    int x;
    scanf("%d", &x);
    while (x != 0){
            if(x > m1) {
                    m3 = m2;
                    m2 = m1;
                    m1 = x;
            } else if(x > m2) {
                    m3 = m2;
                    m2 = x;
            } else if(x > m3){
                    m3 = x;
            }

            scanf("%d", &x);
    }
    printf("max1 = %d, max2 = %d, max3 = %d\n", m1, m2, m3);
    return 0;

}
