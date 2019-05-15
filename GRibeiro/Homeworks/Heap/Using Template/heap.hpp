#ifndef __HEAP_HPP__
#define __HEAP_HPP__
#include <iostream>

template <class T>
class Heap {    
    private:
        T *_heap;
        int _size;
        int _last;
        void fixUpHeap();
        void fixDownHeap();   
        const T getLeftChild(int parent) const;
        const T getRightChild(int parent) const;
        const T getParent(int child) const;
        
    public:
        Heap(int n);
        void insert(T key);
        const T maximum() const;
        void extrac_max();
        void show();
        ~Heap();
};

template <class T>
Heap<T>::Heap(int n) {
    this->_heap = new T[n];
    this->_size = n; 
    this->_last = 0;
}

template <class T>
const T Heap<T>::getParent(int child) const {
    return (child % 2 == 0) ? (child /2 ) -1 : child/2;
}

template <class T>
const T Heap<T>::getLeftChild(int parent) const {
    return 2*parent +1;
}

template <class T>
const T Heap<T>::getRightChild(int parent) const {
    return 2*parent+2;
}

template <class T>
void Heap<T>::fixUpHeap() {
    int child = this->_last-1;
    int parent = getParent(child);

    while (this->_heap[child] > this->_heap[parent] && child >=0 && parent >= 0) {
        // std::cout << "entry\n";
        std::swap(this->_heap[child], this->_heap[parent]);
        child = parent;
        parent = getParent(child);
    } 
}


template <class T>
void Heap<T>::insert(T key) {
    if(this->_last+1 >= this->_size) {
        std::cout << "A Heap is Full\n";
        return;
    }
    this->_heap[this->_last++] = key;
    this->fixUpHeap();
}

template <class T>
const T Heap<T>::maximum() const {
    return this->_heap[0];
}

template <class T>
void Heap<T>::fixDownHeap() {
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

template <class T>
void Heap<T>::extrac_max() {
    int child = this->_last-1;
    std::swap(this->_heap[child], this->_heap[0]);
    int value = this->_heap[this->_last--];
    this->fixDownHeap();
}

template <class T>
void Heap<T>::show() {
    for(int x=0; x<this->_last; x++ ) {
        std::cout << (x>0 ? " " : "") << this->_heap[x];
    }
    std::cout << std::endl;
}

template <class T>
Heap<T>::~Heap() {
    delete[] this->_heap;
}


#endif