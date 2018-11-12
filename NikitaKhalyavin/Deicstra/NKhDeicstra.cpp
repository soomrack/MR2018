//
// Created by work on 11.11.2018.
//

#include "NKhDeicstraLib.h"
#include <iostream>

using namespace std;

int main() {
    point Graph[6];

    List input0(3);
    input0.dataNames[0]  = 1;
    input0.dataLength[0] = 7;
    input0.dataNames[1]  = 2;
    input0.dataLength[1] = 9;
    input0.dataNames[2]  = 5;
    input0.dataLength[2] = 14;
    point p0(input0);
    p0.setLabel(0);
    Graph[0] = p0;

    List input1(3);
    input1.dataNames[0]  = 3;
    input1.dataLength[0] = 15;
    input1.dataNames[1]  = 2;
    input1.dataLength[1] = 10;
    input1.dataNames[2]  = 0;
    input1.dataLength[2] = 7;
    point p1(input1);
    Graph[1] = p1;

    List input2(4);
    input2.dataNames[0]  = 0;
    input2.dataLength[0] = 9;
    input2.dataNames[1]  = 1;
    input2.dataLength[1] = 10;
    input2.dataNames[2]  = 3;
    input2.dataLength[2] = 11;
    input2.dataNames[3]  = 5;
    input2.dataLength[3] = 2;
    point p2(input2);
    Graph[2] = p2;

    List input3(3);
    input3.dataNames[0]  = 1;
    input3.dataLength[0] = 15;
    input3.dataNames[1]  = 2;
    input3.dataLength[1] = 11;
    input3.dataNames[2]  = 4;
    input3.dataLength[2] = 6;
    point p3(input3);
    Graph[3] = p3;

    List input4(2);
    input4.dataNames[0]  = 3;
    input4.dataLength[0] = 6;
    input4.dataNames[1]  = 5;
    input4.dataLength[1] = 9;
    point p4(input4);
    Graph[4] = p4;

    List input5(3);
    input5.dataNames[0]  = 0;
    input5.dataLength[0] = 14;
    input5.dataNames[1]  = 2;
    input5.dataLength[1] = 2;
    input5.dataNames[2]  = 4;
    input5.dataLength[2] = 9;
    point p5(input5);
    Graph[5] = p5;

    while(Graph[0].areNotAllVisited(Graph,6)){
        Graph[Graph[0].getMinNumber(Graph,6)].Visit(Graph);
    }

    Graph[0].printLabels(Graph, 6);

    return 0;
}