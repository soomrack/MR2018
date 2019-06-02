//
// Created by natas on 02.06.2019.
//

#ifndef GRAPHS_DEIKSTRA_H
#define GRAPHS_DEIKSTRA_H

#define SIZE 6
#define INFINITY 10000
#define VISITED 0
#define NOT_VISITED 1


class Deikstra{
public:
    Deikstra(int matrix[SIZE][SIZE]);
    void find_short_way(int end);
    int weight_matrix[SIZE][SIZE];
    void print_matrix();
    void print_shortcuts();
private:
    int min_distance[SIZE];
    int vertex[SIZE];
    void find_shortcuts();
    void build_path(int end);

};



#endif //GRAPHS_DEIKSTRA_H
