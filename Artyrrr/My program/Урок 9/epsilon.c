#include <stdio.h>

int main()
{
    float fx = 1.0;
    float feps = 1.0;
    while (fx + feps != fx) {
        feps = feps/2.;
    }

    double dx = 1.0;
    double deps = 1.0;
    while (dx + deps != dx) {
        deps = deps/2.;
    }
    printf("Machine epsilon for float: %g\n", feps);
    printf("Machine epsilon for double: %g\n", deps);
    return 0;
}
