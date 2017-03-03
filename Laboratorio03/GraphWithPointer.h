#ifndef GRAPHWITHPOINTER_H
#define GRAPHWITHPOINTER_H
#include "Stack.h"
#include "Queue.h"
#include "Node.h"
#include "Edge.h"
#include <climits>

using namespace std;
template<typename D>
class GraphWithPointer {
    public:
        //! Arreglo de tipo Node Pointer, donde se guardan los nodos que contiene el grafo.
        Node<D>** graph;
        //! Atributo que indica la cantidad de nodos del grafo.
        int numNodes;
        //! Atributo que indica la maxima cantidad de elementos que permite graph.
        int maxElements;

        /*! Constructor de la clase grafo.*/
        GraphWithPointer(){
            graph = nullptr;
        }

        /*! addEdge, se agrega una arista a conexions del nodo s.
         *\param w peso
         *\param s source Node
         * \param d destiny Node
         */
        void addEdge(double w, Node<D>* s, Node<D>* d)
        {
            s->addEdge(Edge<D>(w,s,d));
        }

        /*! addNode Agrega un nodo a graph
         \param d dato que contendrá el nodo agregado.*/
        Node<D>* addNode(D* d)
        {
            Node<D>* newNode = new Node<D>(d);
            if (numNodes == 0)
            {
                this->graph = new Node<D>*[10];
                this->numNodes = 1;
                maxElements = 10;
                this->graph[0] = newNode;
            } else { //list con algo
                if (numNodes+1 != maxElements) {
                    this->graph[numNodes] = newNode;
                    this->numNodes++;
                } else { //arreglo sin espacio
                    Node<D>** tmp = new Node<D>*[maxElements*2];
                    maxElements=maxElements*2;
                    for (int i = 0; i<maxElements; i++) {
                        tmp[i] = graph[i];
                    }
                    delete[] this->graph;
                    this->graph = tmp;
                    this->graph[numNodes] = newNode;
                    this->numNodes++;
                }
            }
            return newNode;
        }

        /*! Elimina una arista de la lista de conexiones del nodo s.
         \param s source node
         \param d destiny node*/
        void delEdge(Node<D>* s, Node<D>* d)
        {
            s->delEdge(s,d);
        }

        /*! Elimina el nodo que contiene al dato d de la lista graph.
         * De manera que también elimina todas las aristas que lleguen a dicho nodo.
         * \param d dato que contiene el nodo que se desea borrar. */
        void delNode(D* d)
        {
            int pos=-1;
            Node<D>* a = dfs(d);

            for(int j=0; j<numNodes;j++)
            {
                if(!(*(graph[j]->data)==*(a->data)))
                {
                    delEdge(graph[j],a);
                }
                else
                {
                    pos = j;
                }
            }


            if(pos >0)
            {
                for(int i=pos; i<numNodes-1;i++){
                    graph[i]=graph[i+1];
                }
                graph[numNodes]=nullptr;
                numNodes--;
            }
        }

        /*! Indica el primer nodo que contiene graph.
         \return el primer nodo.*/
        Node<D>* firstNode()
        {
            if(graph)
            {
                return graph[0];
            }
            else return nullptr;
        }

        /*! Indica el nodo que le sigue al nodo t.
         \param t nodo
         \return el nodo siguiente a t*/
        Node<D>* nextNode(Node<D> t)
        {
            for(int i=0; i<numNodes;i++)
            {
                if(*graph[i]->data == t->data )
                {
                    return graph[i];
                }
            }
        }

        /*! Indica el nodo que se encuentra en la posición i de graph
         \param i posicion
         \return nodo que se encuentra en la posicion i de graph*/
        Node<D>* node(int i)
        {
            return graph[i];
        }

        /*! Indica el dato que contiene un nodo
         \param a Nodo
         \return dato que contiene a*/
        D* getData(Node<D>* a)
        {
            return a->data;
        }

        /*! Depth first search.
         *  Recorre el grafo, desde su raíz y avanza de vértice en vértice, marcando cada vértice como visitado.
         * La búsqueda siempre avanza hacia un vértice no marcado,internándose “profundamente” en el grafo
         * sin repetir ningún vértice. Cuando se alcanza un vértice cuyos vecinos han sido marcados,
         * se retrocede al anterior vértice visitado y se avanza desde éste.
         \param d dato buscado
         \return El nodo dentro del grafo donde se ubica el dato.
         \return nullptr si el nodo que contenga al dato no existe*/
        Node<D>* dfs(D* d)
        {
            for(int i=0;i<numNodes;i++)
            {
                graph[i]->beenHere = false;
            }

            int nodeCounter=0;
            Stack<Node<D>,Cell<Node<D>>*>* q1 = new Stack<Node<D>,Cell<Node<D>>*>();
            int i=0;
            while(nodeCounter != numNodes){
                if(!graph[i]->beenHere){
                    q1->insert(graph[i]);
                    nodeCounter++;
                    graph[i]->beenHere = true;
                    Node<D>* temp = graph[i];
                    while(q1->first)
                    {
                        if(*(temp->data) == *d)
                        {
                            cout<<"Valor encontrado :)"<<endl;
                            return temp;
                        }
                        int beenHereCount = 0;
                        if(temp->numconexions != 0){

                            Node<D>* neighbor = temp->conexions[0].successor;
                            bool  limit = false;
                            while(neighbor->beenHere && !limit)
                            {
                                beenHereCount++;
                                if (beenHereCount != temp->numconexions)
                                {
                                    neighbor = temp->conexions[beenHereCount].successor;
                                }
                                else
                                {
                                    limit = true;
                                }
                            }

                            if(beenHereCount == temp->numconexions)
                            {
                                q1->pop();
                                if(q1->first){
                                    temp=q1->last->data;
                                }
                            }
                            else
                            {
                                temp = neighbor;
                                q1->insert(temp);
                                nodeCounter++;
                                temp->beenHere = true;
                            }
                        }
                        else
                        {
                            q1->pop();
                            if(q1->first){
                                temp=q1->last->data;
                            }
                        }
                    }


                    i++;
                }
                else i++;
            }
            cout<<"No se encontro el valor indicado"<<endl;
            return nullptr;
        }

