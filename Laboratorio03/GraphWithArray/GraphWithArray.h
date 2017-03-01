#include "Data.h"
#include "ListWithArray.h"
#ifndef GRAPHWITHARRAY_H
#define GRAPHWITHARRAY_H
template <typename D>
//D es  Data<int>
class GraphWithArray {
public:

    ListWithArray< D , int >* NodesList = nullptr;
    //ListWithArray< ListWithArray< D , int >* , int >* fila;
    int Nodes;

    GraphWithArray() {
	Nodes=0;
    }

    virtual ~GraphWithArray() {
    }

    void addNode(D d){
    (NodesList)->insert(d);
    Nodes++;
    
    }

    void removeNode(D d){
    
	
    	if(Nodes!=0){
		Nodes--;
	}
    }

    void addEdge(int identifier1, int identifier2, int weight){
    }

    void removeEdge(int identifier1, int identifier2){
  
    }

    void printGraph(){

/*	for(int i=0; i<Nodes ; i++){
		fila[i].printList();    
	}*/

    }

    void printNodes(){
	for(int i=0; i<Nodes ; i++){
	     cout<< NodesList[i].data <<endl;    
	}
   }




};

#endif /* GRAPHWITHARRAY_H */
