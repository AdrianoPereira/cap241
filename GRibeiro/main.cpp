#include "heap.hpp"
// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    Heap h(15);
    
    h.insert(17);
    h.insert(15);
    h.insert(11);
    h.insert(85);

    h.insert(160);

    h.extrac_max();
    h.extrac_max();
    // h.extrac_max();

    h.show();
    cout << h.maximum() << endl;
   
    
    return 0;
}