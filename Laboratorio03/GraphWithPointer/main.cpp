
#include <iostream>
#include "Node.h"
#include "Edge.h"
#include "MyType.h"
#include "GraphWithPointer.h"

using namespace std;
int main(int argc, char** argv) {

    GraphWithPointer<MyType>* g1 = new GraphWithPointer<MyType>();
    Node<MyType>* nA = g1->addNode(new MyType('a'));
    Node<MyType>* nB = g1->addNode(new MyType('b'));
    Node<MyType>* nC = g1->addNode(new MyType('c'));
    Node<MyType>* nD = g1->addNode(new MyType('d'));
    Node<MyType>* nE = g1->addNode(new MyType('e'));
    Node<MyType>* nF = g1->addNode(new MyType('f'));
    Node<MyType>* nG = g1->addNode(new MyType('g'));
    Node<MyType>* nH = g1->addNode(new MyType('h'));


    g1->addEdge(20,nA,nB);
    g1->addEdge(80,nA,nD);
    g1->addEdge(90,nA,nG);
    g1->addEdge(20,nG,nA);
    g1->addEdge(10,nB,nF);
    g1->addEdge(40,nF,nD);
    g1->addEdge(10,nF,nC);
    g1->addEdge(50,nC,nF);
    g1->addEdge(10,nC,nD);
    g1->addEdge(20,nC,nH);
    g1->addEdge(10,nD,nC);
    g1->addEdge(20,nD,nG);
    g1->addEdge(50,nE,nB);
    g1->addEdge(30,nE,nG);

    cout<<"Nodos que contiene el grafo"<<endl;
    cout<<"[";
    for(int i=0;i<g1->numNodes;i++)
    {
        if(i!=g1->numNodes-1)
        {
          cout<<**(g1->graph[i]->data)<<",";
        }
        else
        {
          cout<<**(g1->graph[i]->data)<<"]"<<endl;
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
    double* route1 = g1->dijkstra(g1->bfs(new MyType('c')));
    delete [] route1;
    cout<<endl;
    cout<<endl;

    cout<<"Pesos para llegar de cada uno de los nodos dentro del grafo a los otros nodos:"<<endl;
    double** routes = g1->floyd ();
    cout<<endl;
    cout<<endl;

    cout<<"Se elimina el nodo c"<<endl;
    g1->delNode(new MyType('c'));
    cout<<endl;
    cout<<endl;

    cout<<"Nodos que contiene el grafo"<<endl;
    cout<<"[";
    for(int i=0;i<g1->numNodes;i++)
    {
        if(i!=g1->numNodes-1)
        {
          cout<<**(g1->graph[i]->data)<<",";
        }
        else
        {
          cout<<**(g1->graph[i]->data)<<"]"<<endl;
        }
    }
    cout<<endl;
    cout<<endl;

    cout<<"Busqueda mediante dfs de c"<<endl;
    g1->dfs(new MyType('c'));
    cout<<endl;
    cout<<endl;

    return 0;
}
