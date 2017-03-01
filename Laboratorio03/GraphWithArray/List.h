#ifndef LIST_H
#define LIST_H


template <typename D, typename P>
/*!
 Plantilla de la clase List
 */
class List {
public:
    /*! Constructor de la clase Lista sin atributos*/
    List() {}
    
    /*! Constructor de la clase Lista.
     \param t tamaño de la lista*/
    List(int t) {}
    
    /*! Constructor por copia*/
    List(const List& orig) {}
    
    /*! Destructor de la clase lista*/
    virtual ~List() {}

    /*! Metodo virtual insert, agrega el dato d a la lista.
     \param d dato tipo D que se desea agregar a la lista*/
    virtual void insert(D d) = 0; //insertar
    
     /*! Metodo virtual remove , remueve el dato d de la lista, si este existe.
     \param d dato tipo D que se desea remover de la lista*/
    virtual void remove(D d) = 0; //remover
    
    /*! Metodo virtual find, busca dentro de la lista el dato d.
     \param d dato tipo D que se desea encontrar.
     \return posicion o celda donde se encuentra el dato*/
    virtual P find(D d) = 0; //buscar
    
    /*! Metodo virtual get, da el valor que se encuentra almacenado en la posicion k.
     \param k dato tipo P, es una posicion o celda.
     \return retorna el valor almacenado en k*/
    virtual D get(P k) = 0; //obtener
    
    /*! Metodo virtual assign, asigna a una determinada posicion k, el valor d
     \param k dato tipo P, es una posicion o celda.
     \param d dado tipo D, que se quiere asignar a k*/
    virtual void assign(P k, D d) = 0; //asignar
    
    /*! Metodo virtual sort, ordena la lista*/
    virtual void sort() = 0; //ordenar
    
    /*! Metodo virtual getSize, da el tamaño de la lista.
     \return el tamaño de la lista*/
    virtual int getSize() = 0; //tamaño
    
    /*! Metodo printList, imprime la lista*/
    virtual void printList() = 0; //imprimir
    
    /*! Metodo next, da la posicion o celda que le sigue a k
     \param k dato tipo P, es una posicion o celda.
     \return la posicion siguiente a k*/
    virtual P next(P k) = 0; //siguiente
    
    /*! Metodo next, retorna la posicion o celda que precede a k
     \param k dato tipo P, es una posicion o celda.
     \return la posicion previa a k*/
    virtual P prev(P k) = 0; //anterior
    
    /*! Metodo emptyList, vacia la lista*/
    virtual void emptyList() = 0; //vaciar

private:
    //! Numero de elementos en la lista
    int n; //num. elemento
    //! Indica el ultimo elemento de la lista
    P last; //ultimo
    //! Indica el primer elemento de la lista
    P first;

};


#endif /* LIST_H */
