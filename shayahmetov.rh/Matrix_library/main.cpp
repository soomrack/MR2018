#include <iostream>
#include "matrix.h"

int main() {
        Mx::Matrix a(3, 3);
        {
                double arr[9] = {5, 7, 5, 6, 8, 11, 55, 4, 35};
                a.set(arr);
        }
        a.print();
        a.Minor(0, 0).print();
        //a.print();
        std::cout<<a.determinant()<<std::endl;
        /*std::cout<<a.trace()<<std::endl;
        Mx::Matrix b(3, 3);
        b.rand();
        b.print();
        Mx::Matrix c(4, 4);
        c.zero();
        c.print();
        Mx::Matrix d(5, 5);
        d.one();
        d.print();
        Mx::Matrix e(3,3);
        double arr[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        e.set(arr);
        Mx::Matrix f(3,3);
        Mx::Matrix a1=a;
        a1.print();
        a1.sum(e);
        a1.print();
        b.mult(a);
        b.print();
        a1.mult_scalar(2);
        a1.print();
        Mx::Matrix a2=a;
        a2.power(2);
        a2.print();
        a2.trans();
        a2.print();
        std::cout<<a2.determinant()<<std::endl;
        Mx::Matrix M(3, 3);
        Mx::Matrix r(3,3);
        r.rand();
        r.print();
        M = mexp(r);
        M.print();*/

        return 0;
}