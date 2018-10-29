#include <stdio.h>

void helloer()
{
    static int counter = 0; //статическая переменная

    if (counter != 3) {
        printf("Hello, World!\n");
        counter ++;
    } else {
        printf("Oh...\n");
        counter = 0;
    }
}

int main()
{
    helloer();
    helloer();
    helloer();
    helloer();
    helloer();
    helloer();
    helloer();
    helloer();
    helloer();
    helloer();
    helloer();
    helloer();
}
