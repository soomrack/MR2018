//
// Created by natas on 02.06.2019.
//

#include "Deikstra.h"
#include <iostream>
using namespace std;

Deikstra::Deikstra(int matrix[SIZE][SIZE]) {
    for (int i = 0; i<SIZE; i++) { //заполнение матрицы связей
        for(int j=0; j<SIZE; j++) {
            weight_matrix[i][j] = matrix[i][j];
        }
    }
    for (int i =0; i< SIZE; i++){ //инициализация вершин и расстояний
        min_distance[i] = INFINITY;
        vertex[i] = NOT_VISITED;
    }

}

void Deikstra::find_short_way(int end) {
    print_matrix();
    find_shortcuts();
    print_shortcuts();
    build_path(end);
}

void Deikstra::print_matrix() {
    cout << "Weight matrix:"<<endl;
    for (int i = 0; i<SIZE; i++) {
        for (int j = 0; j<SIZE; j++) {
            cout<<weight_matrix[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void Deikstra::find_shortcuts() {
    int min_index ;
    int min_weight;
    int temp;
    min_distance[0] = 0; //задаем минимальную метку первой (или любой другой, от которой хотим найти расстояния) вершины
    do {
        min_index = INFINITY;
        min_weight = INFINITY;
        for (int i = 0; i < SIZE; i++) { //обходим все вершины по порядку нумерации
            if ((vertex[i] == NOT_VISITED) && (min_distance[i] < min_weight)) { // Если вершину ещё не обошли и вес меньше min
                min_weight = min_distance[i];
                min_index = i;
            }

        }
        if (min_index != INFINITY)
        {
            for (int i = 0; i<SIZE; i++)
            {
                if (weight_matrix[min_index][i] > 0) {
                    temp = min_weight + weight_matrix[min_index][i]; // Добавляем найденный минимальный вес к текущему весу вершины
                    if (temp < min_distance[i])  // и сравниваем с текущим минимальным весом вершины
                    {
                        min_distance[i] = temp;
                    }
                }
            }
            vertex[min_index] = VISITED;
        }
    } while (min_index < INFINITY);
}

void Deikstra::print_shortcuts() {
    cout<< endl<<"Shortcuts:"<<endl;
    for (int i = 0; i<SIZE; i++) {
        cout<<i<< "    ";
    }
    cout<<endl;
    for (int i = 0; i<SIZE; i++) {
        cout<<min_distance[i]<< "    ";
    }
    cout<<endl;
}

void Deikstra::build_path(int end) {
    int visited_vertex[SIZE]; //массив посещенных вершин
    int end_index = end-1; //индекс конечной вершины
    visited_vertex[0] = end; //начальный элемент - конечная вершина
    int vertex_counter = 1; //хранит индекс предыдущей вершины
    int weight = min_distance[end_index]; //вес конечной вершины
    while (end_index > 0){
        for (int i=0; i< SIZE; i++) {
            if (weight_matrix[end_index][i] != 0) { //если есть связь между вершинами
                int temp = weight - weight_matrix[end_index][i]; // определяем вес пути из предыдущей вершины
                if (temp == min_distance[i]) // если вес совпал с рассчитанным
                {                 // значит из этой вершины и был переход
                    weight = temp; // сохраняем новый вес
                    end_index = i;       // сохраняем предыдущую вершину
                    visited_vertex[vertex_counter] = i + 1; // и записываем ее в массив
                    vertex_counter++;
                }
            }

        }
    }
    cout<<endl<<"The shortest way is "<<endl;
    for (int i = vertex_counter-1; i>=0; i--)
        cout<<visited_vertex[i]<<"   ";
}

