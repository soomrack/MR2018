#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *p = NULL;
    for(int i = 0; i < 1000; i++) {
        p = malloc(1024*1024);
        if (p == NULL) {
            printf("no memory...\n");
            continue;
        }
        printf("memory allocated\n");
        for(int j = 0; j < 1024*1024; j++) {
            *(p + j) = j;
        }
        free(p);
    }
    int x = getchar();

    return 0;
}
