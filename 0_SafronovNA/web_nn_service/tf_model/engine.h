//
// Created by safic on 02.12.18.
//

#ifndef WEB_NN_SERVICE_ENGINE_H
#define WEB_NN_SERVICE_ENGINE_H

#include "tensorflow/c/c_api.h"

#include "../utils/structures.h"

class Engine{
public:
    bool init();
    void predict_416_x_416(float * input_array, Prediction ** preds, int *preds_len);
    void close();

private:
    bool run_session_416_x_416(float * input_array, TF_Tensor ** output_tensor);
    void output_tensor_to_predictions(float * output_array, Prediction ** preds, int *preds_len);

    TF_Graph* Graph;
    TF_Status* Status;
    TF_ImportGraphDefOptions* Graph_opts;
    TF_SessionOptions* Sess_opts;
    TF_Session* Session;
};

#endif //WEB_NN_SERVICE_ENGINE_H
