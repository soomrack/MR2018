//
// Created by safic on 02.12.18.
//

#include <math.h>
#include <algorithm>

#include "postprocess_utils.h"
#include "../utils/config.h"


void sort( int * arr, int size )
{
    int i = 1;
    int tmp;
    while(i < size){
        if(i == 0 || arr[i-1] <= arr[i]){
            i++;
        } else{
            tmp = arr[i-1];
            arr[i-1] = arr[i];
            arr[i] = tmp;
            i--;
        }
    }
}

int box_intersection(Box box1, Box box2){
    if (box1.l >= box2.r || box2.l >= box1.r || box1.t >= box2.b || box2.t >= box1.b){
        return 0;
    }

    int xx[] = {box1.l, box1.r, box2.l, box2.r};
    sort(xx, 4);

    int yy[] = {box1.t, box1.b, box2.t, box2.b};
    sort(yy, 4);

    int intersection = (xx[2] - xx[1]) * (yy[2] - yy[1]);

    return intersection;
}

double IOU(Box box1, Box box2){
    int intersection = box_intersection(box1,box2);

    int box1_area = (box1.b - box1.t) * (box1.r - box1.l);
    int box2_area = (box2.b - box2.t) * (box2.r - box2.l);
    int union_ = box1_area + box2_area - intersection;

    double intersection_over_union = intersection / (union_ + 0.00001);

    return intersection_over_union;
}


void non_max_supress(Prediction * preds, int preds_len, Prediction ** not_supressed, int * not_supressed_len){
    bool * is_supressed = new bool[preds_len];

    for (int i = 0; i < preds_len; i++){
        is_supressed[i] = false;
    }

    for (int i = 0; i < preds_len; i++){
        for (int j = i+1; j < preds_len; j++){
            if(is_supressed[i] || is_supressed[j])
                continue;

            if (preds[i].class_ != preds[j].class_)
                continue;

            double iou = IOU(preds[i].box, preds[j].box);
            if (iou < IOU_THRESHOLD)
                continue;

            if (preds[i].class_probability < preds[j].class_probability){
                is_supressed[i] = true;
            }else{
                is_supressed[j] = true;
            }
        }
    }

    int not_supressed_len_tmp = 0;
    for (int i = 0; i < preds_len; i++){
        if (!is_supressed[i])
            not_supressed_len_tmp += 1;
    }

    Prediction * not_supressed_tmp = new Prediction[not_supressed_len_tmp];
    *not_supressed = not_supressed_tmp;
    *not_supressed_len = not_supressed_len_tmp;

    int c = 0;
    for (int i = 0; i < preds_len; i++){
        if (!is_supressed[i]){
            not_supressed_tmp[c] = preds[i];
            c++;
        }
    }

    delete[] is_supressed;
}

double sigmoid(double x){
    return 1.0 / (1.0 + exp(-x));
}

void extract_predictions_by_objectness(float *output_array, Prediction ** preds, int * preds_len){
    const int array_h = 13; //height
    const int array_w = 13; //width
    const int array_c = 3; //channels
    const int preds_max_len = array_h*array_w*array_c;
    const int one_pred_len = 85;

    const int image_h = 416;
    const int image_w = 416;

    bool *is_object = new bool[preds_max_len];

    for (int i = 0; i < array_h; i++){
        for (int j = 0; j < array_w; j++){
            for (int k = 0; k < array_c; k++){
                float *this_pred_raw = output_array + i*array_w*array_c*one_pred_len +
                                                      j*array_c*one_pred_len +
                                                      k*one_pred_len;

                float objectness_raw = this_pred_raw[4];
                double objectness = sigmoid(objectness_raw);
                if (objectness > OBJECTNESS_THRESHOLD){
                    is_object[i*array_w*array_c + j*array_c + k] = true;
                }else{
                    is_object[i*array_w*array_c + j*array_c + k] = false;
                }
            }
        }
    }

    int preds_len_tmp = 0;
    for (int i = 0; i < preds_max_len; i++){
        if (is_object[i])
            preds_len_tmp += 1;
    }

    Prediction * preds_tmp = new Prediction[preds_len_tmp];
    *preds = preds_tmp;
    *preds_len = preds_len_tmp;

    int c = 0;
    for (int i = 0; i < array_h; i++){
        for (int j = 0; j < array_w; j++){
            for (int k = 0; k < array_c; k++){
                if (!is_object[i*array_w*array_c + j*array_c + k])
                    continue;

                float *this_pred_raw = output_array + i*array_w*array_c*one_pred_len +
                                       j*array_c*one_pred_len +
                                       k*one_pred_len;

                float tx = this_pred_raw[0];
                float ty = this_pred_raw[1];
                float tw = this_pred_raw[2];
                float th = this_pred_raw[3];

                double bx = j + sigmoid(tx);
                double by = i + sigmoid(ty);
                double bw = ANCHORS[k].w * exp(tw);
                double bh = ANCHORS[k].h * exp(th);

                int t = image_h/array_h * by - bh/2;
                int b = image_h/array_h * by + bh/2;
                int l = image_w/array_w * bx - bw/2;
                int r = image_w/array_w * bx + bw/2;

                preds_tmp[c].box.t = std::max(0, t);
                preds_tmp[c].box.b = std::min(image_h, b);
                preds_tmp[c].box.l = std::max(0, l);
                preds_tmp[c].box.r = std::min(image_w, r);

                preds_tmp[c].objectness = sigmoid(this_pred_raw[4]);

                int max_class = 0;
                float max_class_probability = -INFINITY;
                for (int i = 0; i < one_pred_len-5; i++){
                    int this_class_probability = this_pred_raw[5+i];
                    if (this_class_probability > max_class_probability){
                        max_class_probability = this_class_probability;
                        max_class = i;
                    }
                }

                preds_tmp[c].class_ = max_class;
                preds_tmp[c].class_probability = sigmoid(this_pred_raw[5+max_class]);

                c++;
            }
        }
    }

    delete[] is_object;
}