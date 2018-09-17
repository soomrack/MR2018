/*
 * Lecture 1
 *     + strings
 *     + functions
 *     + macro
 *     + constants
 *     + data types
 *     + goto
 *
 *     Style: Stroustrup + K&R braces
 *     + 8 tabs & ident
 *     + 80 line
 *
 * */

#include "librain.h"

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
/* private: internal use only */
        int c;
};

/**
 * typedef type_name - Brief description.
 *
 * Description of the type.
 */
typedef struct My_struct {
        int a;
} my_type;



/**
 * function_name() - Brief description of function.
 * @arg1: Describe the first argument.
 * @arg2: Describe the second argument.
 *        One can provide multiple line descriptions
 *        for arguments.
 *
 * A longer description, with more discussion of the function function_name()
 * that might be useful to those using or modifying it. Begins with an
 * empty comment line, and may include additional embedded empty
 * comment lines.
 *
 * The longer description may have multiple paragraphs.
 *
 * Return: Describe the return value of foobar.
 *
 * The return value description can also have multiple paragraphs, and should
 * be placed at the end of the comment block.
 */
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
        //printf("Hello, World!\n\n");
      //  for(int k = 1; k <= N; ++k){
       //         ave();
       // }

        main2();
        return 0;
}
