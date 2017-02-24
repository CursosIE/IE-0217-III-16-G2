#ifndef LISTWITHARRAY_H
#define LISTWITHARRAY_H

#include <iostream>
#include "List.h"
using namespace std;

template <typename D, typename P>
class ListWithArray : public List<D, P> {
    public:

 //! Constructor ListWithArray.
 /*! Crea el objeto tipo ListWithArray.
  * Se inicializan los atributos de la clase a un valor neutro.
  * Se asigna nullptr a los punteros y 0 a la cantidad de elementos.
  */

    ListWithArray() {
           data = nullptr;
           this->n = 0;
           this->maxElements = 0;
       }


 //! Constructor por copia de ListWithArray.
 /*! Crea el objeto tipo ListWithArray.
  * Se crea un arreglo de tamaño t y de tipo D.
  * \param t es la cantidad de elementos.
  */

  ListWithArray(int t) {
           data = new D[t];
           this->n = 0;
           this->maxElements = t;
       }


ListWithArray(const ListWithArray& orig) {
}

//! Destructor de la clase ListWithArray
~ListWithArray() {
    delete[] data;
}


 //! Se inserta un elemento d a la lista.
 /*! Se inserta el elemento de la siguiente forma.
  *En caso de que la lista este vacia, se crea por defecto un
  *arreglo de tamaño 10, donde se asigna 10 como la maxima cantidad
  * de elementos de la lista,  y se guarda d en el arreglo data
  * en la posicion 0.
  *En caso de que la lista no este vacia, y aun no alcance su maxima
  *cantidad de elementos se guarda d en el arreglo data en la
  *posicion last.
  *En caso de que el arreglo este lleno, se crea un arreglo nuevo del
  *doble de tamaño, se reajusta la maxima cantidad de elementos y ahora
  *si es posible insertar el valor en la posicion last del arreglo data.
  \param d es el elemento del tipo D que se desea ingresar en la lista.
  */


  void insert(D d) { //insertar
              if (this->getSize() == 0) //list vacia
              {
                  this->data = new D[10];
                  this->n = 1;
                  this->last
                          = 1;
                  this->maxElements = 10;
                  this->data[0] = d;
              } else { //list con algo
                  if (this->getSize() - 1 != last) { //arreglo con espacio
                      this->data[last] = d;
                      this->last++;
                      this->n++;
                  } else { //arreglo sin espacio
                      D* tmp = new D[this->getSize()*2];
                      for (int i = 0; i<this->getSize(); i++) {
                          tmp[i] = this->get(i);
                      }
                      this->maxElements = this->getSize()*2;
                      delete[] this->data;
                      this->data = tmp;
                      this->data[last] = d;
                      this->last++;
                      this->n++;
                  }
              }
          }

 //! Metodo remove.
 /*!  Se busca un elemento d en la lista. En caso de que exista
  * lo remuevo reacomodando la lista.
  * Disminuyo en 1 la cantidad de elementos y a last.
  */

  void remove(D d) { //remover
              int i = this->find(d);
              if (i != -1) {
                  for (i; i< this->getSize() - 1; i++) {
                      this->assign(i, this->get(i + 1));
                  }
                  this->n--;
                  this->last--;
              }
          }


 //! Metodo find.
 /*!  Se busca un elemento d en la lista.
  *Se recorre la lista y si se encuentra un elemento
  *igual a d, se retorna un indice i que indica la posicion
  *en el arreglo de este elemento.
  *En caso de que no se encuentre se retorna -1.
  \param d es el elemento del tipo D que se desea buscar en la lista.
  */

  P find(D d) { //buscar
            for (int i = 0; i < this->getSize(); i++) {
                if (d == this->get(i))
                    return i;
            }
            return -1;
  }

//! Metodo get.
/*! Retorna el contenido en el arreglo data, en la posicion k.
\return k, indica el indice de la lista.
*/
D get(P k) { //obtener
           return data[k];
}

void assign(P k, D d) {
            this->data[k] = d;
        }


//! Metodo Sort
/*! Mediante el algoritmo de ordenamiento Bubble Sort, se ordenan los
* elementos de la lista en orden creciente.
*/
void sort() {
	for(int i=0;i<getSize();i++){
		for(int j=0;j< getSize()-1 ;j++){
			if( this->data[j] >  this->data[j+1]){
				D temp= this->data[j];
			        this->data[j] =  this->data[j+1];
			         this->data[j+1] = temp;
			}

		}
	}

}

//! Metodo getSize.
/*! Retorna la cantidad de elementos de la lista
\return n, es posible determinar el tamaño de la lista con el atributo n.
*/

int getSize() {
    return this->n;
}

//! Metodo printList.
/*! Imprime la lista.
* La lista se ve en pantalla en orden descendente, donde los elementos que se
* agregan a la lista van abajo.
* Se imprime c recorriendo todos sus elementos e imprimiendo el dato. A partir
* del metodo get().
*/
void printList() { //imprimir
    for (int i = 0; i < this->getSize(); i++) {
        cout << this->get(i) << endl;
    }
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"------------------------------------------------------------"<<endl;
}


//! Metodo next.
/*! Este metodo es util para encontrar el elemento siguiente a otro elemento
* de la lista.
\return retorna k+1 en caso de que el elemento k tenga un elemento siguiente.
*caso contrario retorna -1, lo que indica que no hay elemento siguiente.
*/
P next(P k) {
    if (k < this->getSize())
        return k + 1;
    else
        return -1;
}

//! Metodo prev.
/*! Este metodo es util para encontrar el elemento previo a otro elemento
* de la lista.
\return retorna k-1 en caso de que el elemento k tenga un elemento previo.
*caso contrario retorna -1, lo que indica que no hay elemento previo.
*/
P prev(P k) {
    if (k > 0)
        return k - 1;
    else
        return -1;
}


//! Metodo emptyList.
/*! Este metodo vacia la pila.
* La cantidad de elementos se asigna como  0.
*/

void emptyList() { //vaciar
    this->n = 0;
}


protected:
    //! Numero de elementos de la lista
    int n; //num. elementos
    //! Maxima cantidad de elementos que puede contener el arreglo
    int maxElements; //máximo;
    //! Ultimo posicion de la lista
    P last; //ultimo
    //!Puntero que apunda al contenido de un elemento de la lista.
    D* data; //datos
};

#endif /* LISTWITHARRAY_H */
