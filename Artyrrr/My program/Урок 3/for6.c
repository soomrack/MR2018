#include <stdio.h>

int main()
{
    int N, x, found_x0;
    scanf("%d", &N);

    int x0 = 777;

    found_x0 = 0;
    for(int i = 0; i < N; i++) {
        scanf("%d", &x);
        if (x == x0) {
            found_x0 = 1;
        }
    }

    if(found_x0) {
        printf("Found");
     }   else {
            printf("Not found...\n");
        }
        return 0;
}
