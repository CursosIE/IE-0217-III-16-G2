
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
 
    double* route1 = g1->dijkstra(g1->dfs(new MyType('c')));
    double* route2 = g1->dijkstra(g1->bfs(new MyType('b')));
    delete [] route1;
    delete [] route2;
    
    cout<<endl;
    cout<<endl;
    
    double** routes = g1->floyd ();
    
    for(int i=0;i<g1->numNodes;i++)
    {
        cout<<**(g1->graph[i]->data)<<",";
    }
    
    g1->delNode(new MyType('c'));
    
    for(int i=0;i<g1->numNodes;i++)
    {
        cout<<**(g1->graph[i]->data)<<",";
    }
    
    cout<<endl;
    
    g1->dfs(new MyType('c'));
    g1->bfs(new MyType('c'));
    return 0;
}

