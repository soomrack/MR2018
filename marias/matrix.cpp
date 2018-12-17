#include "matrix.h"
#include <iostream>

using namespace std;

// След матрицы
double matrix_trace(const Matrix A){
	double rez=0;
	if(A.rows==A.cols){
		for(int i=0;i<A.rows;i++)
			rez+=A.data[i*A.rows+i];
			
		return rez;
	}
	cout<<endl<<"not rectangle matrix!"<<endl;
	return 0;
}

// Определитель матрицы
double matrix_determinant(const Matrix A){
	double rez=0;
	Matrix B;
	if(A.rows==A.cols){
		if (A.rows == 1) {
        return A.data[0];
		}
		if (A.rows == 2) {
			return (A.data[0] * A.data[3] - A.data[1] * A.data[2]);
		}
		for (int i = 0; i < A.cols; i++) {
			B=matrix_minor(A, 0, i);
			if(i%2==0){
				rez += A.data[i] * matrix_determinant(B); //
			}else{
				rez -= A.data[i] * matrix_determinant(B); //
			}
			delete[] B.data;
		}
		return rez;
	}
	cout<<endl<<"not rectangle matrix!"<<endl;
	return 0;
}

//уменьшение матрицы
Matrix matrix_minor(Matrix A, int row, int column)
{
    Matrix B;
    B.rows=A.rows-1;
    B.cols=A.cols-1;
    B.data=new double[B.rows*B.cols];
    int r,c;
    r=0;
    for(int i=0;i<row;i++){
		c=0;
		for(int j=0;j<column;j++){
			B.data[r*B.rows+c]=A.data[i*A.rows+j];
			c++;
		}
		for(int j=column+1;j<A.cols;j++){
			B.data[r*B.rows+c]=A.data[i*A.rows+j];
			c++;
		}
		r++;
	}
	
    for(int i=row+1;i<A.rows;i++){
		c=0;
		for(int j=0;j<column;j++){
			B.data[r*B.rows+c]=A.data[i*A.rows+j];
			c++;
		}
		for(int j=column+1;j<A.cols;j++){
			B.data[r*B.rows+c]=A.data[i*A.rows+j];
			c++;
		}
		r++;
	}
    return B;
}


// Сумма матриц
Matrix matrix_sum(const Matrix A, const Matrix B){
	Matrix C;
	if((A.rows==B.rows)&&(A.cols==B.cols)){
		C.data = new double[A.rows*A.cols];
		C.rows=A.rows;
		C.cols=A.cols;
		for(int i=0;i<A.rows*A.cols;i++)
			C.data[i]=A.data[i]+B.data[i];
			
		return C;
	}
	cout<<endl<<"not same size!"<<endl;
	return C;
}

// Умножение матриц
Matrix matrix_mult(const Matrix A, const Matrix B){
	Matrix C;
	if(A.cols==B.rows){
		C.data = new double[A.rows*A.cols];
		C.rows=A.rows;
		C.cols=B.cols;
		for(int i=0;i<C.rows;i++)
			for(int j=0;j<C.cols;j++){
				double sum=0;
				for(int k=0;k<A.cols;k++)
					sum+=A.data[i*A.cols+k]*B.data[k*B.cols+j];
				C.data[i*C.cols+j]=sum;
			}
			
		return C;
	}
	cout<<endl<<"incorrect size!"<<endl;
	return C;
}

// Умножение матрицы на скаляр
Matrix matrix_mult__scalar(const double scalar, const Matrix A){
	Matrix B;
	B.rows=A.rows;
	B.cols=A.cols;
	B.data=new double[B.rows*B.cols];
	for(int i=0;i<B.rows;i++)
		for(int j=0;j<B.cols;j++)
			B.data[i*B.cols+j]=A.data[i*A.cols+j]*scalar;
	return B;
}

// Транспонирование матрицы
Matrix matrix_trans(const Matrix A){
	Matrix B;
	B.rows=A.cols;
	B.cols=A.rows;
	B.data=new double[B.rows*B.cols];
	for(int i=0;i<A.rows;i++)
		for(int j=0;j<A.cols;j++)
			B.data[j*B.cols+i]=A.data[i*A.cols+j];
	return B;
}

