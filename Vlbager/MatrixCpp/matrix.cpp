
#include "matrix.hpp"
#include <iostream>
#include <ctime>
#include <cmath>
#include <float.h>

class myvector
{
private:
    dVector data;
public:

    myvector(unsigned int size)
    {
        this->data.reserve(size);
    }

    myvector(Matrix &A, unsigned int col)
    {
        int cols = A.getCols();
        this->data = A.getVector(col);
    }

    myvector(myvector &a)
    {
        this->data = a.data;
    }

    ~myvector()
    {
        this->data.clear();
    }

    double getValue(unsigned int row)
    {
        return this->data[row];
    }

    friend double dotProduct (myvector &a, myvector &b);

    myvector operator * (double scalar)
    {
        for (int i = 0; i < this->data.size(); i++)
        {
            this->data[i] = this->data[i] * scalar;
        }
    }

    myvector operator - (myvector &subtrahend)
    {
        myvector result = (*this);
        for (int i = 0; i < result.data.size(); i++)
        {
            result.data[i] -= subtrahend.data[i];
        }
        return result;
    }
};

double dotProduct(myvector &a, myvector &b)
{
    double result = 0;
    unsigned int size = a.data.size();
    for (int i = 0; i < size; i++)
    {
        result += a.data[i] * b.data[i];
    }
    return result;
}

/*
 * Возвращается скалярное произведение
 */
double vector_normalize(myvector q, myvector a)
{
    double absValue = sqrt(dotProduct(q, q));
    q = q * (1/absValue);
    return dotProduct(q, a);
}

/*
 * Проекция вектора а на вектор б
 * Результат записывается в вектор result
 * Возвращается отношение скалярных произведений (для формирования верхнетреугольной матрицы)
 */
double vector_projection(myvector &a, myvector &b, myvector &result)
{
    double r = dotProduct(a, b) / dotProduct(b, b);
    result = result * r;
    return r;
}

void Matrix::one()
{
    for (int row = 0; row < this->rows; row++)
    {
        for (int col = 0; col < this->cols; col++)
        {
            if (row == col)
            {
                this->data[row * this->cols + col] = 1.0;
            }
            else
            {
                this->data[row * this->cols + col] = 0.0;
            }
        }
    }
}

void Matrix::zero()
{
    for (int row = 0; row < this->rows; row++)
    {
        for (int col = 0; col < this->cols; col++)
        {
            this->data[row * this->cols + col] = 0.0;
        }
    }
}

static double get_rand_range(int min, int max)
{
    return ( (double) (rand() % (1000 * max - 1000 * min + 1) + 1000 * min) / 1000);
}

void Matrix::rand()
{
    static bool ifNotInit = true;
    if (ifNotInit)
    {
        srand( (unsigned int) time(nullptr));
        ifNotInit = false;
    }

    for ( int row = 0; row < this->rows; row++)
    {
        for ( int col = 0; col < this->cols; col++)
        {
            this->data[row * this->cols + col] = get_rand_range(-1, 1);
        }
    }
}

void Matrix::print()
{
    for (int row = 0; row < rows; row++)
    {
        std::cout << "|";
        for(int col = 0; col < cols; col++)
        {
            std::cout << " " << data[row * cols + col] << " ";
        }
        std::cout << "|" << std::endl;
    }
}


Matrix Matrix::operator + (const Matrix &B)
{
    Matrix result(this->rows, this->cols);
    for (int row = 0; row < this->rows; row++)
    {
        for (int col = 0; col < this->cols; col++)
        {
            result.data[row * result.cols + col] = this->data[row * this->cols + col] + B.data[row * B.cols + col];
        }
    }
    return result;
}

Matrix Matrix::operator - (const Matrix &B)
{
    Matrix result(this->rows, this->cols);
    for (int row = 0; row < this->rows; row++)
    {
        for (int col = 0; col < this->cols; col++)
        {
            result.data[row * result.cols + col] = this->data[row * this->cols + col] - B.data[row * B.cols + col];
        }
    }
    return result;
}

Matrix Matrix::trans()
{
    Matrix result(this->rows, this->cols);
    for (int row = 0; row < result.rows; row++)
    {
        for (int col = 0; col < result.cols; col++)
        {
            result.data[row * result.cols + col] = this->data[col * this->cols + row];
        }
    }
    return result;
}

Matrix Matrix::operator * (Matrix &B)
{
    Matrix result(this->rows, B.cols);
    Matrix transB = B.trans();
    for (int row = 0; row < result.rows; row++)
    {
        for (int col = 0; col < result.cols; col++)
        {
            result.data[row * result.cols + col] = 0;
            for (int i = 0; i < this->cols; i++)
            {
                result.data[row * result.cols + col] += this->data[row * this->cols + i] * transB.data[col * transB.cols  + i];
            }
        }
    }
    return result;
}

Matrix Matrix::operator * (double scalar)
{
    Matrix result(this->rows, this->cols);

    for (int row = 0; row < result.rows; row++)
    {
        for (int col = 0; col < result.cols; col++)
        {
            result.data[row * result.cols + col] = scalar * this->data[row * this->cols + col];
        }
    }
    return result;
}

void Matrix::swapRows(unsigned int row1, unsigned int row2)
{
    double temp;
    for (int col = 0; col < this->cols; col++)
    {
        temp = this->data[row1 * this->cols + col];
        this->data[row1 * this->cols + col] = this->data[row2 * this->cols + col];
        this->data[row2 * this->cols + col] = temp;
    }
}

