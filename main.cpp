#include "list.h"
#include <iostream>

int main(){
  List<int> lista;

  cout << "lista.empty(): " << lista.empty()<<endl;

  cout << "lista.push_front: ";
  lista.push_front(1);
  lista.push_front(2);
  lista.push_front(3);
  lista.print();

  cout << "lista.push_back: ";
  lista.push_back(4);
  lista.push_back(5);
  lista.print();

  cout << "lista.front(): " << lista.front() << endl;

  cout << "lista.back(): " << lista.back() << endl;

  cout << "lista.pop_front(): ";
  lista.pop_front();
  lista.print();

  cout << "lista.pop_back(): ";
  lista.pop_back();
  lista.print();

  cout << "lista.get(2): " << lista.get(2) << endl;

  cout << "lista.print_reverse: ";
  lista.print_reverse();

  List<int> otralista;
  for (int i=0; i<3; i++){ otralista.push_back(10); otralista.push_front(11); }
  cout <<"otralista: ";
  otralista.print();
  cout << "lista.concat(otralista): ";
  lista.concat(otralista);
  lista.print();

  cout << "lista.clear()\n";
  lista.clear();
  cout << "lista.empty(): " << lista.empty()<<endl;

  cout << "lista.size(): " << lista.size();

  return EXIT_SUCCESS;
}
