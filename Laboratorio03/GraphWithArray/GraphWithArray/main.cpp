#include <iostream>
#include "GraphWithArray.h"

using namespace std;

int main(int argc, char** argv) {
  
    Data<int>* d1= new Data<int>(1);
    Data<int>* d2= new Data<int>(2);
    Data<int>* d3= new Data<int>(3);
    Data<int>* d4= new Data<int>(4);
    Data<int>* d5= new Data<int>(5);
    //cout << (d1->data) << endl;

    GraphWithArray< Data<int> >* g1 = new GraphWithArray< Data<int> >();
    g1->addNode(*d1, "A");
    g1->addNode(*d2, "B");
    g1->addNode(*d3, "C");
    g1->addNode(*d4, "D");
    g1->addNode(*d5, "E");

   g1-> printNodes(); 
   g1->removeNode("C");
   g1-> printNodes(); 
  // g1->printMatrix();

   g1->addEdge("A", "B", 5);
   g1->addEdge("B", "D", 3);
   g1->printMatrix(); 
   //cout << g1->Path("A", "D") << endl;
   cout << g1->isPath("ADB") << endl;
 // cout << g1->IndirectPath_Main("A", "D") << endl;
   cout << g1->genPaths( 4 , "A", "B")<< endl;

    return 0;
}
