#include <iomanip>
#include <ctime>
#include <iostream>
#include "matrixcpplib.h"
#include <cstdlib>
MyMatrix MyMatrix::matrix_rand(const unsigned int Matrows, const unsigned int Matcols) {
    if(rows!=Matrows) {
        std::cout<<"Nesootvetstvie podanoy matrix and arguments\nmatrix will have"<<Matrows<<"rows"<<std::endl;
        rows=Matrows;
    }
    if(cols!=Matcols) {
        std::cout<<"Nesootvetstvie podanoy matrix and arguments\nmatrix will have"<<Matcols<<"cols"<<std::endl;
        cols=Matcols;
    }
    srand(static_cast<unsigned int>(time(nullptr)));
    for(unsigned int i=0;i<Matrows*Matcols;i++){
        data[i]=(double)(-100+rand()%200)/100;
    }
    return *this;
}

void MyMatrix::matrix_print() {
    for(unsigned int i=0;i<rows*cols;i++){
        if(i%cols==0) std::cout<<std::endl;
            printf("%10.2lf\t",data[i]);
        }
    std::cout<<std::endl;
}
/*
 * for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++)
            std::cout << std::setw(8) << std::setprecision(3) << setiosflags(std::ios::fixed | std::ios::showpoint)
                      << A.data[j+i*A.rows];
        std::cout << "\n";
    }
 */

double MyMatrix::matrix_trace() {
    if (rows!=cols){
        std::cout<<"matrix isn't a square matrix\n";
        return 0;
    }
    double trace=0;
    for(unsigned int i=0;i<rows;i++)
        trace+=data[i+i*rows];
    return trace;
}



void MyMatrix::matrix_one(const unsigned int Matrows, const unsigned int Matcols){
    if(rows!=Matrows) {
        std::cout<<"Nesootvetstvie podanoy matrix and arguments\nmatrix will have"<<Matrows<<"rows"<<std::endl;
        rows=Matrows;
    }
    if(cols!=Matcols) {
        std::cout<<"Nesootvetstvie podanoy matrix and arguments\nmatrix will have"<<Matcols<<"cols"<<std::endl;
        cols=Matcols;
    }
    if (rows!=cols){
        std::cout<<"matrix isn't a square matrix, "
                   "\nyou should give equal number of rows and cols to parametres of the function\n";
        return;
    }
    free(data);
    data=(double *)malloc(Matcols*Matrows*sizeof(double));
    for(unsigned int i=0;i<rows*cols;i++) {
        if(i%(cols+1)==0)
            data[i] = 1;
        else
            data[i] = 0;
    }
}


void MyMatrix::matrix_zero(const unsigned int Matrows, const unsigned int Matcols) {
    if(rows!=Matrows) {
        std::cout<<"Nesootvetstvie podanoy matrix and arguments\nmatrix will have"<<Matrows<<"rows"<<std::endl;
        rows=Matrows;
    }
    if(cols!=Matcols) {
        std::cout<<"Nesootvetstvie podanoy matrix and arguments\nmatrix will have"<<Matcols<<"cols"<<std::endl;
        cols=Matcols;
    }
    free(data);
    data=(double *)malloc(cols*rows*sizeof(double));
    for(unsigned int i=0;i<rows*cols;i++)
            data[i] = 0;
    }

void swap(double *a,double *b){
    double c=*a;
    *a=*b;
    *b=c;
}

MyMatrix MyMatrix::matrix_trans() {
    if (rows!=cols){
        std::cout<<"matrix isn't a square matrix\n";
        return *this;
    }
    MyMatrix ext1(rows,cols);
    for(int i=0;i<cols*rows;i++) ext1.data[i]=data[i];
    for(int i=1,n=1;i<rows*cols-1;i++) {
           swap(&ext1.data[i],&ext1.data[(i%cols)*cols+(i/cols)]);//&data[((i+1)/n)*(cols-1)])
            if((i+1)%cols==0) {
                i=n*cols+n;
                n++;
            }
    }
    return ext1;
}


MyMatrix MyMatrix::matrix_mult__scalar(const double scalar) {
    MyMatrix ext2(rows,cols);
        for(int i=0;i<cols*rows;i++)
            ext2.data[i]=scalar*data[i];
    return ext2;
}

