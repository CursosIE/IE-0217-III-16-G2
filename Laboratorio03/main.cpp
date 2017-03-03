#include <iostream>
#include "GraphWithArray.h"
#include "NodeT.h"
#include "BinarySearchTree.h"

#include "NodeT.h"
#include "Edge.h"
#include "MyType.h"
#include "GraphWithPointer.h"

#define D int
using namespace std;

int main(int argc, char** argv) {

	cout <<"///////////////////////////////////////////" <<endl;
	cout <<" Prueba GraphWithArray:   "<< endl;
	cout << endl;
    Data<int>* d1= new Data<int>(1);
    Data<int>* d2= new Data<int>(2);
    Data<int>* d3= new Data<int>(3);
    Data<int>* d4= new Data<int>(4);
    Data<int>* d5= new Data<int>(5);
    Data<int>* d6= new Data<int>(6);
    Data<int>* d7= new Data<int>(7);
    Data<int>* d8= new Data<int>(8);
    //cout << (d1->data) << endl;

    GraphWithArray< Data<int>>* g1 = new GraphWithArray< Data<int> >();
    g1->addNode(*d1, "A");
    g1->addNode(*d2, "B");
    g1->addNode(*d3, "C");
    g1->addNode(*d4, "D");
    g1->addNode(*d5, "E");
    g1->addNode(*d6, "F");
    g1->addNode(*d7, "G");
    g1->addNode(*d8, "Z");
    g1->addNode(*d8, "P");
    g1-> printNodes();
  cout << "removiendo el nodo P"<< endl;
    g1->removeNode("P");


   g1-> printNodes();


   g1->addEdge("A", "B", 16);
   g1->addEdge("A", "C", 10);
   g1->addEdge("A", "D", 5);

   g1->addEdge("B", "A", 16);
   g1->addEdge("B", "C", 2);
   g1->addEdge("B", "F", 4);
   g1->addEdge("B", "G", 6);

   g1->addEdge("C", "A", 10);
   g1->addEdge("C", "B", 2);
   g1->addEdge("C", "E", 10);
   g1->addEdge("C", "D", 4);
   g1->addEdge("C", "F", 12);

   g1->addEdge("D", "A", 5);
   g1->addEdge("D", "C", 4);
   g1->addEdge("D", "E", 15);

   g1->addEdge("E", "C", 10);
   g1->addEdge("E", "D", 15);
   g1->addEdge("E", "F", 3);
   g1->addEdge("E", "Z", 5);

   g1->addEdge("F", "B", 4);
   g1->addEdge("F", "C", 12);
   g1->addEdge("F", "E", 3);
   g1->addEdge("F", "G", 8);
   g1->addEdge("F", "Z", 16);

   g1->addEdge("G", "B", 6);
   g1->addEdge("G", "F", 8);
   g1->addEdge("G", "Z", 7);

   g1->addEdge("Z", "E", 5);
   g1->addEdge("Z", "G", 7);
   g1->addEdge("Z", "F", 16);

   g1->addEdge("A", "A", 0);
   g1->addEdge("B", "B", 0);
   g1->addEdge("C", "C", 0);
   g1->addEdge("D", "D", 0);
   g1->addEdge("E", "E", 0);
   g1->addEdge("F", "F", 0);
   g1->addEdge("G", "G", 0);
   g1->addEdge("Z", "Z", 0);



   g1->printMatrix();

   int* distancia= g1->dijkstra("A","Z");
   cout << "La distancia entre A y Z es de:" << *distancia << endl;

//g1->floyd();

	cout << endl;
	cout <<"///////////////////////////////////////////" <<endl;
	cout <<" Prueba BST:   "<< endl;
	cout << endl;



    BinarySearchTree<D>* bst1 = new BinarySearchTree<D>(new D(3));
    bst1->insert(new D(4));
    bst1->insert(new D(1));
    bst1->insert(new D(2));
    bst1->insert(new D(3));
    bst1->insert(new D(6));
    bst1->insert(new D(5));
    bst1->insert(new D(7));
    bst1->printTree();

cout << "Cantidad de nodos: " << bst1->nodes << endl;

    NodeT<D>* r = bst1->find(new D(666));
    if (r) {
        cout << *(r->d) << endl;
    } else {
        cout << "no esta" << endl;
    }

    r = bst1->maxLesser(bst1->root);
    if (r) {
        cout << *(r->d) << endl;
    } else {
        cout << "no esta" << endl;
    }

    r = bst1->minGreater(bst1->root);
    if (r) {
        cout << *(r->d) << endl;
    } else {
        cout << "no esta" << endl;
    }

    bst1->remove(new int(3));
    bst1->printTree();
    cout << "Cantidad de nodos: " << bst1->nodes << endl;

   cout << "balance" << endl;
   bst1->balance();

   cout<<""<<endl;
   cout<<""<<endl;
   cout<<""<<endl;

       cout<<"GraphWithPointer"<<endl;
       GraphWithPointer<MyType>* g2 = new GraphWithPointer<MyType>();
       Node<MyType>* nA = g2->addNode(new MyType('a'));
       Node<MyType>* nB = g2->addNode(new MyType('b'));
       Node<MyType>* nC = g2->addNode(new MyType('c'));
       Node<MyType>* nD = g2->addNode(new MyType('d'));
       Node<MyType>* nE = g2->addNode(new MyType('e'));
       Node<MyType>* nF = g2->addNode(new MyType('f'));
       Node<MyType>* nG = g2->addNode(new MyType('g'));
       Node<MyType>* nH = g2->addNode(new MyType('h'));


       g2->addEdge(20,nA,nB);
       g2->addEdge(80,nA,nD);
       g2->addEdge(90,nA,nG);
       g2->addEdge(20,nG,nA);
       g2->addEdge(10,nB,nF);
       g2->addEdge(40,nF,nD);
       g2->addEdge(10,nF,nC);
       g2->addEdge(50,nC,nF);
       g2->addEdge(10,nC,nD);
       g2->addEdge(20,nC,nH);
       g2->addEdge(10,nD,nC);
       g2->addEdge(20,nD,nG);
       g2->addEdge(50,nE,nB);
       g2->addEdge(30,nE,nG);

       cout<<"Nodos que contiene el grafo"<<endl;
       cout<<"[";
       for(int i=0;i<g2->numNodes;i++)
       {
           if(i!=g2->numNodes-1)
           {
             cout<<**(g2->graph[i]->data)<<",";
           }
           else
           {
             cout<<**(g2->graph[i]->data)<<"]"<<endl;
           }
       }
       cout<<endl;
       cout<<endl;

       cout<< "Aristas que contiene el Nodo d:"<<endl;

       cout<<"[";
       for(int i=0;i<nD->numconexions;i++)
       {
         char s = nD->conexions[i].predecessor->data->content;
         char d = nD->conexions[i].successor->data->content;
         int w = nD->conexions[i].weight;
         if(i!=nD->numconexions-1){
           cout<< "("<<s<<" to "<<d<<":"<<w<<"),";
         }
         else
         {
           cout<< "("<<s<<" to "<<d<<":"<<w<<")]"<<endl;
         }
       }
       cout<<endl;
       cout<<endl;

       cout<<"Pesos para llegar de c a cada uno de los otros nodos:"<<endl;
       double* route1 = g2->dijkstra(g2->bfs(new MyType('c')));
       delete [] route1;
       cout<<endl;
       cout<<endl;

       cout<<"Pesos para llegar de cada uno de los nodos dentro del grafo a los otros nodos:"<<endl;
       double** routes = g2->floyd ();
       cout<<endl;
       cout<<endl;

       cout<<"Se elimina el nodo c"<<endl;
       g2->delNode(new MyType('c'));
       cout<<endl;
       cout<<endl;

       cout<<"Nodos que contiene el grafo"<<endl;
       cout<<"[";
       for(int i=0;i<g2->numNodes;i++)
       {
           if(i!=g2->numNodes-1)
           {
             cout<<**(g2->graph[i]->data)<<",";
           }
           else
           {
             cout<<**(g2->graph[i]->data)<<"]"<<endl;
           }
       }
       cout<<endl;
       cout<<endl;

       cout<<"Busqueda mediante dfs de c"<<endl;
       g2->dfs(new MyType('c'));
       cout<<endl;
       cout<<endl;

    return 0;
}
