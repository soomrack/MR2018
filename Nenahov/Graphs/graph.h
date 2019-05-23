//
// Created by prog on 22.04.2019.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include <vector>
#include <string>

using namespace std;


struct node
{
    string name;
    int orderNumber;


};


class graph {
public:
    graph() = default;
    ~graph() = default;

    void addNode(const string name,const vector<int> edges);
    void deleteNode(const string name);
    vector<int> findShortestWay(const int node);   //Dijkstra algorithm
    int getSize();

private:
    /*vector<vector<int>> adjacencyMatrix;
    vector <node> nodes;*/

    int  adjacencyMatrix [5][5] ={
            {0, 2, 3, 7, 1},
            {2, 0, 5, 8, 3},
            {3, 5, 0, 4, 0},
            {7, 8, 4, 0, 5},
            {1, 3, 0, 5, 0}
    };
    int size = 5;





};


#endif //GRAPHS_GRAPH_H
