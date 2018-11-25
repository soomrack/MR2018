#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <float.h>

#include "matrix.h"


typedef struct
{
    unsigned int size;
    double * data;
} Vector;


static void matrix_mult_withoutCreate(Matrix A, Matrix B, Matrix result);

extern double matrix_trace(const Matrix  A)
{

    double result = 0;

    for (int row = 0; row < A.rows; row++)
    {
        result += A.data[row * A.cols + row];
    }
    return result;
}

static Matrix matrix_forminor(const Matrix A, int mrow, int mcol)
{
    int counter = 0;

    Matrix result = {A.rows - 1, A.cols - 1};
    result.data = malloc(result.cols * result.rows * sizeof(double));

    for (int row = 0; row < A.rows; row++)
    {
        if (row == mrow)
        {
            continue;
        }
        for (int col = 0; col < A.cols; col++)
        {
            if (col == mcol)
            {
                continue;
            }
            result.data[counter] = A.data[row * (A.cols) + col];
            counter++;
        }
    }

    return result;
}

extern double matrix_determinant(const Matrix A)
{

    if (A.rows == 1)
    {
        return A.data[0];
    }

    double result = 0;
    int sign = 1;

    for (int col = 0; col < A.cols; col++)
    {
        Matrix temp;
        temp = matrix_forminor(A, 0, col);

        result += sign * A.data[col] * matrix_determinant(temp);

        sign = -sign;

        free(temp.data);
    }
    return result;
}

extern void matrix_print(const Matrix A)
{
    for (int row = 0; row < A.rows; row++)
    {
        printf("|");
        for(int col = 0; col < A.cols; col++)
        {
            printf(" %5.2lf ", A.data[row * A.cols + col]);
        }
        printf("|\n");
    }
    printf("\n");
}

extern Matrix matrix_one(const unsigned int size)
{
    Matrix result = {size, size};
    result.data = malloc(size * size * sizeof(double));
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            if (row == col)
            {
                result.data[row * size + col] = 1.0;
            }
            else
            {
                result.data[row * size + col] = 0.0;
            }
        }
    }
    return result;
}

extern Matrix matrix_zero(const unsigned int rows, const unsigned int cols)
{
    Matrix result = {rows, cols};
    result.data = malloc(rows * cols * sizeof(double));
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            result.data[row * cols + col] = 0.0;
        }
    }
    return result;
}

static double get_rand_range(int min, int max)
{
    return ( (double) (rand() % (1000 * max - 1000 * min + 1) + 1000 * min) / 1000);
}

extern Matrix matrix_rand(const unsigned int rows, const unsigned int cols)
{
    Matrix result = {rows, cols};
    result.data = malloc(rows * cols * sizeof(double));

    static bool ifNotInit = true;
    if (ifNotInit)
    {
        srand( (unsigned int) time(NULL));
        ifNotInit = false;
    }

    for ( int row = 0; row < result.rows; row++)
    {
        for ( int col = 0; col < result.cols; col++)
        {
            result.data[row * result.cols + col] = get_rand_range(-1, 1);
        }
    }
    return result;
}

extern Matrix matrix_sum(const Matrix A, const Matrix B)
{
    Matrix result = {A.rows, A.cols};
    result.data = malloc(result.rows * result.cols * sizeof(double));
    for (int row = 0; row < A.rows; row++)
    {
        for (int col = 0; col < A.cols; col++)
        {
            result.data[row * A.cols + col] = A.data[row * A.cols + col] + B.data[row * A.cols + col];
        }
    }
    return result;
}

extern Matrix matrix_trans(const Matrix A)
{
    Matrix result = {A.cols, A.rows};
    result.data = malloc(result.rows * result.cols * sizeof(double));
    for (int row = 0; row < result.rows; row++)
    {
        for (int col = 0; col < result.cols; col++)
        {
            result.data[row * result.cols + col] = A.data[col * A.cols + row];
        }
    }
    return result;
}

extern Matrix matrix_mult(const Matrix A, const Matrix B)
{
    Matrix result = {A.rows, B.cols};
    result.data = malloc(result.rows * result.cols * sizeof(double));

    Matrix transB = matrix_trans(B);
    for (int row = 0; row < result.rows; row++)
    {
        for (int col = 0; col < result.cols; col++)
        {
            result.data[row * result.cols + col] = 0;
            for (int i = 0; i < A.cols; i++)
            {
                result.data[row * result.cols + col] += A.data[row * A.cols + i] * transB.data[col * transB.cols  + i];
            }
        }
    }
    free(transB.data);
    return result;
}

