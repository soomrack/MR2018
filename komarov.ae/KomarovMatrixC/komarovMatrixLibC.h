#ifndef C_LIBRARY_H
#define C_LIBRARY_H

typedef struct {
unsigned int cols;
unsigned int rows;
double *data;
}Matrix;

// След матрицы
static Matrix matrix_trace(const Matrix A);                                 //

// Определитель матрицы
extern double matrix_determinant(const Matrix A);                           //

// Сумма матриц
const Matrix matrix_sum(const Matrix A, const Matrix B);                   //

// Умножение матриц
static Matrix matrix_mult(const Matrix A, const Matrix B);                  //

// Умножение матрицы на скаляр
static Matrix matrix_mult__scalar(const double scalar, const Matrix A);     //

// Транспонирование матрицы
static Matrix matrix_trans(const Matrix A);                                 //

// Обращение матрицы
static Matrix matrix_invert(const Matrix A);                                //

// Матричная экспонента
static Matrix matrix_exp(const Matrix A);

// Возведение матрицы в степень (натуральное число или 0)
static Matrix matrix_power(const Matrix A, const unsigned int power);       //


// Единичная матрица
static Matrix matrix_one(const unsigned int rows, const unsigned int cols); //

// Нулевая матрица
static Matrix matrix_zero(const unsigned int rows, const unsigned int cols);//

// Матрица составленная из случайных чисел из диапазона [-1, +1]
static Matrix matrix_rand(const unsigned int rows, const unsigned int cols);//


// Вывести матрицу на экран
extern void matrix_print(const Matrix A);                                   //





//ДОПОЛНИТЕЛЬНЫЕ ФУНКЦИИ

//Минор матрицы
static Matrix Minor(const Matrix A, int row, int col);

//Факториал
extern int Factorial(unsigned int k);

//Рандом от -1 до 1
extern double Random_Number();

#endif //C_LIBRARY_H
