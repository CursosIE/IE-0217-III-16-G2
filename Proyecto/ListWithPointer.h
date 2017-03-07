#ifndef LISTWITHPOINTER_H
#define LISTWITHPOINTER_H

#include <iostream>
#include "List.h"
#include "Cell.h"
using namespace std;

template <typename D, typename P>
/*!
 Plantilla de la clase Lista con Punteros, que hereda de la clase List.
 */
class ListWithPointer : public List<D, P> {
    public:
        /*! \brief Constructor de la clase ListWithPointer, 
         * los atributos first y null, son nulos y n es igual a cero
         */
        ListWithPointer(){
            this->first = this->last = nullptr;
            this->n=0;
        }
        
        /*! \brief Destructor, elimina todos los elementos de la lista con emptyList() 
         */
        virtual ~ListWithPointer()
        {
            emptyList();
        }
        
        //! Metodo insert.
        /*!Inserta elementos en la lista.
         * Si la lista esta vacia, se crea la celda y se almacena el dato, los punteros first y last apuntan a dicha celda.
         * De lo contrario, se crea la celda, se almacena el dato y se asigna el puntero last a la ultima celda agregada.
         * Se hace la conexion entre la penultima celda y la ultima, mediante el atributo de la clase Cell: next. 
         * Aumenta en uno a n.
         * \param d dato tipo D que se desea insertar en la lista.
         * \param Cell celda que se crea para almacenar el dato d.
         */
        void insert(D d) { 
            P c = new Cell<D>(new D(d), nullptr);
            if(this->getSize()==0) 
            {
                this->first = this->last = c; 
            }
            
            else
            {
                
                this->last->next = c; 
                this->last = c; 
            }
            this->n++; 
            
        }
        
        //!Metodo remove.
        /*!Remueve una celda de la lista.
         *  Se asegura que la lista no este vacia.De ser asi se crea un puntero temp tipo celda, que apunta a la celda que almacena el dato d.
         *  Si temp apunta a first, se cambia first a apuntar al siguiente valor de la lista.
         *  De lo contrario, se crea un puntero temp2 tipo celda que apunta al valor anterior a temp. Se realiza la conexion entre temp2, y la celda siguiente a temp.
         *  Se elimina temp.
         *  \param d dato tipo D que se desea remover de la lista.
         */
        void remove(D d) { 
            if(first) 
            {
                P temp= find(d); 
                if(temp) 
                {
                    if(temp==first) 
                    {
                        first=next(temp);
                    }
                    
                    else{ 
                        P temp2 = prev(temp); 
                        temp2->next = next(temp); 
                        if(temp==last) 
                        {
                            last = temp2;
                        }
                    }
                    this->n--; 
                    delete temp; 
                }
            }     
        }
        //! Metodo find
        /*!Metodo de busqueda de un dato en la lista. 
         * \param d dato tipo D que se desea buscar en la lista
         * \return la celda en la cual se encuentra alojado el dato.
         */
        P find(D d) 
        { 
            P temp = first;
            if(first){
                for(int i=0;i<this->getSize();i++)
                {
                    if(get(temp)==d)
                    {
                        return temp;
                    }
                    else
                    {
                        temp=next(temp);
                    }
                }
            }
            cout<<"El valor " << d <<" no esta en la lista"<<endl;
            return nullptr;
        }
        
        D pos(int k)
        {
            int counter=0;
            P temp=first;
            for(int i=0;i<getSize();i++)
            {
                if(counter==k){
                    return get(temp);
                }
                temp = next(temp);
                counter++;
            }
        }
        //!Metodo get
        /*! Metodo de obtencion del dato contenido en una celda
         * \param k  puntero tipo Celda.
         * \return Retorna el dato contenido en la celda.
         */
        D get(P k) { //obtener
            return *(k->data);
        }
        
        //!Metodo assign.
        /*! Metodo para asignar a una celda existente en la lista, un valor especifico
         * \param k puntero tipo Celda.
         * \param d dato tipo D, el cual se quiere asignar a la celda k.
         */
        void assign(P k, D d) {
            *(k->data) = d;
        }
        
        //! Metodo sort
        /*! Metodo para ordenar la lista de menor a mayor*/
        void sort() { 
            for(int i=0;i<getSize();i++){
                P temp = first;
                for(int j =0; j<getSize()-1;j++)
                {
                    if(temp && next(temp) && *(temp->data)>*(next(temp)->data))
                    {
                        D newtemp=*(temp->data);
                        *(temp->data)=*(next(temp)->data);
                        *(next(temp)->data)=newtemp;
                    }
                    temp=next(temp);
                }
            }
        }
        
        //! Metodo getSize
        /*! Metodo que devuelve el tamaño de la lista
         \return tamaño.
         */
        int getSize() { //tamaño
            return this->n;
        }
        
        //!Metodo printList
        /*! Metodo que imprime la lista.
         */
        void printList() { 
            P temp = first;
            if(first){
                for(int i=0; i<this->getSize(); i++)
                {
                    cout<<get(temp)<<endl;
                    temp=next(temp);
                }
                cout<<"------------------------------------------------------------"<<endl;
                cout<<"------------------------------------------------------------"<<endl;
            }
            else
            {
                cout<<"La lista se encuentra vacia"<<endl;
            }
        }
        
        //!Metodo next
        /*! Metodo que dice la celda siguiente a una celda dada.
         \param k puntero tipo celda.
         \return la celda siguiente a k.
         */
        P next(P k) { //siguiente
            return k->next;
        }
        
        //!Metodo previous
        /*! Metodo que dice la celda anterior a una celda dada.
         * \param k puntero tipo celda.
         * \return la celda anterior a k.
         */
        P prev(P k) { //anterior
            if(k != first){
                P temp = first;
                for(int i=0; i < this->getSize(); i++)
                {
                    if(k == next(temp))
                    {
                        return temp;
                    }
                    else
                    {
                        temp = next(temp);
                    }
                }
            }
            return nullptr;
        }
        //! Metodo emptyList
        /*! Metodo que se encarga de vaciar la lista.
         */
        void emptyList() {
            while(first)
            {
                remove(*(first->data));
            }
        }
        
        //! Atributo de la clase que dice el tamaño de la lista
        int n; 
        //! Puntero de tipo celda que indica el primer elemento de la lista.
        P first;
        //! Puntero de tipo celda que indica el ultimo elemento de la lista.
        P last; 
};
#endif /* LISTWITHPOINTER_H */



