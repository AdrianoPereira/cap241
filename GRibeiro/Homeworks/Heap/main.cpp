/* Implementation Heap in C++
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
    h.extrac_max();

    h.show();
    cout << h.maximum() << endl;
   
    
    return 0;
}