#include <iostream>
#include "GraphWithArray.h"

using namespace std;

int main(int argc, char** argv) {
  
    Data<int>* d1= new Data<int>(1);
    cout << (d1->data) << endl;

    GraphWithArray< Data<int> >* g1 = new GraphWithArray< Data<int> >();
   // g1->printGraph();


    g1->addNode(*d1);

    return 0;
}
