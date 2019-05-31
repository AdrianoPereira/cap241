/** IMPLEMENTAÇÃO DA ESTRUTURA DE DADOS LISTA DUPLAMENTE ENCADEADA 27/03/2017
 * @AUTHOR: ADRIANO P. ALMEIDA
 **/

//implentação da classe e métodos

#include "linkedList.hpp"
#include <cstdlib>
#include <iostream>

//Inicialmente cada nó criado fica isolado, sendo definido somente seu valor
Node::Node(int value) {
    data = value;
    prev = next = NULL;
}

// Inicialmente o início e fim da lista serão os mesmos
LinkedList::LinkedList() { 
    head_ = tail_ = NULL;
    size_ = 0;
}

int LinkedList::front() {
    if(!isEmpty())
        return head_->data; //retorna o valor da frente da lista
    std::cout << "A lista esta vazia!\n";
    return 0;
}

int LinkedList::back() {
    if(!isEmpty())
        return tail_->data; //retorna o valor do final da lista
    std::cout << "A lista esta vazia!\n";
    return 0;
}


void LinkedList::push_front(int value) {
    Node* temp = new Node(value);

    if(temp == NULL){
        std::cout << "Memoria indisponível!\n";
        exit(1);
    }

    if(head_ == NULL){
        //Ao entrar aqui a lista esta vazia.
        head_ = tail_ = temp;
    }else {
        // liga o nó criado ao início da lista
        head_->prev = temp;
        temp->next = head_;
        head_ = temp;
    }
    size_++;
}

void LinkedList::push_back(int value) {
    Node* temp = new Node(value);
    if(temp == NULL){
        std::cout << "Memoria indisponivel!\n";
        exit(1);
    }
    
    if(tail_ == NULL){
        head_ = tail_ = temp;
    }else {
        // liga o nó criado ao início da lista
        tail_->next = temp;
        temp->prev = tail_;
        tail_ = temp;
    }
    size_++;
}

void LinkedList::pop_front() {
    if(!isEmpty()) {
        Node* temp = head_;
        if(head_ == tail_)
            tail_ = NULL; //A lista fica vazia
        head_ = head_->next;

        delete temp; //libera a memória utilizada pelo nó separado da lista

        size_--;
        return ;
    }
    std::cout << "A lista esta vazia\n"; 
}

void LinkedList::pop_back() {
    if(!isEmpty()) {
        Node* temp = tail_;
        if(head_ == tail_)
            head_ = NULL;
        tail_->next = NULL;
        tail_ = tail_->prev;

        delete temp; //libera a memória utilizada pelo nó separado da lista

        size_--;
        return ;
    }
    std::cout << "A lista esta vazia\n"; 
}

bool LinkedList::isEmpty() {
    return size_ <= 0;
}

void LinkedList::display() {
    Node* temp = head_;

    while(temp != NULL) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

LinkedList::~LinkedList() {
    while(!isEmpty()) {
        pop_front();
    }
}