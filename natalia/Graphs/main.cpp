//#include "stdafx.h"
#include <iostream>
#include "Deikstra.h"
using namespace std;



int main() {
    int matrix[SIZE][SIZE] = {{0, 7, 9, 0, 0, 14},
                              {7, 0, 10, 15, 0, 0},
                              {9, 10, 0, 11, 0, 2},
                              {0, 15, 11, 0, 6, 0},
                              {0, 0, 0, 6, 0, 9},
                              {14 ,0, 2, 0, 9, 0}};
    Deikstra* graph = new Deikstra(matrix);
    graph->find_short_way(4); //Кратчайший путь от 1-й вершины до любой другой

}