//
//  Header.h
//  Data Structure
//
//  Created by Zhou, Yifan on 8/8/18.
//  Copyright © 2018 Zhou, Yifan. All rights reserved.
//

#ifndef Header_h
#define Header_h

class MinIntHeap {
    int capacity;
    int size;
    int* items;

    void ensureCapacity();//Ensure enough capacity
    
    int getLeftChildIndex(int parentIndex);
    int getRightChildIndex(int parentIndex);
    int getParentIndex(int childIndex);
    
    bool hasLeftChild(int index);
    bool hasRightChild(int index);
    bool hasParent(int index);
    
    int leftChild(int index);//Return the value of its left child
    int rightChild(int index);//Return the value of its right child
    int parent(int index);//Return the value of its parent

    void swapIndex(int index_1, int index_2);//Swap the items stored in 2 indices
    
public:
    MinIntHeap(): capacity(10), size(0){items = new int[capacity];}//Create an empty heap
    MinIntHeap(MinIntHeap& heap);//Create from an existing heap
    
    int get_size() const {return size;}
    int* get_items() const {return items;}
    
    int peek();//Return the smallest value
    int poll();//Pop the smallest item
    void add(int item);
    void heapifyDown();
    void heapifyUp();
};


#endif /* Header_h */