// Обращение матрицы
Matrix matrix_invert(const Matrix A){
	Matrix B,C;
	if(A.rows==A.cols){
		double d=matrix_determinant(A);
		if(d!=0){
	B.rows=A.cols;
	B.cols=A.rows;
	B.data=new double[B.cols*B.rows];
	for(int i=0;i<B.rows;i++)
		for(int j=0;j<B.cols;j++){
			C=matrix_minor(A, i, j);
			B.data[i*B.cols+j]=matrix_determinant(C);
			delete[] C.data;
		}
		
	for(int i=0;i<B.rows;i++)
		for(int j=0;j<B.cols;j++){
			if(((i%2==0)&&(j%2==1))||((i%2==1)&&(j%2==0)))
			B.data[i*B.cols+j]=B.data[i*B.cols+j];
		}
		
		C=matrix_trans(B);
		B=matrix_mult__scalar(1.0/d,C);
		delete[] C.data;
		return B;
	}else
	cout<<endl<<"determinant = 0 !!!"<<endl;
	return A;
}
	cout<<endl<<"not rectangle matrix!"<<endl;
	return A;
}

// Матричная экспонента
Matrix matrix_exp(const Matrix A){
	double d=1;
	double k=0;
	Matrix sum,B,C;
	sum=matrix_zero(A.rows,A.cols);
	if(A.rows==A.cols){
		while(d>0.000000001){
			C=matrix_power(A,k);
			B=matrix_mult__scalar(d,C);
			delete[] C.data;
			C=matrix_sum(sum,B);
			delete[] B.data;
			delete[] sum.data;
			sum=C;
			k++;
			d/=k;
		}	
		return sum;
	}
	cout<<endl<<"not rectangle matrix!"<<endl;
	return A;
}

// Возведение матрицы в степень (натуральное число или 0)
Matrix matrix_power(const Matrix A, const unsigned int power){
	Matrix B,C;
	if(A.rows==A.cols){
		if(power>0){
		B.rows=A.rows;
		B.cols=A.cols;
		B.data=new double[B.rows*B.cols];
		for(int i=0;i<B.rows*B.cols;i++)
			B.data[i]=A.data[i];
			
		for(int i=1;i<power;i++){
			C=matrix_mult(B,A);
			delete[] B.data;
			B=C;
		}
	}else{
		B=matrix_one(A.rows,A.cols);
	}
			
		return B;
	}
	cout<<endl<<"not rectangle matrix!"<<endl;
	
	return B;
}


// Единичная матрица
Matrix matrix_one(const unsigned int rows, const unsigned int cols){
	Matrix A;
	A.rows=rows;
	A.cols=cols;
	A.data=new double[rows*cols];
	if(rows==cols){//проверка на квадратность матрицы
		for(int i=0;i<rows;i++)
			for(int j=0;j<cols;j++){
				if(i!=j){
					A.data[i*cols+j]=0;
				}else{
					A.data[i*cols+j]=1;
				}
			}
		}else{//если указана не квадратная матрица то просто заполним единицами
			for(int i=0;i<rows;i++)
				for(int j=0;j<cols;j++)
					A.data[i*cols+j]=1;
		}
	return A;
}

// Нулевая матрица
Matrix matrix_zero(const unsigned int rows, const unsigned int cols){
	Matrix A;
	A.rows=rows;
	A.cols=cols;
	A.data=new double[rows*cols];
	for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			A.data[i*cols+j]=0;
	return A;
}

// Матрица оставленная из случайных чисел из диапазона [-1, +1]
Matrix matrix_rand(const unsigned int rows, const unsigned int cols){
	Matrix A;
	A.rows=rows;
	A.cols=cols;
	A.data=new double[rows*cols];
	for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			A.data[i*cols+j]=fRand(-1,1);
	return A;
}


// Вывести матрицу на экран
void matrix_print(const Matrix A){
	for(int i=0;i<A.rows;i++){
		cout<<endl;
		for(int j=0;j<A.cols;j++)
			cout<<A.data[i*A.cols+j]<<" ";
		}
	cout<<endl;
}


double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
