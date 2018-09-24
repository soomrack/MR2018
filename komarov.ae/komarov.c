#include "library.h"

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define N 3
#define CONFIG_SOMETHING
#define SQUARE(x) (x*x)

/**
 * struct my_struct - short description
 * @a: first member
 * @b: second member
 *
 * Longer description
 */
struct my_struct {
        int a;
        int b;
        int c;
};

typedef struct My_struct {
        int a;
} my_type;

void ave()
{
        char *a = "0123456";
        printf("Awe %s!\n", a);
        printf("%d %d %d %li \n\n", sizeof(a), SQUARE(strlen(a)), SHRT_MAX, LONG_MAX);

#ifdef CONFIG_SOMETHING
        printf("CONFIG!");
        goto err;
#endif /* CONFIG_SOMETHING */
        return;
err:
        ;
        my_type ras;
        ras.a = 100500;
        printf("%d\n", ras.a);
        printf("Error!\n");
}



int main()
{
        printf("Hello, World!\n\n");
        for(int k = 1; k <= N; ++k){
                ave();
        }

        main2();
        return 0;
}