Matrix Matrix::invert()
{
    Matrix A2 = *this;

    Matrix result(this->rows);
    result.one();

    //прямой ход
    for (unsigned int diagonal = 0; diagonal < A2.cols; diagonal++)
    {
        //ищу ненулевой элемент и меняю строки местами, если нужно
        if (A2.data[diagonal * A2.rows + diagonal] == 0)
        {
            for (unsigned int nozerorow = diagonal + 1; nozerorow < A2.rows; nozerorow++)
            {
                if (A2.data[nozerorow * A2.rows + diagonal] == 0)
                {
                    continue;
                }
                A2.swapRows(diagonal, nozerorow);
                A2.swapRows(diagonal, nozerorow);
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
    return result;
}

Matrix Matrix::forMinor(unsigned int mrow, unsigned int mcol)
{
    Matrix result(this->rows - 1, this->cols - 1);
    int counter = 0;
    for (int row = 0; row < this->rows; row++)
    {
        if (row == mrow)
        {
            continue;
        }
        for (int col = 0; col < this->cols; col++)
        {
            if (col == mcol)
            {
                continue;
            }
            result.data[counter] = this->data[row * (this->cols) + col];
            counter++;
        }
    }

    return result;
}

double Matrix::determinant()
{
    if (this->rows == 1)
    {
        return this->data[0];
    }

    double result = 0;
    int sign = 1;

    for (unsigned int col = 0; col < this->cols; col++)
    {
        Matrix temp = this->forMinor(0, col);

        result += sign * this->data[col] * temp.determinant();

        sign = -sign;
    }
    return result;
}

double Matrix::Enorm()
{
    double result = 0;
    for (int row = 0; row < this->rows; row++)
    {
        for (int col = 0; col < this->cols; col++)
        {
            result += (this->data[row * this->cols + col] * this->data[row * this->cols + col]);
        }
    }
    return sqrt(result);
}

Matrix Matrix::exp()
{
    //чтобы не копить слишком большую ошибку, создам матрицу А2 в 2^p раз меньше А
    double norm = this->Enorm();
    uint64_t p;
    if (norm < 4)
    {
        p = 1;
    }
    else
    {
        p = (uint64_t) norm;
    }

    Matrix A2 = (*this) * (1/pow(2.0, p));

    //вычисляем матричную экспоненту от A2

    Matrix exp(this->rows);
    exp.one();
    Matrix temp = exp;
    int k = 0;
    do
    {
        k++;
        temp = temp * (1.0/k);
        temp = temp * A2;
        exp = exp + temp;
    }
    while ( (k < 10000) );


    //теперь чтобы перейти обратно к матрице А, нужно перемножить exp саму на себя p раз
    for (int i = 0; i < p; i++)
    {
        exp = exp * exp;
    }

    return exp;
}

Matrix Matrix::power(unsigned int power)
{
    Matrix result = *this;

    if (power == 1)
    {
        return result;
    }

    if (power == 0)
    {
        result.one();
        return result;
    }

    for (int i = 1; i < power; i++)
    {
        result = result * (*this);
    }
    return result;
}

void Matrix::QR(Matrix &Q, Matrix &R)
{
    //ищу ортонормированную матрицу Q в виде векторов
    myvector * q;
    q = new myvector((unsigned int)this->cols);

    for (unsigned int i = 0; i < this->cols; i++)
    {
        //временный вектор для последующей нормализации вектора q и вычисления диагонали R
        myvector a((*this), i);
        //на первом шагу создаю вектора q = a
        q[i] = a;

        for (unsigned int j = 0; j < i; j++)
        {
            myvector proj = q[j];

            //вычисляю проекцию вектора q на все предыдущие вектора q
            R.data[j * R.cols + i] = vector_projection(q[i], q[j], proj);

            //вычитаю из текущего вектора эту проекцию
            q[i] = q[i] - proj;
        }   //и так по всем векторам

        //теперь необходимо нормализовать этот вектор
        R.data[i * R.cols + i] = vector_normalize(q[i], a);
    }

    //перевожу все вектора q в матрицу Q
    for (unsigned int col = 0; col < Q.cols; col++)
    {
        for (unsigned int row = 0; row < Q.rows; row++)
        {
            Q.data[row * Q.cols + col] = q[col].getValue(col);
        }
    }
    delete q;
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
bool Matrix::checkTriangular()
{
    for (int row = 1; row < this->rows; row++)
    {
        for (int col = 0; col < row; col++)
        {
            if (!doublecomparison(this->data[row * this->cols + col], 0))
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
 * иногда не сходится (из-за отсутствия сдвигов)
 */
Matrix Matrix::eigenValues()
{
    Matrix Q(this->rows);
    Matrix R(this->rows);

    Matrix temp = (*this);

    //начинаю итерационный процесс
    int i = 0;
    do
    {
        temp.QR(Q, R);
        temp = R * Q;
        i++;
    }
    while ((i < 10000) && (!temp.checkTriangular()));
    //пока матрица не станет треугольной либо не будет превышен лимит итераций

    Matrix result(this->rows, 1);

    //собственные значения будут лежат на диагонали
    for (int d = 0; d < this->rows; d++)
    {
        result.data[d] = temp.data[d * temp.cols + d];
    }

    return result;
}

/*
 * Все работает для матриц, содержащих только вещественные собственные числа
 */
Matrix Matrix::eigenVectors()
{
    Matrix Q(this->rows);
    Matrix R(this->rows);

    Matrix temp = (*this);

    Matrix result(this->rows);
    result.one();

    //начинаю итерационный процесс
    int i = 0;
    do
    {
        temp.QR(Q, R);
        temp = R * Q;

        result = result * Q;

        i++;
    }
    while ((i < 10000) && (!temp.checkTriangular()));
    //пока матрица не станет треугольной либо не будет превышен лимит итераций


    return result;
}
