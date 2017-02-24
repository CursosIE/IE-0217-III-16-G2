#include <iostream>
#include "ListWithArray.h"
#include "ListWithPointer.h"
#include "Cell.h"
#include "Queue.h"
#include "Stack.h"
using namespace std;

int main(int argc, char** argv) {
     cout<<"Incia prueba ListWithArray"<<endl;
     /*Prueba de ListWithArray*/
     ListWithArray< double , int >* lista = new ListWithArray< double , int >();
     lista->insert(0.1);
     lista->insert(0.7);
     lista->insert(0.4);
     lista->insert(0.3);
     lista->insert(0.6);
     lista->insert(0.2);
     lista->insert(0.4);
     lista->insert(0.5);
     cout << "Imprimiendo Lista Desordenada" << endl;
     lista->printList();

     cout << "Imprimiendo Lista Ordenada" << endl;
     lista->sort();
     lista->printList();
     cout << "Removiendo primer elemento" << endl;
     lista->remove(0.1);
     lista->printList();
     cout << " " << endl;
     cout << " " << endl;
     cout << "Removiendo elemento del medio " << endl;
     lista->remove(0.4);
     lista->printList();
     cout << " " << endl;
     cout << " " << endl;
     cout << "Removiendo elemento del final " << endl;
     lista->remove(0.7);
     lista->printList();


     cout << endl;
     cout << endl;



     cout<<"Incia prueba ListWithPointer"<<endl;
    /*Prueba de ListWithPointer*/

    ListWithPointer< int , Cell<int>* >* l2 = new ListWithPointer< int , Cell<int>* >();
    ListWithPointer<int, Cell<int>*>* l3 = new ListWithPointer<int, Cell<int>*>();
    cout<<"Imprimiendo lista l3"<<endl;
    l3->printList();
    l2->insert(8);
    l2->insert(23);
    l2->insert(17);
    l2->insert(35);
    l2->insert(4);
    cout<<"Imprimiendo lista l2"<<endl;
    l2->printList();
    l2->assign((l2->find(35)),47);
    cout<<"Imprimiendo lista l2, con un cambio..."<<endl;
    l2->printList();
    l2->sort();
    cout<<"Imprimiendo lista l2 ordenada"<<endl;
    l2->printList();
    l2->remove(35);
    cout<<"Elimino el elemento del medio"<<endl;
    l2->remove(*(l2->first->next->next->data));
    l2->printList();
    cout<<"Elimino el primer elemento de la lista"<<endl;
    l2->remove(*(l2->first->data));
    l2->printList();
    cout<<"Elimino el ultimo elemento de la lista"<<endl;
    l2->remove(*(l2->last->data));
    l2->printList();
    cout<<"Vacio la lista..."<<endl;
    l2->emptyList();
    l2->printList();


    /*Prueba de Queue*/

    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"Incia prueba Queue"<<endl;

    Queue< int , Cell<int>* >* q1 = new Queue< int , Cell<int>* >();
    q1->insert(1);
    q1->insert(10);
    q1->insert(100);
    q1->insert(1000);
    q1->printList();
    q1->remove(256);
    q1->printList();
    q1->remove(137);
    q1->printList();
    q1->emptyList();
    q1->printList();

    /*Prueba de Stack*/
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"Incia prueba Stack"<<endl;

    Stack< int , Cell<int>* >* s1 = new Stack< int , Cell<int>* >();
    s1->insert(1);
    s1->insert(10);
    s1->insert(100);
    s1->insert(1000);
    s1->printList();
    s1->remove(0);
    s1->printList();
    s1->remove(0);
    s1->printList();
    s1->emptyList();
    s1->printList();

    return 0;
}