        /*! Breadth first search
         *La busqueda se comienza desde la raíz que es el primer vértice activo.
         * En el siguiente paso se etiquetan como visitados todos los vecinos del
         *vértice activo que no han sido etiquetados. Se continúa etiquetando todos los vecinos de
         *los hijos de v que no hayan sido visitados aún.
         *\param d dato buscado.
         *\return El nodo donde se ubica el dato.
         *\return nullptr si el nodo no existe.
         */
        Node<D>* bfs(D* d)
        {
            for(int i=0;i<numNodes;i++)
            {
                graph[i]->beenHere = false;
            }
            int nodeCounter=0;
            Queue<Node<D>,Cell<Node<D>>*>* q1 = new Queue<Node<D>,Cell<Node<D>>*>();
            int i=0;
            while(nodeCounter != numNodes){
                if(!graph[i]->beenHere){
                    q1->insert(graph[i]);
                    nodeCounter++;
                    graph[i]->beenHere = true;
                    Node<D>* temp = graph[i];
                    while(q1->first)
                    {
                        char ch = **(temp->data);
                        //cout<<ch<<endl;
                        if(*(temp->data) == *d)
                        {
                            //cout<<"Valor encontrado :)"<<endl;
                            return temp;
                        }
                        if(temp->numconexions != 0){
                            for(int i=0; i<temp->numconexions;i++)
                            {
                                Node<D>* neighbor =temp->conexions[i].successor;
                                if(!neighbor->beenHere){
                                    q1->insert(neighbor);
                                    neighbor->beenHere=true;
                                    nodeCounter++;
                                }
                            }
                        }
                        q1->pop();
                        if(q1->first){
                            temp = q1->first->data;
                        }
                    }
                    i++;
                }
                else i++;
                if(nodeCounter==numNodes)
                {
                    cout<<"No se encontro el valor indicado"<<endl;
                    return nullptr;
                }
            }


        }

        /*! Indica la posicion dentro de graph donde se ubica el nodo s
         \param s nodo
         * \return posicion
         */
        int index(Node<D>* s)
        {
            for(int i=0;i<numNodes;i++)
            {
                if(*(graph[i]->data)==*(s->data))
                {
                    return i;
                }
            }
        }

        /*! Indica el peso correspondiente de ir de un nodo s, a cada uno de los nodos dentro del grafo
         * \param s source Node
         * \return arreglo de tipo double. */
        double* dijkstra(Node<D>* s)
        {
            double* route = new double[numNodes];

            bool found = false;
            int pos = 0;
            while(!found){
                if(graph[pos] != s) {
                    pos++;
                }
                else
                {
                    found = true;
                }
            }

            for(int i=0; i < numNodes; i++)
            {
                graph[i]->beenTemp=false;
                route[i] = INT_MAX;
            }

            route[pos] = 0;

            Node<D>* temp = graph[pos];
            Node<D>* temp3;
            double minWeight =0;
            double preMinWeight=0;

            while(minWeight != INT_MAX){
                for(int k=0;k<numNodes;k++)
                {
                    if(route[k] != INT_MAX && route[k]>=preMinWeight)
                    {
                        Node<D>* a1 = bfs(graph[k]->data);
                        if(!(a1->beenTemp))
                        {
                            if(route[k]<minWeight)
                            {
                                if(a1->numconexions>0){
                                    minWeight=route[k];
                                    temp=a1;
                                }
                                else{
                                    a1->beenTemp=true;
                                }
                            }
                        }
                    }
                }

                double minConex = INT_MAX;
                temp->beenTemp = true;
                for(int i=0; i<temp->numconexions;i++)
                {


                    Node<D>* neighbor = temp->conexions[i].successor;
                    double nWeight = temp->conexions[i].weight;
                    double actualWeight = nWeight+minWeight;
                    if (route[index(neighbor)] > actualWeight)
                    {

                        route[index(neighbor)] = actualWeight;
                        if (actualWeight < minConex && neighbor->numconexions!=0 && !(neighbor->beenTemp))
                        {
                            minConex = actualWeight;
                            temp3 = neighbor;
                        }
                    }
                }
                preMinWeight=minWeight;
                minWeight = minConex;
                temp=temp3;
            }

            for(int i=0;i<numNodes;i++)
            {
                cout<<route[i]<<",";
            }
            cout<<endl;
            return route;
        }

        /*! Indica el peso que tiene de ir de cada uno de los nodos de graph, a los otros nodos pertenecientes a graph
         \return arreglo en 2D de doubles.*/
        double** floyd()
        {
            double** routes = new double*[numNodes];
            for(int i=0; i<numNodes;i++)
            {
                routes[i]=dijkstra(graph[i]);
            }

        }

        /*! Destructor de la clase GraphWithPointer*/
        virtual ~GraphWithPointer(){
            for (int i=0; i<numNodes;i++)
            {
                delete [] graph[i];
            }
            delete [] graph;
        }

};

#endif /* GRAPHWITHPOINTER_H */
