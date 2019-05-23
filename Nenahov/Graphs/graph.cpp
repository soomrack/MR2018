//
// Created by prog on 22.04.2019.
//

#include "graph.h"



void graph::addNode(const string name,const vector<int> edges)
{
    node newNode;
    nodes.emplace_back(newNode);
    nodes[nodes.size() - 1].name = name;

    unsigned int size = nodes.size();
    adjacencyMatrix.resize(size);
    for(unsigned int i = 0;i < size;i ++)
    {
        adjacencyMatrix[i].resize(size);
    }


    for(unsigned int i = 0; i < size - 1;i ++)
    {
        adjacencyMatrix[size - 1][i] = edges[i];
        adjacencyMatrix[i][size - 1] = edges[i];
    }
    adjacencyMatrix[size - 1][size - 1] = 0;
}

/*void graph::deleteNode(const string name)
{
    int orderOfRemovableNode;
    for(unsigned int i = 0;i < nodes.size();i ++)
    {
        if(nodes[i].name == name)
        {
            orderOfRemovableNode = i;
            break;
        }
    }

    adjacencyMatrix.erase(orderOfRemovableNode);

}*/

vector<int> graph::findShortestWay(const int targetNode)
{
    vector<int> distance()

}



