#include <vector>
#include <iostream>
#include <cstring>

typedef std::vector<unsigned int> uiVector;

class node
{
private:
    int value;
    uiVector edges;
public:

    int color;

    node()
    {
        this->value = 0;
        this->color = 0;
    }

    node(int val)
    {
        this->value = val;
        this->color = 0;
    }

    void setValue(int val)
    {
        this->value = val;
    }

    unsigned int edge(unsigned int num)
    {
        return this->edges[num];
    }

    unsigned int edgeSize()
    {
        return this->edges.size();
    }

    int getValueOfNode()
    {
        return this->value;
    }

    void addEdge(unsigned int link)
    {
        edges.push_back(link);
    }

    ~node()
    {
        edges.clear();
    }
};

class graph
{
private:
    unsigned int amount;
    node * nodes;
    bool dfs(unsigned int curNode, uiVector &stack);
public:

    graph(unsigned int size);

    void print();

    bool topological_sort(uiVector &result);

    ~graph()
    {
        delete(nodes);
    }
};



