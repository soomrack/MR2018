//
// Created by admin on 17.09.2018.
//

#include "kurshakov_lib.h"
#include <math.h>
//
long int payment(long int dolg, double stavka, int time){
    double monthpercent = stavka / 12.0;
    double coef = (monthpercent * pow(1.0 + monthpercent, time))/(pow(1.0 + monthpercent, time) - 1.0);
    long int monthly = (long int) (coef * (double) dolg);
    return (monthly * time);
}