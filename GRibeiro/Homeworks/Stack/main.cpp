/** IMPLEMENTAÇÃO DA ESTRUTURA DE DADOS PILHA 27/03/2017
 * @AUTHOR: ADRIANO P. ALMEIDA
 **/

//Código principal
#include <iostream>
#include "stack.hpp"

using namespace std;

int main() {
    
    Stack *stack; // Cria uma referência na memória para instanciar depois a pilha
    int op;
    int value;
    int aux;

    cout << "Deseja definir um tamanho inicial para a pilha?[1-SIM][2-NAO]: ";
    cin>>op;
    if(op == 1){
        cout << "Qual o tamanho inicial da pilha? ";
        cin>>value;
        // Chamada do método construtor sobrecarregado
        // Instancia a pilha com o valor passado pelo usuário
        stack = new Stack(value);
    }else {
        // instancia a pilha com o construtor principal, iniciando o objeto com o tamanho padrão definido na implementação
        stack = new Stack();
    }
    
    do {
        cout << "==========================================" << endl;
        cout << "IMPLEMENTACAO PILHA ALOCADA DINAMICAMENTE" << endl;
        cout << "==========================================" << endl;
        cout << "[1] - Inserir elemento\n";
        cout << "[2] - Remover elemento\n";
        cout << "[3] - Topo da pilha\n";
        cout << "[4] - Consultar pilha vazia\n";
        cout << "[5] - Encerrar\n";
        cout << "Operacao: ";
        cin>>op;

        switch(op) {
            case 1:
                cout << "Inserir valor: ";
                cin>>value;
                stack->push(value);
                break;
            case 2:
                aux = stack->top();
                stack->pop();
                cout << aux << " removido\n";
                break;
            case 3:
                cout << stack->top() << " esta no topo da pilha\n";
                break;
            case 4:
                cout << (stack->isEmpty() ? "A Pilha esta vazia" : "A pilha nao esta vazia") << endl;
                break;
            case 7:
                break;
            default:
                cout << "Opcao de menu invalida!" << endl;
        }
       
    }while(op != 7);

    
    return 0;
}
