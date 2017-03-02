#ifndef LISTACONARREGLO_H
#define LISTACONARREGLO_H
#include <iostream>
//#include "Lista.h"
using namespace std;

//Lista de double con arreglo en vasco 

template <typename D, typename P>
class ListaConArreglo  {
public:
    
ListaConArreglo() {
    data = nullptr;
    this->n = 0;
    this->maxElements = 0;
}

ListaConArreglo(int t) {
    data = new D[t];
    this->n = 0;
    this->maxElements = t;
}

ListaConArreglo(const ListaConArreglo& orig) {
}

~ListaConArreglo() {
    delete[] data;

}

void insert(D d) { //insertar
    if (this->getSize() == 0) //lista vacia
    {
        this->data = new D[10];
        this->n = 1;
        this->last = 1;
        this->maxElements = 10;
        this->data[0] = d;
    } else { //lista con algo
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

P find(D d) { //buscar
    for (int i = 0; i < this->getSize(); i++) {
        if (d == this->get(i))
            return i;
    }
    return -1;
}

D get(P k) { //obtener
    return data[k];
}

void assign(P k, D d) {
    this->data[k] = d;
}

void sort() { //ordenar

}

int getSize() { //tamaño
    return this->n;
}

void printList() { //imprimir
    for (int i = 0; i < this->getSize(); i++) {
        cout << this->get(i) << endl;
    }
}

P next(P k) { //siguiente
    if (k < this->getSize())
        return k + 1;
    else
        return -1;
}

P prev(P k) { //anterior
    if (k > 0)
        return k - 1;
    else
        return -1;
}

void emptyList() { //vaciar
    this->n = 0;
}



    int n; //num. elementos
    int maxElements; //máximo;
    P last; //ultimo
    D* data; //datos
};

#endif /* LISTACONARREGLO_H */