extern Matrix matrix_mult__scalar(const double scalar, const Matrix A)
{
    Matrix result = {A.rows, A.cols};
    result.data = malloc(result.rows * result.cols * sizeof(double));

    for (int row = 0; row < result.rows; row++)
    {
        for (int col = 0; col < result.cols; col++)
        {
            result.data[row * result.cols + col] = scalar * A.data[row * A.cols + col];
        }
    }

    return result;
}

static void matrix_swap_rows(Matrix A, int rowtoswap1, int rowtoswap2)
{
    double temp;
    for (int col = 0; col < A.cols; col++)
    {
        temp = A.data[rowtoswap1 * A.cols + col];
        A.data[rowtoswap1 * A.cols + col] = A.data[rowtoswap2 * A.cols + col];
        A.data[rowtoswap2 * A.cols + col] = temp;
    }
}

static void matrix_datacopy(Matrix A, const Matrix B)
{
    for (int row = 0; row < A.rows; row++)
    {
        for (int col = 0; col < A.cols; col++)
        {
            A.data[row * A.cols + col] = B.data[row * B.cols + col];
        }
    }
}

extern Matrix matrix_invert(const Matrix A)
{
    Matrix A2 = {A.rows, A.cols};
    A2.data = malloc(A2.rows * A2.cols * sizeof(double));
    matrix_datacopy(A2, A);

    Matrix result = matrix_one(A.rows);

    //прямой ход
    for (int diagonal = 0; diagonal < A2.cols; diagonal++)
    {
        //ищу ненулевой элемент и меняю строки местами, если нужно
        if (A2.data[diagonal * A2.rows + diagonal] == 0)
        {
            for (int nozerorow = diagonal + 1; nozerorow < A2.rows; nozerorow++)
            {
                if (A2.data[nozerorow * A2.rows + diagonal] == 0)
                {
                    continue;
                }
                matrix_swap_rows(A2, diagonal, nozerorow);
                matrix_swap_rows(result, diagonal, nozerorow);
                break;
            }
        }


        //делим всю строку на A[row][row]
        double temp = A2.data[diagonal * A2.cols + diagonal];
        for (int col = 0; col < A2.cols; col++)
        {
            A2.data[diagonal * A2.cols + col] /= temp;
            result.data[diagonal * result.cols + col] /= temp;
        }

        //отнимаю от всех нижних строк diagonal строку, помноженную на [row][diagonal] элемент
        for (int row = diagonal + 1; row < A2.rows; row++)
        {
            temp = A2.data[row * A2.cols + diagonal];
            for (int col = 0; col < A2.cols; col++)
            {
                A2.data[row * A2.cols + col] -= A2.data[diagonal * A2.cols + col] * temp;
                result.data[row * result.cols + col] -= result.data[diagonal * A2.cols + col] * temp;
            }
        }

    }
    //обратный ход
    for ( int diagonal = 1; diagonal < A2.rows; diagonal++)
    {
        for ( int row = 0; row < diagonal; row++)
        {
            double temp = A2.data[row * A2.cols + diagonal];
            for ( int col = 0; col < A2.cols; col++)
            {
                A2.data[row * A2.cols + col] -= A2.data[diagonal * A2.cols + col] * temp;
                result.data[row * result.cols + col] -= result.data[diagonal * result.cols + col] * temp;
            }
        }
    }

    free(A2.data);
    return result;
}

extern Matrix matrix_power(const Matrix A, const unsigned int power)
{
    Matrix result = {A.rows, A.cols};
    result.data = malloc(result.rows * result.cols * sizeof(double));

    if (power == 0)
    {
        Matrix one = matrix_one(result.rows);
        matrix_datacopy(result, one);
        free(one.data);
        return result;
    }

    matrix_datacopy(result, A);

    if (power == 1)
    {
        return result;
    }


    for (int i = 1; i < power; i++)
    {
        double * dataptr = result.data;
        result = matrix_mult(result, A);
        free(dataptr);
    }

    return result;
}

//вычислю эвклидову норму матрицы для минимизации вычислительных ошибок алгоритма вычисления матричной экспоненты
static double matrix_Enorm(const Matrix A)
{
    double result = 0;
    for (int row = 0; row < A.rows; row++)
    {
        for (int col = 0; col < A.cols; col++)
        {
            result += (A.data[row * A.cols + col] * A.data[row * A.cols + col]);
        }
    }
    return sqrt(result);
}

static void matrix_mult_scalar_withoutCreate(const double scalar, const Matrix A, Matrix result)
{
    for (int row = 0; row < result.rows; row++)
    {
        for (int col = 0; col < result.cols; col++)
        {
            result.data[row * result.cols + col] = scalar * A.data[row * A.cols + col];
        }
    }
}

