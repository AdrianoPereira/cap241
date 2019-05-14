#include "heap.hpp"
#include <iostream>

Heap::Heap(int n) {
    this->_heap = new int[n];
    this->_size = n; 
    this->_last = 0;
}

const int Heap::getParent(int child) const {
    return (child % 2 == 0) ? (child /2 ) -1 : child/2;
}

const int Heap::getLeftChild(int parent) const {
    return 2*parent +1;
}

const int Heap::getRightChild(int parent) const {
    return 2*parent+2;
}

void Heap::fixUpHeap() {
    int child = this->_last-1;
    int parent = getParent(child);

    while (this->_heap[child] > this->_heap[parent] && child >=0 && parent >= 0) {
        // std::cout << "entry\n";
        std::swap(this->_heap[child], this->_heap[parent]);
        child = parent;
        parent = getParent(child);
    } 
}

void Heap::insert(int key) {
    if(this->_last+1 >= this->_size) {
        std::cout << "A Heap is Full\n";
        return;
    }
    
    this->_heap[this->_last++] = key;
    this->fixUpHeap();
    // int parent = this->_last;

    // if(this->_last <= this->_size-1) {
    //     this->_heap[this->_last] = key;
        
    //     while(this->_last > 0 && this->_heap[parent] > this->_heap[parent/2]) {
    //         if(this->_heap[parent] > this->_heap[parent/2]) {
    //             std::swap(this->_heap[parent], this->_heap[parent/2]);
    //             parent /= 2;
    //         }
    //     }
    // }
    // this->_last++;
}

const int Heap::maximum() const {
    return this->_heap[0];
}

void Heap::fixDownHeap() {
    int parent = 0;

    while(true) {
        int left = getLeftChild(parent);
        int right = getRightChild(parent);
        int length = this->_last;
        int largest = parent;

        if (left < length && this->_heap[left] > this->_heap[largest])
            largest = left;

        if (right < length && this->_heap[right] > this->_heap[largest])
            largest = right;

        if (largest != parent) {
            std::swap(this->_heap[largest], this->_heap[parent]);
            parent = largest;
        } else {
            break;
        }
    }
}

void Heap::extrac_max() {
    int child = this->_last-1;
    std::swap(this->_heap[child], this->_heap[0]);

    int value = this->_heap[this->_last--];

    this->fixDownHeap();
    
}

Heap::~Heap() {
    delete[] this->_heap;
}

void Heap::show() {
    for(int x=0; x < this->_last; ++x) {
        std::cout << (x>0 ? " " : "")  << this->_heap[x];
    }
    std::cout << std::endl;
}

