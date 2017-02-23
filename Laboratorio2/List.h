#ifndef LIST_H
#define LIST_H

template <typename D, typename P>
class List {
public:
    List() {}
    List(int t) {}
    
    
    List(const List& orig) {}
    virtual ~List() {}

    virtual void insert(D d) = 0; //insertar
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

private:
    int n; //num. elemento
    P last; //ultimo
    P first;

};


#endif /* LIST_H */

