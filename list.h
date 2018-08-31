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

        void print_reverse(Node<T>* head){
          //Keep calling method until it reaches the end
          if (head){
            this->print_reverse(head->next);
            //Print current head data from tail to actual head
            cout << head->data << " ";
          }
        };

    public:
        List(): head(nullptr), tail(nullptr), nodes(0) {};
        T front(){
          if (this->head) return this->head->data;
          throw "No element in empty list";
        };
        T back(){
          if (this->tail) return this->tail->data;
          throw "No element in empty list";
        };
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
          newnode->next = nullptr;
          //Make tail point new node
          if (!this->empty()) { this->tail->next = newnode; }
          else{ this->head=newnode; }
          //Change tail for new node
          this->tail=newnode;

          //List size increases by 1
          this->nodes++;
        };
        void pop_front(){
          if (this->empty()) throw "Can not delete element in empty list";
          Node<T>* secondnode = this->head->next;
          this->head = secondnode;

          //List size decreases by 1
          this->nodes--;
        };
        void pop_back(){
          if (this->empty()) throw "Can not delete element in empty list";
          Node<T>* secondlast = this->head;
          while (secondlast->next && secondlast->next->next){
            secondlast = secondlast->next;
          }
          //Erase content of previous tail
          delete secondlast->next;
          //Change tail for second last node
          secondlast->next = nullptr;
          this->tail = secondlast;

          //List size decreases by 1
          this->nodes--;
        };
        T get(int position){
          if (this->empty() || position >= this->nodes) throw "No element in empty list";
          Node<T>* temporalnode = this->head;
          for (int i=0; i<position; i++) temporalnode = temporalnode->next;
          return temporalnode->data;
        };
        void concat(List<T> *other){ // Solo habría que revisar esta función para que utlice & en vez de puntero
          if (!other->empty()){
            if (this->empty()) this->head=other->head; // If this empty but other full
            else { //both full
              this->tail->next = other->head;
              //cout << "\nDEBUG: "<<other.head->data<<endl;
            }
            this->tail = other->tail;

            // Modify list size
            this->nodes+=other->size();
          }
        };
        bool empty(){
          return !this->head;
        };
        int size(){ return nodes; };
        void print(){
          if (!this->empty()){
            Node<T>* temporalnode = this->head;
            while (temporalnode){
              cout << temporalnode->data << " ";
              temporalnode = temporalnode->next;
            }
            cout <<endl;
          }
          else throw "No element in empty list";
        };
        void print_reverse(){
          if (this->empty()) throw "No element in empty list";
          this->print_reverse(this->head);
          cout <<endl;
        };
        void clear(){
          if (!this->empty()){
            this->head->killSelf();
            head=tail=nullptr;
            this->nodes=0;
          }
        }
        Iterator<T> begin();
        Iterator<T> end();

        ~List(){ if (!this->empty()){ this->head->killSelf(); } }

};
#endif
