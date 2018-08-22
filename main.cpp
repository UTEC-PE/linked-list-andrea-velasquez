#include "list.h"
#include <iostream>

int main(){
  List<int> lista;
  cout <<"Is empty?: " << lista.empty()<<endl;

  lista.push_front(1);
  lista.push_front(2);
  lista.push_back(99);
  lista.push_back(32);
  lista.push_front(3);

  cout << "\nAdding elements...\n";
  cout << "Linked list: ";
  lista.print();

  lista.pop_front();
  cout << "\n\nRemoving first element...";
  cout << "\nLinked list: ";
  lista.print();

  cout << "\n\nThe list has " << lista.size() <<" elements";

  return EXIT_SUCCESS;
}
