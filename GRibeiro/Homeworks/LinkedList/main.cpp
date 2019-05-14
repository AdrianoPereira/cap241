#include "linkedList.hpp"
#include <iostream>

using namespace std;

int main() {
    LinkedList linkedList;
    int op;
    int value;
    int aux;
    do {
        cout << "==========================================" << endl;
        cout << "IMPLEMENTACAO LISTA DUPLAMENTE ENCADEADA" << endl;
        cout << "==========================================" << endl;
        cout << "[1] - Inserir elemento no inicio\n";
        cout << "[2] - Inserir elemento no final\n";
        cout << "[3] - Remover elemento da frente\n";
        cout << "[4] - Remover elemento do final\n";
        cout << "[5] - Mostrar elemento do inicio\n";
        cout << "[6] - Mostrar elemento do final\n";
        cout << "[7] - Encerrar\n";
        cout << "Operacao: ";
        cin>>op;

        switch(op) {
            case 1:
                cout << "Inserir valor no inicio: ";
                cin>>value;
                linkedList.push_front(value);
                break;
            case 2:
                cout << "Inserir valor no final: ";
                cin>>value;
                linkedList.push_back(value);
                break;
            case 3:
                aux = linkedList.front();
                linkedList.pop_front(); 
                cout << aux << " removido do inicio\n";
                break;
            case 4:
                aux = linkedList.back();
                linkedList.pop_back(); 
                cout << aux << " removido do final\n";
                break;
            case 5:
                cout << "Elemento da frente" << linkedList.front() << "\n";
                break;
            case 6:
                cout << "Elemento do final" << linkedList.back() << "\n";
                break;
            case 7:
                break;
            default:
                cout << "Opcao de menu invalida!" << endl;
        }
       
    }while(op != 7);






    return 0;
}