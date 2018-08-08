//
//  heap.cpp
//  Data Structure
//
//  Created by Zhou, Yifan on 8/8/18.
//  Copyright © 2018 Zhou, Yifan. All rights reserved.
//
#include "heap.h"
#include <stdio.h>
using namespace std;

// Constructors
// Create from an existing heap
MinIntHeap::MinIntHeap(MinIntHeap& heap): size(heap.get_size()) {
    int * items_to_copy = heap.get_items();
    capacity = size >= 10? size : 10;
    items = new int[capacity];
    for (int i = 0; i < size; i++){
        items[i] = items_to_copy[i];
    }
}

void MinIntHeap::ensureCapacity() {
    if (size == capacity) {
        int *tmp = new int[2 * capacity];
        for (int i = 0; i < size; i++){
            tmp[i] = items[i];
        }
        capacity *= 2;
        delete [] items;
        items = tmp;
    }
}
    
int MinIntHeap::getLeftChildIndex(int parentIndex) {
    return 2 * parentIndex + 1;
}
int MinIntHeap::getRightChildIndex(int parentIndex) {
    return 2 * parentIndex + 2;
}
int MinIntHeap::getParentIndex(int childIndex) {
    return (childIndex - 1) / 2;
}
    
bool MinIntHeap::hasLeftChild(int index) {
    return getLeftChildIndex(index) < size;
}
bool MinIntHeap::hasRightChild(int index) {
    return getRightChildIndex(index) < size;
}
bool MinIntHeap::hasParent(int index) {
    return getParentIndex(index) >= 0;
}
    
int MinIntHeap::leftChild(int index) {
    if (hasLeftChild(index)) {
        return items[getLeftChildIndex(index)];
    }
    else return -1;
}
    
int MinIntHeap::rightChild(int index) {
    if (hasRightChild(index)) {
        return items[getRightChildIndex(index)];
    }
    else return -1;
}
    
int MinIntHeap::parent(int index) {
    if (hasParent(index)) {
        return items[getParentIndex(index)];
    }
    else return -1;
}

// Swap the items stored in 2 indices
void MinIntHeap::swapIndex(int index_1, int index_2) {
    int tmp = items[index_1];
    items[index_1] = items[index_2];
    items[index_2] = tmp;
}

    
int MinIntHeap::peek() {
    if (size == 0) {
        throw "Empty Heap";
    }
    return items[0];
}
    
int MinIntHeap::poll() {
    if (size == 0) {
        throw "Empty Heap";
    }
    int item = items[0];
    items[0] = items[size - 1];
    size--;
    heapifyDown();
    return item;
}

void MinIntHeap::add(int item) {
    ensureCapacity();
    items[size] = item;
    size++;
    heapifyUp();
}
    
void MinIntHeap::heapifyDown() {
    int index = 0;
    while (hasLeftChild(index)) {
        int smallerChildIndex = getLeftChildIndex(index);
        if (hasRightChild(index) && rightChild(index) < leftChild(index)) {
            smallerChildIndex = getRightChildIndex(index);
        }
        if (items[index] < items[smallerChildIndex]) {
            break;
        }
        else {
            swapIndex(index, smallerChildIndex);
        }
    }
}
    
void MinIntHeap::heapifyUp() {
    int index = size - 1;
    while (hasParent(index) && parent(index) > items[index]) {
        swapIndex(getParentIndex(index), index);
        index = getParentIndex(index);
    }
}

