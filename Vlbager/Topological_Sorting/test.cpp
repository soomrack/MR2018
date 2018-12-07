
#include "source.h"
#include <chrono>
#include <cstdlib>

typedef std::chrono::high_resolution_clock Clock;

int main()
{
    srand(123);

    for (unsigned int n = 2; n <= 512; n *= 2)
    {
        graph test(n);
        uiVector sorted;
        clock_t start, stop;
        auto t1 = Clock::now();
        test.topological_sort(sorted);
        auto t2 = Clock::now();
        std::cout << "Testing graph of " << n << " elements:  "
                  << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
                  << std::endl;
    }
    return 0;

}


