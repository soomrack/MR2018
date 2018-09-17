//
// Created by science on 16.09.18.
//

#ifndef C_LIBRARY_H
#define C_LIBRARY_H

#endif //C_LIBRARY_H

#include <stdio.h>
#include <math.h>
#define TIME 120
#define DOLG 5000000
#define VKLAD 1000000
#define ARENDA 20000
#define STAVKA 0.18
#define STAVKA2 0.1

long int platezh(long int dolg){
    return (long int)((double)dolg/10.0*STAVKA/(1.0-pow(STAVKA+1.0,-TIME))) ;
}

long int ipoteka(int months){
    if (months == 0) {
        return 1000000;
    }
    else {
        return ipoteka(months-1) + platezh(DOLG);
    }
}

long int procenty(long int vklad){
    return (long int)(STAVKA2*(double)vklad/12.0);
}

long int vklad(int months){
    if (months == 0){
        return VKLAD;
    }
    else {
        int r = vklad(months-1);
        return r + procenty(r);
    }
}

long int arenda(int months){
    if (months == 0){
        return 0;
    }
    else {
        return arenda(months-1) + ARENDA;
    }
}

void main2();

