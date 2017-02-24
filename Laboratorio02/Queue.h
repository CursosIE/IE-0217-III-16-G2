#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "List.h"
#include "Cell.h"
using namespace std;

template <typename D, typename P>
/*!
 Plantilla de la clase Cola, que hereda de la clase Lista.
 */
class Queue : public List<D, P> {
    public:
        //! Constructor de la clase Queue
        /*! Constructor de una cola vacia*/
        Queue(){
            first=last=nullptr;
            n=0;
        }
        
        //! Destructor de la clase Queue
        /*! Llama al método emptyList, para eliminar la cola.*/
        virtual ~Queue()
        {
            emptyList();
        }
        
        
        //! Metodo de insercion de elementos a la cola.
        /*!
         * Dichos elementos solo pueden ser ingresados al final de la cola.
         * Si la cola esta vacia, al insertar el elemento, este tendra los punteros first y last apuntando a él.
           De lo contrario, se crea la conexión entre el penúltimo elemento y el elemento 
         * agregado, y el puntero last apuntará a este elemento.
         *\param d  dato tipo D que será ingresado a la cola. 
         */
        void insert(D d) {
            P newest = new Cell<D>(new D(d),nullptr);
            if(getSize()==0)
            {
                this->first=this->last=newest;
            }
            else
            {
                this->last->next = newest;
                this->last = newest;
            }
           
            n++;
        }
        
        /*! Metodo que remueve el ultimo elemento de la cola.
         * \param d dato tipo D. Irrelevante para la cola.
         */
        void remove(D d) { 
            
            P temp = first;
            if(getSize()>1){
                first = first->next;
            }
            else
            {
                first=last=nullptr;
            }
            delete temp;
            n--;
        }
        
        /*! Metodo find, irrelevante para la cola*/
        P find(D d) 
        { 
            
        }
        
        /*! Metodo assign, irrelevante para la cola*/
        void assign(P k, D d) {

        }
        
        /*! Metodo sort, irrelevante para la cola*/
        void sort() { 
            
        }
        
        /*! Metodo getSize, da el tamaño de la cola.
         \return tamaño*/
        int getSize() { //tamaño
            return n;
        }
        
        /*! Metodo printList, imprime la cola*/
        void printList() { 
            if(first)
            {
                P temp = first;
                for(int i =0; i<this->getSize(); i++)
                {
                    cout<<*(temp->data)<<endl;
                    temp=temp->next;
                }
                cout<<"-------------------------------------------------------"<<endl;
            cout<<"-------------------------------------------------------"<<endl;
            }
            else
            {
                cout<<"La cola esta vacia"<<endl;
            }
        }
        
        /*! Metodo next, irrelevante para la cola*/
        P next(P k) { 
            
        }
        
        /*! Metodo prev, irrelevante para la cola*/
        P prev(P k) { //anterior
            
        }
        
        /*! Metodo get, irrelevante para la cola*/
        D get(P k){
        
        }
        
        /*! Metodo emptyList, elimina todos los elementos pertenecientes a la cola.*/
        void emptyList() {
           while(first)
            {
               remove(*(first->data));
            }
        }
            //! Numero de elementos de la cola
            int n; 
            //! Puntero que apunta al primer elemento de la cola
            P first; 
            //! Puntero que apunta al último elemento de la cola
            P last; 
};


#endif /* QUEUE_H */

