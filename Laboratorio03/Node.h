#ifndef NODE_H
#define NODE_H

using namespace std;

template<typename D>
class Edge;
template<typename D>
/*! Plantilla de la clase Node*/
class Node {
    public:
        //! Atributo que tiene el dato almacenado en el nodo.
        D* data;
        //! Arreglo que contiene todas las aristas que salen del nodo.
        Edge<D>* conexions;
        //! Numero de aristas que tiene el nodo.
        int numconexions;
        //! Máxima cantidad de elementos que puede contener el arreglo conexions.
        int maxElements;
        //! Atributo de tipo bool que dice si se ha visitado el nodo.
        bool beenHere;
        //! Atributo de tipo bool, que indica si el nodo se ha utilizado para saber la distancia más corta entre un nodo y otro.
        bool beenTemp;
        
        //! Constructor de la clase Node, inicializa todos los atributos en nullptr o false, según corresponda.
        Node(){
            data = nullptr; 
            conexions = nullptr;
            numconexions=0;
            beenHere = false;
            beenTemp=false;
        }
        
        //! Constructor de la clase Node, inicializa data en d.
        //! \param d dato de tipo puntero.
        Node(D* d){
            data = d; 
            conexions = nullptr;
            numconexions=0;
            beenHere = false;
            beenTemp = false;
        }
        
        //! addEdge sirve para agregar aristas a la lista de aristas del nodo.
        //! \param d objeto tipo arista.
        void addEdge(Edge<D> d)
        {
            if (numconexions == 0) //list vacia
            {
                this->conexions = new Edge<D>[10];
                this->numconexions = 1;
                maxElements = 10;
                this->conexions[0] = d;
            } else { //list con algo
                if (numconexions+1 != maxElements) { //arreglo con espacio
                    this->conexions[numconexions] = d;
                    this->numconexions++;
                } else { //arreglo sin espacio
                    Edge<D>* tmp = new Edge<D>[maxElements*2];
                    maxElements=maxElements*2;
                    for (int i = 0; i<maxElements; i++) {
                        tmp[i] = conexions[i];
                    }
                    delete[] this->conexions;
                    this->conexions = tmp;
                    this->conexions[numconexions] = d;
                    this->numconexions++;
                }
            }
        }
        
        //! delEdge remueve la arista que va de un nodo s al nodo d.
        //! \param s Puntero que indica el nodo de partida.
        //! \param d Puntero que indica el nodo de llegada.
        void delEdge(Node<D>* s, Node<D>* d)
        {
            int* pos = searchEdge(s, d);
            if(pos != nullptr)
            {
                for(int i=*pos; i<numconexions-1;i++){
                    conexions[i]=conexions[i+1];
                }
                conexions[numconexions].predecessor=nullptr;
                conexions[numconexions].successor=nullptr;
                conexions[numconexions].weight=0;
                numconexions--;
            }
        }
        
        //! searchEdge
        //! \param s Puntero que indica el nodo de partida.
        //! \param d Puntero que indica el nodo de llegada.
        //! \return la posición dentro de conexions, donde se encuentra la arista solicitada
        int* searchEdge(Node<D>* s, Node<D>* d)
        {
            for(int i=0; i<numconexions;i++)
            {
                if(conexions[i].predecessor==s && conexions[i].successor==d)
                {
                    return new int(i);
                }
                else return nullptr;
            }
        }
        //! \brief Destructor de la clase Node.
        virtual ~Node(){
        }
        private:
            
};

#endif /* NODE_H */

