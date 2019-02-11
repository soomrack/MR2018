#include "source.h"


#define COLOR_OF_NODE_GREY 1
#define COLOR_OF_NODE_BLACK 2

static unsigned int random_Range(unsigned int range)
{
    unsigned int result = (rand() % range);
    return result;
}

graph::graph(unsigned int size)
{
    this->nodes = new node[size];

    this->amount = size;

    unsigned int ranks[size][size + 1];
    memset(ranks, 0, size * (size + 1) * sizeof(int));

    //установка значения каждой вершине равной её позиции
    for (unsigned int i = 0; i < size; i++)
    {
        nodes[i].setValue(i);
        unsigned int currentRank = random_Range(size);
        ranks[currentRank][0] += 1;
        ranks[currentRank][ranks[currentRank][0]] = i;
    }

    //создаю случайные связи
    for(unsigned int rank = 0; rank < size - 1; rank++)
    {
        for (unsigned int curNode = 1; curNode < ranks[rank][0] + 1; curNode++)
        {
            //ищется существующая вершина
            //если вершина найдена, то ищется следующий элемент и связывает их
            for (unsigned int rankLow = rank + 1; rankLow < size; rankLow++)
            {
                for (unsigned int link = 1; link < ranks[rankLow][link]; link++)
                {
                    if (random_Range(100) > 50)
                    {
                        nodes[ranks[rank][curNode]].addEdge(ranks[rankLow][link]);
                    }
                }
            }
        }
    }
}

void graph::print()
{
    for (int i = 0; i < this->amount; i++)
    {
        int value = this->nodes[i].getValueOfNode();
        std::cout << "Node " << i << ":  " << value << ";    edges:";
        int edgeCount = this->nodes[i].edgeSize();
        for (int j = 0; j < edgeCount; j++)
        {
            unsigned int link = this->nodes[i].edge((unsigned int) j);
            std::cout << "(" << i << "," << link << ")  ";
        }
        std::cout << std::endl;

    }
}

bool graph::Tarjan(unsigned int curNode, uiVector &stack)
{
    //проверка цвета текущей вершины
    if (this->nodes[curNode].color == COLOR_OF_NODE_GREY)
    {
        return true;
    }
    if (this->nodes[curNode].color == COLOR_OF_NODE_BLACK)
    {
        return false;
    }
    this->nodes[curNode].color = COLOR_OF_NODE_GREY;

    //Поиск в глубину для всех вершин, на которые ссылается текущая
    unsigned int edgeCount = this->nodes[curNode].edgeSize();
    for (unsigned int i = 0; i < edgeCount; i++)
    {
        unsigned int link = this->nodes[curNode].edge(i);
        if (this->Tarjan(link, stack))
        {
            return true;
        }
    }
    //вершина заноится в стек и краится в черный, если идти некуда
    stack.push_back(curNode);
    this->nodes[curNode].color = COLOR_OF_NODE_BLACK;
    return false;
}

bool graph::topological_sort(uiVector &result)
{
    uiVector stack;
    for (unsigned int i = 0; i < this->amount; i++)
    {
        if (Tarjan(i, stack))
        {
            return false;
        }
    }

    //отсортированная последовательность
    result.reserve(this->amount);
    for (unsigned int i = 0; i < this->amount; i++)
    {
        unsigned int index = stack.back();
        result[index] = i;
        stack.pop_back();
    }

}
