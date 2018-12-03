#include <vector>
#include <iostream>
#include <time.h>
#include <cstring>

static unsigned int random_Range(unsigned int range)
{
    unsigned int result = (rand() % range);
    return result;
}

class node
{
private:
    int value;
    std::vector<unsigned int> edges;
    unsigned int parents;
public:

    node(int val)
    {
        this->value = val;
        edges.reserve(0);
        parents = 0;
    }

    node(const node &a)
    {
        this->value = a.value;
        this->edges.reserve(a.edges.size());
    }

    unsigned int edge(unsigned int num)
    {
        return this->edges[num];
    }

    unsigned int edgeCount()
    {
        return this->edges.capacity();
    }

    int getValue()
    {
        return this->value;
    }

    void addEdge(unsigned int link)
    {
        this->edges.push_back(link);
    }

    void addParent()
    {
        parents++;
    }

    unsigned int parentsCount()
    {
        return parents;
    }

    ~node()
    {

    }
};


class graph
{
private:
    std::vector<node> nodes;
public:
    //создам конструктор, который будет создавать ациклический граф со случайными связями
    graph(unsigned int size)
    {
        int a = 0;
        //srand((unsigned int)time(NULL));
        //unsigned int ranks[size][size + 1];

        //memset(ranks, 0, size * (size + 1) * sizeof(int));

        nodes.reserve(size);
        //заполняю значениями равным позициям, заодно присваиваю вершине ее ранг
        for (unsigned int i = 1; i <= size; i++)
        {
            this->nodes[i] = node(i);
            //unsigned int currentRank = random_Range(size);
            //ranks[currentRank][0] += 1;
            //ranks[currentRank][ranks[currentRank][0]] = i;
        }
/*
        //очень плохо написано, но это чисто для теста
        for(unsigned int rank = 0; rank < size - 1; rank++)
        {
            for (unsigned int curNode = 1; curNode < ranks[rank][0] + 1; curNode++)
            {
                //ищем существующую вершину на ранге
                if (ranks[rank][curNode] == 0)
                {
                    continue;
                }
                //если нашли, то ищем следующий элемент на ранг ниже и связываем их
                for (unsigned int rankLow = rank + 1; rankLow < size; rankLow++)
                {
                    for (unsigned int link = 1; link < ranks[rankLow][link]; link++)
                    {
                        if (random_Range(100) > 65)
                        {
                            this->nodes[ranks[rank][curNode]].addEdge(ranks[rankLow][link]);
                            this->nodes[ranks[rankLow][link]].addParent();
                        }
                    }
                }

            }

        }
        //осталось только проверить, есть ли вершины, на которые никто не ссылается и они никуда не ссылаются
        for (unsigned int curNode = 0; curNode < size; curNode++)
        {
            if ( (this->nodes[curNode].parentsCount() == 0) && (this->nodes[curNode].edgeCount() == 0) )
            {
                //в таком случае можно связывать эту вершину с любой вершиной
                unsigned int randomNode = curNode;
                while (randomNode == curNode)
                {
                    randomNode = random_Range(size);
                }
                this->nodes[curNode].addEdge(randomNode);
            }
        }
*/
    }

    void print()
    {
        std::cout << "Nodes:" << std::endl;
        for (int i = 1; i <= this->nodes.capacity(); i++)
        {
            std::cout << i << " - " << this->nodes[i].getValue() << std::endl;
        }
    }
};

