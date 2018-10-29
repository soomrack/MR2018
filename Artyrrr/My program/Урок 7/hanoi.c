#include <stdio.h>

void hanoi(int height, int start, int finish)
{
    if (height == 1) {
            printf("move disk 1 from %d to %d\n", start, finish);
    } else {
        int tmp = 6 - start - finish;
        hanoi(height - 1, start, tmp);
        printf("move disk %d from %d to %d\n", height, start, finish);
        hanoi(height - 1, tmp, finish);
    }
}

int main()
{
    hanoi(5, 1, 2);

    return 0;
}
