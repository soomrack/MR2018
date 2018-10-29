#include <stdio.h>

int main()
{
    int x = 777;
    int * pi = &x; //переменная адресного типа, положим туда адрес x
    int ** ppi = &pi; //переменная адресного типа
    int *** pppi = &ppi; //переменная адресного типа
    int **** ppppi = &pppi;
    int ***** pppppi = &ppppi;
    int ****** ppppppi = &pppppi;
    int ******* pppppppi = &ppppppi;
    int ******** ppppppppi = &ppppppi;

    *pi = 111;
    printf("%d\n", x);
    **ppi = 222;
    printf("%d\n", x);
    ***pppi = 333;
    printf("%d\n", x);
    ****ppppi = 444;
    printf("%d\n", x);
    *****pppppi = 555;
    printf("%d\n", x);
    ******ppppppi = 666;
    printf("%d\n", x);
    *******pppppppi = 777;
    printf("%d\n", x);
    ********ppppppppi = 888;
    printf("%d\n", x);

    return 0;
}
