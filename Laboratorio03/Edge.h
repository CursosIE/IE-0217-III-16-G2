#ifndef EDGE_H
#define EDGE_H

#include "Node.h"
using namespace std;

template<typename D>
/*! Plantilla de la clase Edge*/
class Edge {
    public:
        //! Puntero que indica el nodo de salida de la arista.
        Node<D>* predecessor;
        //! Puntero que indica el nodo de llegada de la arista.
        Node<D>* successor;
        //! Atributo que corresponde al peso que toma de llegar del nodo de salida al nodo de llegada.
        double weight;
        
        /*! Constructor de la clase Edge, inicializa sus atributos en nullptr*/
        Edge(){
            predecessor=successor=nullptr;
        }
        
        /*! Constructor de la clase Edge,
         *  inicializa sus atributos segun los valore enviados como parametros(w,s,d)
         \param w weight
         \param s source
         \param d destiny*/
        Edge(double w, Node<D>* s, Node<D>* d){
            this->weight=w;
            this->predecessor = s;
            this->successor = d;
        }
        
        /*! Constructor por copia */
        Edge(const Edge<D>& orig)
        {
            this->weight = orig.weight;
            this->predecessor = orig.predecessor;
            this->successor = orig.successor;
        }
        
        /*! Destructor de la clase Edge*/
        virtual ~Edge()
        {
        }
        
};

#endif /* EDGE_H */

