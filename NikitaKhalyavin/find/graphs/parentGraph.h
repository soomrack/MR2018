//
// Created by Nikita on 06.05.2019.
//

#ifndef MR2018_PARENTGRAPH_H
#define MR2018_PARENTGRAPH_H

#endif //MR2018_PARENTGRAPH_H

class Node {
protected:
    Node * connections;
public:
    virtual void connect_to(Node * newOut) = 0;
    void * data;
};