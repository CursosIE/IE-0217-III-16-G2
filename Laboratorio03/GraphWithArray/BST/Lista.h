
#ifndef LISTA_H
#define LISTA_H

template <typename D, typename P>
class Lista {
public:
    Lista() {}
    Lista(int t) {}
    Lista(const Lista& orig) {}
    virtual ~Lista() {}

    virtual void insert(double d) = 0; //insertar
    virtual void remove(D d) = 0; //remover
    virtual P find(D d) = 0; //buscar
    virtual D get(P k) = 0; //obtener
    virtual void assign(P k, D d) = 0; //asignar
    virtual void sort() = 0; //ordenar
    virtual int getSize() = 0; //tamaño
    virtual void printList() = 0; //imprimir
    virtual P next(P k) = 0; //siguiente
    virtual P prev(P k) = 0; //anterior
    virtual void emptyList() = 0; //vaciar
    int n; //num. elementos

private:
    int maxElements; //máximo;
    P last; //ultimo
    D* datuak; //datos

};

#endif /* LISTA_H */

