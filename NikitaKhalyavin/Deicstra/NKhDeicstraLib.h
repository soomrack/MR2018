//
// Created by work on 11.11.2018.
//

#include <limits.h>
#include <cstring>

#ifndef MR2018_NKHDEICSTRALIB_H
#define MR2018_NKHDEICSTRALIB_H

#endif //MR2018_NKHDEICSTRALIB_H


class List {
private:
    int listSize;
public:
    int * dataNames;
    int * dataLength;

    List (int size): listSize(size) {
        dataNames = new int[size];
        dataLength = new int[size];
    }

    List (){
        dataNames  = (int*)0;
        dataLength = (int*)0;
    }

    int getSize(){
        return listSize;
    }

    void operator = (List& Arg){
        listSize = Arg.listSize;
        if(dataNames != (int*)0)
            delete dataNames;
        dataNames = new int[listSize];
        memcpy(dataNames, Arg.dataNames,listSize*sizeof(int));
        if(dataLength != (int*)0)
            delete dataLength;
        dataLength = new int[listSize];
        memcpy(dataLength, Arg.dataLength,listSize*sizeof(int));
    }

    ~List(){
        delete dataNames;
        delete dataLength;
    }
};




class point {
private:
    bool isNotVisited;
    int label;
    List ConnectTo;
public:
    point(){

    }
    point(List& connection): ConnectTo(connection){
        label = INT_MAX;
        isNotVisited = 1;
    }

    void setLabel(int value){
        label = value;
    }

    bool areNotAllVisited(point * Graph, int size){
        bool NotAllVisits = 0;
        for(int i = 0; i < size; i++){
            NotAllVisits |= Graph[i].isNotVisited;
        }
        return  NotAllVisits;
    }

    int getMinNumber(point * Graph, int size){
        int min = INT_MAX;
        int out = 0;
        for(int i = 0; i < size; i++){
            if(Graph[i].isNotVisited)
                if(Graph[i].label < min){
                    out = i;
                    min = Graph[i].label;
                }
        }
        return out;
    }

    void Visit(point * Graph){
        for(int i = 0; i < ConnectTo.getSize(); i++){
            int temp = ConnectTo.dataNames[i];
            if(Graph[temp].isNotVisited){
                if(ConnectTo.dataLength[i] + label < Graph[ConnectTo.dataNames[i]].label)
                    Graph[ConnectTo.dataNames[i]].label = ConnectTo.dataLength[i] + label;
            }
        }
        isNotVisited = 0;
    }

    void operator = (point& Arg) {
        isNotVisited = Arg.isNotVisited;
        label = Arg.label;
        ConnectTo = Arg.ConnectTo;
    }

    ~point() {

    }
};