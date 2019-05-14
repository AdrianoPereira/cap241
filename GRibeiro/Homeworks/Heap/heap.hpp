#ifndef __HEAP_HPP__
#define __HEAP_HPP__

// template <class T>
class Heap {    
    private:
        int *_heap;
        int _size;
        int _last;
        void fixUpHeap();
        void fixDownHeap();   
        const int getLeftChild(int parent) const;
        const int getRightChild(int parent) const;
        const int getParent(int child) const;
        
    public:
        Heap(int n);
        void insert(int key);
        const int maximum() const;
        void extrac_max();
        void show();
        ~Heap();
};

#endif