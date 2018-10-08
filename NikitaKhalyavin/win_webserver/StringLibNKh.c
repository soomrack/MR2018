//
// Created by work on 01.10.2018.
//

#include <mem.h>
#include <stdio.h>
#include "StringLibNKh.h"

char* resp(char* input, int len){
    char bufer[len];
    for(int i = 0; i < len; i++){
        if(input[i] == ' '){
            len = i;
            break;
        }
    }
    strncpy(bufer,input,len);
    bufer[len] = '\0';
    return bufer;
}


char* returnGetString(char* input, int len){
    for(int i = 0; i<len; i++){
        if (input[i] == '?') return resp(&input[i + 1], len - i - 1);
    }
    return "0";
}