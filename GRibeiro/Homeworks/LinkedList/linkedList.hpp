/** IMPLEMENTAÇÃO DA ESTRUTURA DE DADOS LISTA DUPLAMENTE ENCADEADA 27/03/2017
 * @AUTHOR: ADRIANO P. ALMEIDA
 **/

//Declaração do cabeçalho

#ifndef __LINKEDLIST_HPP__
#define __LINKEDLIST_HPP__

//Classe criada para auxiliar na criação de um nó da lista
class Node {
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int value);
};

class LinkedList {
    private:
        Node* head_;
        Node* tail_;
        int size_;
    
    public:
        LinkedList();
        int front();
        int back();
        void push_front(int value);
        void push_back(int value);
        void pop_front();
        void pop_back();
        bool isEmpty();
        void display();
        ~LinkedList();
};

#endif