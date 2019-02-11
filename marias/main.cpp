#include <iostream>
#include <string>
#include <ctime>
#include "matrix.h"

using namespace std;

int main(){
	srand(time(0));
	Matrix a=matrix_one(3,3);
	Matrix b=matrix_one(3,2);
	a.data[0]=-2;
	a.data[5]=41;
	a.data[6]=6;
	b.data[0]=4;
	b.data[5]=6;
	matrix_print(a);
	cout<<endl;
	matrix_print(b);
	cout<<""<<endl;
	Matrix c=matrix_exp(a);
	matrix_print(c);
	//cout<<matrix_determinant(a);
	return 0;
}
