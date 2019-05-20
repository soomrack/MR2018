#include <iostream>
#include "graph.h"
#include <random>

int main()
{
    srand(10);
    graph first;

    vector<int> edges;
    edges.emplace_back(0);

    first.addNode("A",edges);
    edges.emplace_back(rand());
    first.addNode("B",edges);
    edges.emplace_back(rand());
    first.addNode("C",edges);

   std::cout<<"hello World";



    return 0;
}