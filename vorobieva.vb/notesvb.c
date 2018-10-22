#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <err.h>
#include "libraryvb.h"
#include <time.h>


int main()
{
    srand(time(NULL));
    Matrix A = matrix_rand(3,3);
    Matrix B = matrix_rand(3,3);
    matrix_print(A);
    printf("\n");
    matrix_print(B);
    printf("%1.3f\n\n", matrix_trace(matrix_rand(3,3)));
    matrix_print(matrix_one(3,3));
    printf("\n");
    matrix_print(matrix_zero(3,3));
    printf("\n");
    Matrix C = matrix_sum(A, B);
    matrix_print(C);
    printf("\n");
    C = matrix_mult__scalar(3,A);
    matrix_print(C);
    return 0;
}
