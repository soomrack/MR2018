//
// Created by safic on 02.12.18.
//

#ifndef WEB_NN_SERVICE_POSTPROCESS_UTILS_H
#define WEB_NN_SERVICE_POSTPROCESS_UTILS_H

#include "../utils/config.h"
#include "../utils/structures.h"

double sigmoid(double x);

void non_max_supress(Prediction * preds, int preds_len, Prediction ** not_supressed, int * not_supressed_len);
void extract_predictions_by_objectness(float *output_array, Prediction ** preds, int * preds_len);

#endif //WEB_NN_SERVICE_POSTPROCESS_UTILS_H
