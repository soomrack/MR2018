//
// Created by work on 11.11.2018.
//

#include <limits.h>
#include <cstring>
#include <stdio.h>

#ifndef MR2018_NKHDEICSTRALIB_H
#define MR2018_NKHDEICSTRALIB_H

#endif //MR2018_NKHDEICSTRALIB_H


class List {            //хранит список рёбер, выходящих из одной вершины графа
private:
    int listSize;
public:
    int * dataNames;
    int * dataLength;

    List (int size): listSize(size) {           //конструктор
        dataNames = new int[size];
        dataLength = new int[size];
    }

    List (List& Arg){                           //конструктор крпий
        listSize = Arg.listSize;
        dataNames = new int[listSize];
        memcpy(dataNames, Arg.dataNames,listSize*sizeof(int));
        dataLength = new int[listSize];
        memcpy(dataLength, Arg.dataLength,listSize*sizeof(int));
    }

    List (){                                    //конструктор пустого экземпляра класса для объявления по умолчанию
        dataNames  = (int*)0;                   //используется при объявлени массива экземпляров класса point
        dataLength = (int*)0;
    }

    int getSize(){
        return listSize;
    }

    void operator = (List& Arg){                //оператор присвоения для переписывания пустого экземпляра класса
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

    ~List(){                                   //деструктор
        if(dataNames != (int*)0)
            delete dataNames;
        if(dataLength != (int*)0)
            delete dataLength;
    }
};






class point {                                 //класс, экземпляр которого соответствует вершине графа
private:
    bool isNotVisited;
    int label;
    int way;                                 //номер вершины, путь из которой можно добраться с весом label
    List ConnectTo;

    bool areNotAllVisited(point * Graph, int size){     //метод, проверяющий условие завершения работы алгоритма - посещение всех вершин
        bool NotAllVisits = 0;
        for(int i = 0; i < size; i++){
            NotAllVisits |= Graph[i].isNotVisited;
        }
        return  NotAllVisits;
    }

    int getMinNumber(point * Graph, int size){      //метод, возвращающий номер вершины, которая должна быть посещена следующей
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

    void Visit(point * Graph, int thisName) {        //метод, осуществляющий посещение вершины
        for (int i = 0; i < ConnectTo.getSize(); i++) {
            int temp = ConnectTo.dataNames[i];
            if (Graph[temp].isNotVisited) {
                if (ConnectTo.dataLength[i] + label < Graph[ConnectTo.dataNames[i]].label) {
                    Graph[ConnectTo.dataNames[i]].label = ConnectTo.dataLength[i] + label;
                    Graph[ConnectTo.dataNames[i]].way = thisName;
                }
            }
        }
        isNotVisited = 0;
    }

public:
    point(){                                        //пустой конструктор для объявления в массиве

    }

    point(point& Arg){                              //конструктор копий
        isNotVisited = Arg.isNotVisited;
        label = Arg.label;
        way = Arg.way;
        ConnectTo = Arg.ConnectTo;
    }

    void operator = (point& Arg) {      //оператор присвоения
        isNotVisited = Arg.isNotVisited;
        label = Arg.label;
        way = Arg.way;
        ConnectTo = Arg.ConnectTo;
    }

    point(List& connection): ConnectTo(connection) {   //конструктор по сформированному списку подключений
        label = INT_MAX;
        way = 0;
        isNotVisited = 1;
    }

    void printResults(point * Graph, int size){     //вывод минимального веса пути в каждую вершину
        for(int i = 0; i < size; i++){
            printf("%d\t%d\t%d\n", i, Graph[i].label,Graph[i].way);
        }
    }

    void printWayTo(point * Graph, int TargetName, int StartName){      //вывод кратчайшего пути в заданную вершину
        int pointer = TargetName;
        printf("//////////\n");
        while(pointer != StartName){
            printf("%d\t%d\n", pointer, Graph[pointer].label);
            pointer = Graph[pointer].way;
        }
        printf("%d\t%d\n", pointer, Graph[pointer].label);
    }

    void DeicstraAlg(point * Graph, int size, int startNumber){     //функция, исполняющая алгоритм Дейкстры
        Graph[startNumber].label = 0;
        while(Graph[0].areNotAllVisited(Graph,6)){
            int thisPoint = Graph[0].getMinNumber(Graph,6);
            if(thisPoint > size) return;
            Graph[thisPoint].Visit(Graph, thisPoint);
        }
    }
};
