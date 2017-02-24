#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "List.h"
#include "Cell.h"
using namespace std;

template <typename D, typename P>
class Stack : public List<D, P> {
    public:
        //! Constructor Stack.
        /*! Crea el objeto tipo Stack.
	*/
        Stack(){
            first=last=nullptr;
            n=0;
        }

        //! Metodo Insert.
        /*! Inserta un elemento a la pila.
	* Se crea un objeto newest tipo celda, que almacena al dato d.
	* En caso de que la pila este vacia, se almacena esta celda creada en los
	* punteros last y first .
	* En caso de que la pila no este vacia, se realiza la coneccion de manera
	* que ahora la ultima celda se convierta en la penultima(apuntando a la ultima).
	* Se suma 1 a la cantidad de elementos.
        * \param d es un dato tipo D que se desea insertar en la pila.
	* \param newest es un objeto tipo P.

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



	//! Metodo remove.
        /*! Remueve un elemento de la pila.
	* Al ser una pila, se sigue un orden LIFO(Last In First Out)
	* Basicamente se asigna la penultima posicion de la pila como
	*la ultima, descartando el elemento que ingreso a la pila mas
	*recientemente. Se resta 1 a la cantidad de elementos.
	*/
        void remove(D d) {
            if(n>0){
            last= prev(last);
	     n--;
	    }

        }

        P find(D d)
        {

        }

        void assign(P k, D d) {

        }

        void sort() {

        }

	//! Metodo getSize.
        /*! Retorna la cantidad de elementos de la pila.
	\return n, es posible determinar el tamaño de la pila con el atributo n.
	*/

        int getSize() {
            return n;
        }


	//! Metodo printList.
        /*! Imprime la pila.
	* La pila se ve en pantalla en orden descendente, donde los elementos que se
	* agregan a la pila van abajo. Y por lo tanto es de abajo que se tienen
	* que extraer los valores.
	* Se imprime como si fuese una lista, recorriendo todos sus elementos e
	* imprimiendo el dato correspondiente a cada elemento.
	*/
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
                cout<<"La pila esta vacia"<<endl;
            }
        }

        P next(P k) {

        }

	//! Metodo prev.
        /*! Para una pila este metodo no tiene sentido, sin embargo es util
	*para otros metodos de la clase.
	* Este metodo recibe un puntero a un objeto tipo Cell, y recorre toda
	*la pila(tal como una lista), buscando que celda apunta a la celda
	*indicada, a partir del atributo next.
	\param k es un puntero a un objeto tipo Cell.
	\return retorna un puntero a la celda previa si se encontro, caso
	* contrario retorna un nullptr
	*/


        P prev(P k) {
        if(k != first){
                P temp = first;
                for(int i=0; i < this->getSize(); i++)
                {
                        if(k == next(temp))
                        {
                            int a = get(temp);
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

        D get(P k){

        }

        //! Metodo emptyList.
        /*! Este metodo vacia la pila.
	* Se asignan punteros nulos a first y last, y la cantidad de
	* elementos se asigna como  0.
	*/

        void emptyList() {
          n=0;
	  first=last=nullptr;
        }


            //!n es la cantidad de elementos en la pila.
            int n;
            //!first es un puntero a la primera celda de la pila.
            P first;
            //!last  es un puntero a la ultima celda de la pila.
            P last;
};


#endif /* STACK_H */