static void matrix_sum_withoutCreate(const Matrix A, const Matrix B, const Matrix result)
{
    for (int row = 0; row < A.rows; row++)
    {
        for (int col = 0; col < A.cols; col++)
        {
            result.data[row * A.cols + col] = A.data[row * A.cols + col] + B.data[row * A.cols + col];
        }
    }
}
/*
 * К этому алгоритму много вопросов
 */
extern Matrix matrix_exp(const Matrix A)
{
    static const double eps = 0.000001;
    //чтобы не копить слишком большую ошибку, создам матрицу А2 в 2^p раз меньше А
    double norm = matrix_Enorm(A);
    uint64_t p;
    if (norm < 4)
    {
        p = 1;
    }
    else
    {
        p = (uint64_t) norm;
    }

    //Matrix A2 = matrix_mult__scalar(1/(pow(2.0, p)), A);
    Matrix A2 = {A.rows, A.cols, malloc(A.rows * A.cols * sizeof(double))};
    matrix_datacopy(A2, A);

    //вычисляем матричную экспоненту от A2
    Matrix exp = matrix_one(A.rows);
    Matrix temp = matrix_one(A.rows);
    Matrix temp2 = matrix_one(A.rows);
    int k = 0;
    do
    {
        k++;
        matrix_mult_scalar_withoutCreate(1.0/k, temp, temp);
        matrix_mult_withoutCreate(temp, A2, temp2);
        matrix_datacopy(temp, temp2);
        matrix_sum_withoutCreate(exp, temp, exp);
    }
    while ( (k < 10000) );
    free(temp2.data);
    free(A2.data);

    /*
    //теперь чтобы перейти обратно к матрице А, нужно перемножить exp саму на себя p раз
    for (int i = 0; i < p; i++)
    {
        matrix_mult_withoutCreate(exp, exp, temp);
        matrix_datacopy(exp, temp);
    }
    */
    free(temp.data);

    return exp;
}


static Vector vector_create(const Matrix A, const int col)
{
    Vector result = {A.rows, malloc(A.rows * sizeof(double))};

    for (int row = 0; row < A.rows; row++)
    {
        result.data[row] = A.data[row * A.cols + col];
    }

    return result;
}

/*
 * Предполагается, что память уже выделена
 */
static void vector_copy(const Vector result, const Vector copy)
{
    for (int i = 0; i < copy.size; i++)
    {
        result.data[i] = copy.data[i];
    }
}

static double vector_dotProduct(const Vector a, const Vector b)
{
    double result = 0;

    for (int i = 0; i < a.size; i++)
    {
        result += a.data[i] * b.data[i];
    }

    return result;
}

static void vector_multiplyByScalar(const Vector a, double scalar)
{
    for (int i = 0; i < a.size; i++)
    {
        a.data[i] = a.data[i] * scalar;
    }
}

/*
 * Проекция вектора а на вектор б
 * Результат записывается в вектор result
 * Возвращается отношение скалярных произведений (для формирования верхнетреугольной матрицы)
 */
static double vector_projection(Vector a, Vector b, Vector result)
{
    double r = vector_dotProduct(a, b) / vector_dotProduct(b, b);
    vector_multiplyByScalar(result, r);
    return r;
}

static void vector_sub(Vector minuend, const Vector subtrahend)
{
    for (int i = 0; i < minuend.size; i++)
    {
        minuend.data[i] -= subtrahend.data[i];
    }
}

/*
 * Возвращается скалярное произведение
 */
static double vector_normalize(Vector q, Vector a)
{
    double absValue = sqrt(vector_dotProduct(q, q));
    vector_multiplyByScalar(q, 1/absValue);
    return vector_dotProduct(q, a);
}

/*
 * Реализую модифицированный процесс Грама - Шмидта для QR разложения матрицы А
 * Для последовательного доступа к памяти использую вектора
 * В качестве матрицы R обязательно нужно присылать верхнетреугольную матрицу (например единичную)
 */