MyMatrix MyMatrix::matrix_sum(const MyMatrix B) {
    if(B.cols!=cols) {
        std::cout<<"mismatch columns in matrix A and B\n";
        return *this;
    }
    if(B.rows!=rows) {
        std::cout<<"mismatch rows in matrix A and B\n";
        return *this;
    }
    MyMatrix ext3(rows,cols);
        for(int i=0;i<rows*cols;i++)
            ext3.data[i]=data[i]+B.data[i];
    return ext3;
}


MyMatrix MyMatrix::matrix_mult(const MyMatrix B) {
    if(cols!=B.rows) {
        std::cout<<"mismatch rows in matrix A and columns in matrix B\n";
        return *this;
    }
    MyMatrix ext4(rows,B.cols);
    for(int i=0;i<rows*B.cols;i++) {
            for(int n=0;n<cols;n++) {
                ext4.data[i]+=data[(i/B.cols)*cols+n]*B.data[i%B.cols+n*B.cols];
            }
    }
    return ext4;
}

MyMatrix MyMatrix::matrix_power(const int power){
    if (rows!=cols){
        std::cout<<"matrix isn't a square matrix\n";
        return *this;
    }
    MyMatrix ext5(rows,cols);
    ext5=*this;
    if(power>0) {
        for (unsigned int i = 0; i < power - 1; i++) {
            ext5=matrix_mult(ext5);
        }
    }
    else std::cout<<"Power cannot be unpositive\n";
    return ext5;
}

MyMatrix MyMatrix::matrix_exp() {
    MyMatrix ext6(rows,cols);
    double F=1;
    for(int i=1;i<10;i++) {
        for (int j=2;j<=i;j++){
            F=F*j;
        }
        MyMatrix pow(rows,cols);
        pow = matrix_power(i);
        MyMatrix powdiv(rows,cols);
        powdiv = pow.matrix_mult__scalar(1/F);
        ext6 = powdiv.matrix_sum(ext6);
    }
    return ext6;
}


MyMatrix MyMatrix::matrix_invert() {
    MyMatrix ext7(rows,cols);
    double temp;
    MyMatrix B(rows,cols);
    B.matrix_one(rows,cols);
    for (int k = 0; k < rows; k++) {
        temp = data[k+k*rows];
        for (int j = 0; j < rows; j++) {
            data[j+k*rows] =data[j+k*rows] / temp;
            B.data[j+k*B.rows] = B.data[j+k*B.rows] / temp;
        }
        for (int i = k + 1; i < rows; i++) {
            temp = data[k+i*rows];
            for (int j = 0; j < rows; j++) {
                data[j+i*rows] -= data[j+k*rows] * temp;
                B.data[j+i*B.rows] -= B.data[j+k*B.rows] * temp;
            }
        }
    }
    for (int k = rows - 1; k > 0; k--) {
        for (int i = k - 1; i >= 0; i--) {
            temp = data[k+i*rows];
            for (int j = 0; j < rows; j++) {
                data[j+i*rows] -= data[j+k*rows] * temp;
                B.data[j+i*B.rows] -= B.data[j+k*B.rows] * temp;
            }
        }
    }
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < rows; j++)
            data[j+i*rows] = B.data[j+i*B.rows];
    std::cout << "\n\n";
    std::cout << " inverted matrix " << "\n\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++)
            std::cout << std::setw(8) << std::setprecision(3) << setiosflags(std::ios::fixed | std::ios::showpoint)
                      << data[j+i*rows];
        std::cout << "\n";
    }
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < rows; j++)
            ext7.data[j + rows * i] = data[j+i*rows];
    return ext7;
}

double det(MyMatrix A,unsigned int size){
    if (size == 1)
        return A.data[0];
    if (size == 2)
        return (A.data[3] * A.data[0]) - (A.data[1] * A.data[2]);
    double determinant = 0, sign = 1;
    for (int i = 0; i < size; i++){
        MyMatrix minor(size-1,size-1);
        for (int m = 1; m < size; m++){
            for (int j = 0, k = 0; j < size; j++, k++){
                if (j == i){
                    k--;
                    continue;
                }
                minor.data[k+(m-1)*(size-1)] = A.data[j+m*size];
            }
        }
        determinant += (sign * A.data[i] * det(minor,size - 1));
        sign *= -1;
    }
    return determinant;
}

double MyMatrix::matrix_determinant(){
    if (rows!=cols){
        std::cout<<"matrix isn't a square matrix\n";
        return 0;
    }
    double determinant = det(*this, cols);
    return determinant;
}
