
#include "lib.h"
#include <iostream>
#include <cstdlib>

int main() {
    int arr[23] = {2, 5, 8, 1, 0, 3, 5, 6, 8, 5, 7, 1, 3, 6, 9, 2, 4, 3, 7, 5, 6, 9, 4};
    //int arr[23] = {0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2};
    //int arr[23] = {7,9,1,3,4,6,8,5,2,6,1,3,7,2,4,9,8,5,7,5,8,6,1};

    //print_array(arr,23);

    /*int index = linear_search(1,arr,5);
    std::cout<<index<<std::endl;

    bubble_sort(arr,5);
    print_array(arr,5);

    index = binary_search(2,arr,5);
    std::cout<<index<<std::endl;

    element_replacement(3,arr,5);
    print_array(arr,5);

    element_replacement(5,arr,5);
    print_array(arr,5);


    element_replacement(8,arr,5);
    print_array(arr,5);*/

    //MergeSort(arr, 0, 23);
    //InsertSort(arr, 0, 23);
    //Timsort(arr, 23);
    //HeapSort(arr, 23);
   // print_array(arr, 23);

   /* Tree mytree;


    int temp;
    for (int i = 5; i > 0; i--)
    {
        temp = i*i;
        mytree.insert(i, &temp);
    }

    mytree.infix_traverse(mytree.root);
    std::cout<<'\n';
    mytree.remove(mytree.root->key);
    //удаление всего дерева??


    for (int i = 20; i > 5; i--)
    {
        int k = arr[i];
        mytree.insert(k, &i);
    }

    mytree.infix_traverse(mytree.root);
    mytree.remove(9);
    mytree.infix_traverse(mytree.root);
    node result = mytree.search(8);
    std::cout<<'\n';
    std::cout<< result.value;
    mytree.remove(mytree.root->key);*/


   /* Graph newGraph;

    char nodes[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    for (int i = 0; i < 8; i++)
    {
        newGraph.addVertex(&nodes[i]);
    }
    newGraph.addEdge(0,1,2);
    newGraph.addEdge(1,2,2);
    newGraph.addEdge(1,3,2);
    newGraph.addEdge(2,7,4);
    newGraph.addEdge(3,6,3);
    newGraph.addEdge(7,6,2);
    newGraph.addEdge(7,4,4);
    newGraph.addEdge(5,6,2);

    newGraph.printPath(newGraph.FordBellman(&newGraph, 5), 5, 0);*/

    BinaryMinHeap newHeap(10);
    int keys[10] = {5, 9, 2, 1, 6, 3, 8, 4, 11, 7};
    int values[10] = {55, 92, 21, 15, 67, 31, 80, 43, 110, 74};

    for (int i = 0; i < 10; i++)
    {
        int key = keys[i];
        int * data;
        data = &values[i];
        newHeap.Insert(key, data);
    }

    /*HeapNode * foundNode = newHeap.Search(6);
    std::cout << "key: 6  value: " << * foundNode->data << "\n";*/

    HeapNode minNode = newHeap.extractMin();
    std::cout << "min node key: " << minNode.key << "  data: " << *minNode.data << "\n";

    minNode = newHeap.extractMin();
    std::cout << "min node key: " << minNode.key << "  data: " << *minNode.data << "\n";

    minNode = newHeap.extractMin();
    std::cout << "min node key: " << minNode.key << "  data: " << *minNode.data << "\n";

    return 0;
}