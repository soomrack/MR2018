#include <stdio.h>
#include <stdlib.h>

int main()
{
    char tmpstr[1000];
    int x = 0;
    int tokens = 0;
    do {
    printf("Enter x: ");
    tokens = scanf("%d", &x);
    gets(tmpstr);
    printf("tokens = %d, x = %d\n", tokens, x);
    } while(x <= 0 || tokens == 0);
    printf("Successfully scanned positive number! x = %d, x");
    return 0;
}
