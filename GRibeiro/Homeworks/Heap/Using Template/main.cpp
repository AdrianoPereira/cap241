/* Implementation Heap using template in C++
** @Author: Adriano P. Almeida
** @Date: 15/05/2019
** @References: 
**      http://ads.dpi.inpe.br/lib/exe/fetch.php?media=wiki:turma2019:estruturas_dados_elementares_parte_04.pdf
**      https://dl.acm.org/citation.cfm?doid=512274.512284
**      http://www.cplusplus.com/reference/ios/ios_base/sync_with_stdio/
**
** Code avaiable in: https://github.com/AdrianoPereira/cap241/tree/master/GRibeiro/Homeworks/Heap 
*/

#include "heap.hpp"
#include <iostream>

#define _ std::ios::sync_with_stdio(false); //turn off synchronization of all the iostream standard streams with their corresponding standard C

using namespace std;

int main() {_
    Heap<char> hc(10);
    Heap<int> hi(10); 
    
    hc.insert('a');
    hc.insert('d');
    hc.insert('r');
    hc.insert('i');
    hc.insert('a');
    hc.insert('n');
    hc.insert('o');

    cout << "Priority Queue Char: ";
    hc.show();
    cout << "Max: " << hc.maximum() << endl;
   
    hi.insert(3);
    hi.insert(1);
    hi.insert(5);
    hi.insert(7);
    hi.insert(2);
    hi.insert(4);
    hi.insert(6);


    cout << "\nPriority Queue Int: ";
    hi.show();
    cout << "Max: " << hi.maximum() << endl;


    
    return 0;
}