#include <stdio.h>
//#include <stdint.h>
#include <iostream>


//#include "../src/ClassMatrix.h"
#include "../src/ClassMatrix.cpp"


#define STRINGIFY( x ) #x

#define TEST_EQUAL( value, expected )                                   \
{                                                                       \
    printf("%-50s","Testing "  STRINGIFY(value) " ");                   \
    int32_t v = value;                                                  \
    if( v != expected )                                                 \
    {                                                                   \
        printf( "Test failed! "     \
               " Expected: %i, got %i\n", expected, v);                 \
        returnCode = 1;                                                 \
    }                                                                   \
    else                                                                \
    {                                                                   \
        printf(": " "Passed\n" ); \
    }                                                                   \
}\

int main()
{
    double *B = new double[1 * 1 * sizeof(double)];
    ClassMatrix C {1, 1, B};
    double D = C.matrix_trace(C);
    int returnCode = 0;

    printf("Starting tests on eval...\n\n");

    // sanity checks
    TEST_EQUAL( D,  3.0  );
    if( returnCode == 0 )
    {
        printf(  "All tests passed!\n"  );
    }

    return returnCode;
}



