//
// Created by safic on 02.12.18.
//

#include "../../tf_model/postprocess_utils.h"

#include <stdio.h>

int main(){
    fprintf(stdout, "sigmoid(%.2f) = %.2f\n", -10.0, sigmoid(-10));
    fprintf(stdout, "sigmoid(%.2f) = %.2f\n", 0.1, sigmoid(0.1));
    fprintf(stdout, "sigmoid(%.2f) = %.2f\n", 1.0, sigmoid(1.0));
    fprintf(stdout, "sigmoid(%.2f) = %.2f\n", 10.0, sigmoid(10.0));
}
