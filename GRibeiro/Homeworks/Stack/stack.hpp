/** IMPLEMENTAÇÃO DA ESTRUTURA DE DADOS PILHA 27/03/2017
 * @AUTHOR: ADRIANO P. ALMEIDA
 **/

//Declaração do cabeçalho

#ifndef __STACK_HPP__
#define __STACK_HPP__

class Stack {
    private:
        int* arr_;
        int maxsize_, indextop_;
        
    public:
        Stack();    
        Stack(int size);

        void push(int value);
        void pop(); 
        int top();
        bool isEmpty();
        bool isFull();
        int size();        
        void display();
        
        ~Stack();
};

#endif