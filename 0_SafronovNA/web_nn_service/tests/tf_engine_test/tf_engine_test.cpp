//
// Created by safic on 02.12.18.
//

#include "../../tf_model/engine.h"

#include <stdio.h>

int main(){
    Engine engine = Engine();

    engine.init();

    const int input_array_len = 416*416*3;
    float * input_array = new float[input_array_len];

    Prediction * preds = nullptr;
    int preds_len = 1;

    engine.predict_416_x_416(input_array, &preds, &preds_len);

    fprintf(stdout, "preds_len %d \n", preds_len);

    engine.close();
}
