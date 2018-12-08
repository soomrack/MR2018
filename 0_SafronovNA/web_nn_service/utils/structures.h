//
// Created by safic on 02.12.18.
//

#ifndef WEB_NN_SERVICE_STRUCTURES_H
#define WEB_NN_SERVICE_STRUCTURES_H

typedef struct{
    int w;
    int h;
} Anchor;

const Anchor ANCHORS[] = {
        {116,90},
        {156,198},
        {373,326}
};

typedef struct{
    int t;
    int b;
    int l;
    int r;
} Box;

typedef struct{
    float objectness;
    Box box;
    int class_;
    double class_probability;
} Prediction;

#endif //WEB_NN_SERVICE_STRUCTURES_H
