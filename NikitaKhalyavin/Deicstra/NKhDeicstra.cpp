//
// Created by work on 11.11.2018.
//

#include "NKhDeicstraLib.h"
#include <iostream>
#include "../CPPtest/MatrLib.h"

using namespace std;

int main() {

    Matrix times(9,9,0);

    for(int mn = 100; mn < 500; mn += 50)
        times.data[((mn - 100) / 50 + 1)*9] = mn;

    for(int n = 1000; n < 5000; n += 500) {

        times.data[(n - 1000) / 500 + 1] = n;

        for(int mn = 100; mn < 500; mn += 50) {


            Matrix MConnection(n, n, -50);
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j <= i + mn / 2; j++) {
                    if (j < n)
                        MConnection.data[i * n + j] = 10;
                    else
                        MConnection.data[(j - n) * n + i] = 10;
                }
            }
            //MConnection.data[n-1] = 10;


            MConnection = MConnection.Trans();
            MConnection.beSymmetric();
            MConnection = MConnection.Trans();

            point Graph2[n];


            for (int i = 0; i < n; i++) {
                List temp(2 * mn);
                int k = 0;
                for (int j = 0; j < n; j++) {
                    if (MConnection.data[i * n + j] > 5) {
                        temp.dataNames[k] = j;
                        temp.dataLength[k] = (int) MConnection.data[i * n + j];
                        k++;
                        //if(k==mn)break;
                    }
                }
                List temp2(k);
                memcpy(temp2.dataNames, temp.dataNames, k * sizeof(int));
                memcpy(temp2.dataLength, temp.dataLength, k * sizeof(int));
                point tempP(temp2);
                Graph2[i] = tempP;
            }

            int start;
            start = clock();
            int stop;

            Graph2[0].DeicstraAlg(Graph2, n, 0);

            stop = clock();
            //Graph2[0].printResults(Graph2, n);
            //Graph2[0].printWayTo(Graph2, n / 2 , 0);

            printf("time for Deicstra: %d\n", stop - start);

            times.data[((mn - 100) / 50 + 1)*9 + (n - 1000) / 500 + 1] = stop - start;
        }
    }

    times.Print();
/*
    point Graph[6];               //граф объявляется как массив неинициализированных вершин

    List input0(3);               //создание и инициализация списка нулевой вершины
    input0.dataNames[0]  = 1;
    input0.dataLength[0] = 7;
    input0.dataNames[1]  = 2;
    input0.dataLength[1] = 9;
    input0.dataNames[2]  = 5;
    input0.dataLength[2] = 14;
    point p0(input0);             //создание инициализированной вершины
    Graph[0] = p0;                //копирование вершины в нулевую вершину массива

    List input1(3);               //аналогично - инициализация остальных вершин
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


    Graph[0].DeicstraAlg(Graph, 6, 0);      //выполнение алгоритма Дейкстры
    Graph[0].printResults(Graph, 6);        //вывод длины кратчайшего пути для всех вершин
    Graph[0].printWayTo(Graph, 4, 0);       //вывод пути в 4 вершину из 0
*/
    return 0;
}