//
// Created by work on 29.10.2018.
//

#include "MatrLib.h"


unsigned long long int fact(unsigned int n){
    unsigned long long int out = 1;
    for(int i = 2; i < n; i++)out*=i;
    return  out;
}