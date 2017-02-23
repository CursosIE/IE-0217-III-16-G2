#include <iostream>
#include "ListWithArray.h"
#include "ListWithPointer.h"
#include "Cell.h"
using namespace std;

int main(int argc, char** argv) {

    ListWithPointer< int , Cell<int>* >* l2 = new ListWithPointer< int , Cell<int>* >();
    l2->insert(15);
    l2->insert(10);
    l2->insert(9);
    l2->insert(7);
    l2->insert(3);
    l2->printList();
    ListWithPointer< int , Cell<int>* >* l3 = new ListWithPointer< int , Cell<int>* >();
    //l3->printList();
    l3->insert(5);
    l3->printList();
    l3->remove(5);
    l3->printList();
    l2->remove(9);
    //l2->printList();
    //l2->assign(l2->first,19);
    //l2->printList();
    //l2->remove(19);
    //l2->printList();
    l2->remove(3);
    l2->printList();
    //l2->emptyList();
    //l2->printList();
    
    
    
    return 0;
}


