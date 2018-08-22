#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes;

        void print_reverse(Node<T>* head);

    public:
         List() {
          this->head = this->tail = NULL;
          this->nodes=0;
        };

        T front(){ return this->head->data; } ;
        T back(){ return this->tail->data; };
        void push_front(T value){
          //Create new node
          Node<T>* newnode = new Node<T>;
          newnode->data = value;
          newnode->next = head;
          //Change head for new node
          if (this->empty()){ this->tail=newnode; }
          this->head=newnode;

          //List size increases by 1
          this->nodes++;
        };
        void push_back(T value){
          //Create new node
          Node<T>* newnode = new Node<T>;
          newnode->data = value;
          newnode->next = NULL;
          //Make tail point new node
          if (!this->empty()) { this->tail->next = newnode; }
          else{ this->head=newnode; }
          //Change tail for new node
          this->tail=newnode;

          //List size increases by 1
          this->nodes++;
        };
        void pop_front(){
          Node<T>* secondnode = this->head->next;
          this->head = secondnode;

          //List size decreases by 1
          this->nodes--;
        };
        void pop_back(){};
        T get(int position){};
        void concat(List<T> &other);
        bool empty(){
          return this->head==NULL;
        };
        int size(){ return nodes; };
        void print(){
          Node<T>* temporalnode = this->head;
          while (temporalnode){
            cout << temporalnode->data << " ";
            temporalnode = temporalnode->next;
          }
        };
        void print_reverse();
        void clear();
        Iterator<T> begin();
        Iterator<T> end();

        ~List(){ if (!this->empty()){ this->head->killSelf(); } }

};
#endif
