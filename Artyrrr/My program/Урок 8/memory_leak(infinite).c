#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *p = NULL;
    for(;;) {
        p = malloc(1024*1024);
        if (p == NULL) {
            printf("no memory...\n");
            continue;
        }
        printf("memory allocated\n");
        for(int j = 0; j < 1024*1024; j++) {
            *(p + j) = j;
        }
    }
    int x = getchar();

    return 0;
}
