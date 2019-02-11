#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[10]={0, -2, 3, 4, -8, 0, 2, 4, -1, 3};
    unsigned int size = 10;
    unsigned int left_current = 0;
    unsigned int right_answer = 0;
    unsigned int left_answer = 0;
    int s_current = 0;
    int s_answer = array[0];
    for (unsigned int i = 0; i < size; i++){
        s_current += array[i];
        if(s_current > s_answer){
            left_answer = left_current;
            right_answer = i;
            s_answer = s_current;
        }
        if(s_current < 0){
            s_current = 0;
            left_current = i + 1;
        }
    }
    printf("Recieved subarray [%d;%d].\nThe sum is %d\n", left_answer, right_answer, s_answer);

    return 0;
}