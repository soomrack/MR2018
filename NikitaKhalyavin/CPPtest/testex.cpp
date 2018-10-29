#include <stdio.h>
#include <conio.h>
#include "MatrLib.h"


int main(){
   Matrix M1(3,3,1);
   Matrix M2(4,5,0);
   Matrix M3(1,2);

   M1.Print();
   M2.Print();
   M3.Print();

    return  0;
}
