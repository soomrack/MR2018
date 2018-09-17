#include <stdio.h>
#include <math.h>
#include <locale.h>
double proc_division(int proc) {
	return (1.0 + (double)proc / 1200);
}
double vklad(double extramoney, int proc, int month) {
	double procent = proc_division(proc);
	if (month > 0) {
		extramoney = extramoney * procent;
		return vklad(extramoney, proc, month - 1);
	}
	else return extramoney;
}
double raznost(int sum, int proc, int i, int pay_rent) {
	double raz = vklad(sum, proc, i + 1) - vklad(sum, proc, i);
	return(raz - pay_rent);
}
double dohody_all_time(sum, proc, renta, year) {
	double dohod = 0;
	for (int q = 1; q <= year * 12; q++) {
		dohod += raznost(sum, proc, q, renta);
	}
	return dohod;
}

int main() {
	setlocale(LC_ALL, "Rus");//перевод на русский
	int sum_vklad = 1000000;
	int procent_vklad = 10;
	int years = 10;
	int rent = 20000;
	struct First {
		int sum;
		int pr;
	};
	struct First A;
	struct First array_struct[50];
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 4; j++) {
			A.sum = (i + 5) * 1000000;
			A.pr = j + 10;
			array_struct[5 * i + j] = A;
		}
	}
	double array[50];
	/*for (int n = 0; n< 50; n++) {
		printf("%d\t",array_struct[n].sum);
		printf("%d\n", array_struct[n].pr);
	}*/for (int n = 0; n < 50; n++) {
		array[n] = dohody_all_time(array_struct[n].sum, array_struct[n].pr, rent, years);
	}
	int c;
	for (int i = 0; i < 50; i++) {
		for (int j = 48; j >= i; j--) {
			if (array[j] > array[j + 1])
			{
				c = array[j];
				array[j] = array[j + 1];
				array[j + 1] = c;
			}
		}
		printf("%d\t", i + 1);
		printf("%d\t", array_struct[i].sum);
		printf("%d\t", array_struct[i].pr);
		printf("%lf\n", array[i]);
	}
	system("pause");
	return 0;
}