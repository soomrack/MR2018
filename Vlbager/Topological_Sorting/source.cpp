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

    //установлю значение каждой вершине равным его позиции в памяти
    //ну и еще рандомно раскидаю по рангам
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
            //ищем существующую вершину на ранге
            //если нашли, то ищем следующий элемент на ранг ниже и связываем их
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

bool graph::dfs(unsigned int curNode, uiVector &stack)
{
    //проверяю цвета текущей вершины
    if (this->nodes[curNode].color == COLOR_OF_NODE_GREY)
    {
        return true;
    }
    if (this->nodes[curNode].color == COLOR_OF_NODE_BLACK)
    {
        return false;
    }
    this->nodes[curNode].color = COLOR_OF_NODE_GREY;

    //запускаю поиск в глубину для всех вершин, на которые ссылается текущая
    unsigned int edgeCount = this->nodes[curNode].edgeSize();
    for (unsigned int i = 0; i < edgeCount; i++)
    {
        unsigned int link = this->nodes[curNode].edge(i);
        if (this->dfs(link, stack))
        {
            return true;
        }
    }
    //если больше идти некуда - заношу в стек и крашу в черный
    stack.push_back(curNode);
    this->nodes[curNode].color = COLOR_OF_NODE_BLACK;
    return false;
}

bool graph::topological_sort(uiVector &result)
{
    uiVector stack;
    for (unsigned int i = 0; i < this->amount; i++)
    {
        if (dfs(i, stack))
        {
            return false;
        }
    }

    //отсортированная последовательность будет лежать в этом векторе
    result.reserve(this->amount);
    for (unsigned int i = 0; i < this->amount; i++)
    {
        unsigned int index = stack.back();
        result[index] = i;
        stack.pop_back();
    }

}
