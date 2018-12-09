//
// Created by safic on 19.10.18.
//
#include <iostream>
using namespace std;

#include "tensorflow/c/c_api.h"

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <iterator>

#include "engine.h"
#include "postprocess_utils.h"
#include "../utils/structures.h"

TF_Buffer* read_file(const char* file);

void free_buffer(void* data, size_t length) {
    free(data);
}

static void Deallocator(void* data, size_t length, void* arg) {
    free(data);
    // *reinterpret_cast<bool*>(arg) = true;
}

TF_Buffer* read_file(const char* file) {
    FILE *f = fopen(file, "rb");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);  //same as rewind(f);

    void* data = malloc(fsize);
    fread(data, fsize, 1, f);
    fclose(f);

    TF_Buffer* buf = TF_NewBuffer();
    buf->data = data;
    buf->length = fsize;
    buf->data_deallocator = free_buffer;
    return buf;
}



bool Engine::init() {
    // Use read_file to get graph_def as TF_Buffer*
    TF_Buffer* graph_def = read_file("/home/safic/CPP/web_nn_service/res/yolo.pb");
    Graph = TF_NewGraph();

    //create status to get status of operation
    Status = TF_NewStatus();

    // Import graph_def into graph
    Graph_opts = TF_NewImportGraphDefOptions();
    TF_GraphImportGraphDef(Graph, graph_def, Graph_opts, Status);
    if (TF_GetCode(Status) != TF_OK) {
        fprintf(stderr, "ERROR: Unable to import graph %s", TF_Message(Status));
        return false;
    }
    else {
        fprintf(stdout, "Successfully imported graph\n");
    }


    Sess_opts = TF_NewSessionOptions();
    Session = TF_NewSession(Graph, Sess_opts, Status);

    if (TF_GetCode(Status) != TF_OK) {
        fprintf(stderr, "ERROR: Unable to create session %s", TF_Message(Status));
        return false;
    }
    else {
        fprintf(stdout, "Successfully created session\n");
    }
}

void Engine::close() {
    TF_DeleteSession(Session, Status);
    TF_DeleteSessionOptions(Sess_opts);

    TF_DeleteImportGraphDefOptions(Graph_opts);
    TF_DeleteGraph(Graph);
    TF_DeleteStatus(Status);
}

bool Engine::run_session_416_x_416(float * input_array, TF_Tensor ** output_tensor) {
    // ######################
    // Set up graph input_tensor
    // ######################

    //length of array of input data
    const int input_array_len = 416*416*3;
    const int num_bytes_in = input_array_len * sizeof(float);

    //input array's shape
    int64_t in_dims[] = {1,416,416,3};
    int in_dims_len = 4;

    //get input of the graph
    TF_Operation* input_op = TF_GraphOperationByName(Graph, "input_1");
    TF_Output input_operations[] = {input_op, 0};

    // Create the input tensor using the dimension (in_dims) and size (num_bytes_in)
    // variables created earlier
    TF_Tensor* input_tensor = TF_NewTensor(TF_FLOAT, in_dims, in_dims_len, input_array, num_bytes_in, &Deallocator, 0);
    TF_Tensor ** input_tensors = {&input_tensor};

    // ######################
    // Set up graph output_tensor
    // ######################

    TF_Operation* output_op = TF_GraphOperationByName(Graph, "conv2d_59/BiasAdd");
    TF_Output output_operations[] = {output_op, 0};

    TF_Tensor ** output_tensors = {output_tensor};

    // ######################
    // Run graph
    // ######################

    TF_SessionRun(Session, nullptr,
            // Inputs
                  input_operations, input_tensors, 1,
            // Outputs
                  output_operations, output_tensors, 1,
            // Target operations
                  nullptr, 0, nullptr,
                  Status);

    fprintf(stdout, "Session Run Status: %d - %s\n", TF_GetCode(Status), TF_Message(Status) );

    if(TF_GetCode(Status) == TF_OK) {
        fprintf(stdout, "Successfully run session\n");
        return true;
    }else{
        fprintf(stderr, "Run session with error\n");
        return false;
    }
}

void Engine::output_tensor_to_predictions(float *output_array, Prediction **preds, int *preds_len) {
    fprintf(stdout, "Start: output_tensor_to_predictions\n");

    Prediction *preds_raw = nullptr;
    int preds_raw_len = 0;
    extract_predictions_by_objectness(output_array, &preds_raw, &preds_raw_len);

    fprintf(stdout, "Raw predictions len: %d\n", preds_raw_len);

    non_max_supress(preds_raw, preds_raw_len, preds, preds_len);
    //*preds = preds_raw;
    //*preds_len = preds_raw_len;
    if (preds_raw != nullptr)
        delete[] preds_raw;
}

void Engine::predict_416_x_416(float *input_array, Prediction ** preds, int *preds_len) {
    TF_Tensor * output_tensor = nullptr;

    if (!run_session_416_x_416(input_array, &output_tensor)){
        *preds = nullptr;
        *preds_len = 0;
        return;
    }

    float *output_array = static_cast<float*>(TF_TensorData(output_tensor));

    output_tensor_to_predictions(output_array, preds, preds_len);

    TF_DeleteTensor(output_tensor);
}