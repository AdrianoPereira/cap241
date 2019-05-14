/** IMPLEMENTAÇÃO DA ESTRUTURA DE DADOS PILHA 27/03/2017
 * @AUTHOR: ADRIANO P. ALMEIDA
 **/

//implentação da classe e métodos

#include "stack.hpp"
#define SIZE_DEFAULT 5 // Tamanho padrão para a capacidade da pilha, caso o usuário não informe

#include <iostream>

//Método construtor principal, chamado quando o usuário instanciar o objeto sem passar um tamanho inicial
Stack::Stack() { 
    arr_ = new int[SIZE_DEFAULT];
    maxsize_ = SIZE_DEFAULT;
    indextop_ = -1;
    std::cout << "Pilha iniciada com capacidade: " << SIZE_DEFAULT << std::endl;
}

//Sobrecarga do método construtor, chamado quando o usuário passar um tamanho incial quando criar o objeto 
Stack::Stack(int size) { 
    arr_ = new int[size];
    maxsize_ = size;
    indextop_ = -1;
    std::cout << "Pilha iniciada com capacidade: " << size << std::endl;
}

void Stack::push(int value) {
    /*  Quando o usuário chamar o método de inserção e a pilha já tiver atingido sua
        capacidade máxima, o seu tamanho será dobrado até que haja memória suficiente usando alocação dinâmica.
    */
    if(isFull()) {
        std::cout << "A pilha atingiu sua capacidade máxima! Alocando mais memória...\n";
        maxsize_ *= 2; // Dobra a capacidade da pilha
        int* aux;
        
        aux = new int[maxsize_];

        //Verifica se teve memória suficiente para dobrar a capacidade da pilha
        if(aux == NULL) {
            std::cout << "Memória insuficiente!" << std::endl;
           exit(1);
        }

        for(int x=0; x<=indextop_; x++) 
            aux[x] = arr_[x];
        
        arr_ = new int[maxsize_];
        arr_ = aux;
   }
   arr_[++indextop_] = value;
   std::cout << top() << " adicionado" << std::endl;
}

void Stack::pop() {
    if(!isEmpty()) {
        indextop_--;
    }else {
        std::cout << "A pilha está vazia!\n";
    }
   
}

int Stack::top() {
    return arr_[indextop_];
}

bool Stack::isEmpty() {
    return indextop_ < 0;
}

bool Stack::isFull() {
    return indextop_ == maxsize_-1;
}
    

int Stack::size() {
    return indextop_+1;
}

void Stack::display() {
   for(int x=indextop_; x>=0; x--) {
       std::cout << arr_[x] << std::endl;
   }
}

Stack::~Stack() {
    // libera a memória alocada pela pilha ao ser destruído a instância criada
    delete[] arr_;
}