static void matrix_QR(Matrix A, Matrix Q, Matrix R)
{
    //ищу ортонормированную матрицу R в виде векторов
    Vector q[A.cols];

    //временный вектор для вычисления проекции
    Vector proj = {A.rows, malloc(A.rows * sizeof(double))};
    for (int i = 0; i < A.cols; i++)
    {
        //временный вектор для последующей нормализации вектора q и вычисления диагонали R
        Vector a = vector_create(A, i);
        //на первом шагу создаю вектора q = a
        q[i] = vector_create(A, i);

        for (int j = 0; j < i; j++)
        {
            vector_copy(proj, q[j]);

            //вычисляю проекцию вектора q на все предыдущие вектора q
            R.data[j * R.cols + i] = vector_projection(q[i], q[j], proj);

            //вычитаю из текущего вектора эту проекцию
            vector_sub(q[i], proj);
        }   //и так по всем векторам

        //теперь необходимо нормализовать этот вектор
        R.data[i * R.cols + i] = vector_normalize(q[i], a);
        free(a.data);
    }
    free(proj.data);

    //перевожу все вектора q в матрицу Q
    for (int col = 0; col < Q.cols; col++)
    {
        for (int row = 0; row < Q.rows; row++)
        {
            Q.data[row * Q.cols + col] = q[col].data[row];
        }
        free(q[col].data);
    }
}


static void matrix_mult_withoutCreate(const Matrix A, const Matrix B, Matrix result)
{
    Matrix transB = matrix_trans(B);
    for (int row = 0; row < result.rows; row++)
    {
        for (int col = 0; col < result.cols; col++)
        {
            result.data[row * result.cols + col] = 0;
            for (int i = 0; i < A.cols; i++)
            {
                result.data[row * result.cols + col] += A.data[row * A.cols + i] * transB.data[col * transB.cols  + i];
            }
        }
    }
    free(transB.data);
}

static bool doublecomparison (double a, double b)
{
    double diff = fabs(a - b);
    const double eps = 0.000001;
    if ( a == b )
    {   //случаи для нулей и бесконечностей
        return true;
    }
    else if ( a == 0 || b == 0 || diff < DBL_MIN )
    {   //близкие к нулю значения сравниваются с абсолютным eps
        return diff <= eps;
    }
    else
    {   //все остальное сравнивнивается относительно
        return diff / (fabs(a) + fabs(b)) <= eps;
    }
}

/*
 * Возвращает true если матрица треугольная
 */
static bool matrix_checkTriangular(const Matrix A)
{
    for (int row = 1; row < A.rows; row++)
    {
        for (int col = 0; col < row; col++)
        {
            if (!doublecomparison(A.data[row * A.cols + col], 0))
            {
                return false;
            }
        }
    }
    return true;
}

/*
 * Функция корректно работает только для матриц с вещественными собственными числами
 * (в теории с помощью этого алгоритма можно найти собственные числа для любой матрицы, но мне не хватает матана)
 * да и вообще сюда бы прикрутить сдвиги, но это работает и ладно - я уже устал и мне надо дм делать(((((
 */
extern Matrix matrix_eigen_values(const Matrix A)
{
    Matrix Q = {A.rows, A.cols, malloc(A.rows * A.cols * sizeof(double))};
    Matrix R = matrix_one(A.rows);

    Matrix temp = {A.rows, A.cols, malloc(A.rows * A.cols * sizeof(double))};
    matrix_datacopy(temp, A);

    //начинаю итерационный процесс
    int i = 0;
    do
    {
        matrix_QR(temp, Q, R);
        matrix_mult_withoutCreate(R, Q, temp);
        i++;
    }
    while ((i < 100) && (!matrix_checkTriangular(temp))); //пока матрица не станет треугольной либо не будет превышен лимит итераций

    free(Q.data);
    free(R.data);

    matrix_print(temp);

    Matrix result = {A.rows, 1, malloc(A.rows * sizeof(double))};

    //собственные значения будут лежат на диагонали
    for (int d = 0; d < A.rows; d++)
    {
        result.data[d] = temp.data[d * temp.cols + d];
    }

    free(temp.data);

    return result;

}
/*
 * Очень плохо
 */
extern Matrix matrix_eigen_vectors(const Matrix A)
{
    Matrix Q = {A.rows, A.cols, malloc(A.rows * A.cols * sizeof(double))};
    Matrix R = matrix_one(A.rows);

    Matrix temp = {A.rows, A.cols, malloc(A.rows * A.cols * sizeof(double))};
    matrix_datacopy(temp, A);

    Matrix result = matrix_one(A.rows);
    Matrix Qtemp = matrix_one(A.rows);

    //начинаю итерационный процесс
    int i = 0;
    do
    {
        //поиск собственных значений только как критерий остановки цикла
        matrix_QR(temp, Q, R);
        matrix_mult_withoutCreate(R, Q, temp);

        matrix_mult_withoutCreate(result, Q, Qtemp);
        matrix_datacopy(result, Qtemp);

        matrix_print(Q);
        i++;
    }
    while ((i < 100) && (!matrix_checkTriangular(temp))); //пока матрица не станет треугольной либо не будет превышен лимит итераций

    free(Q.data);
    free(R.data);

    return result;

}



