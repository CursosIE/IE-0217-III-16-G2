#ifndef MYTYPE_H
#define MYTYPE_H

using namespace std;

//! Clase MyType
/*!
 Clase que tiene como atributo una variable de tipo char.
 */
class MyType {
public:
    //! Atributo de la clase MyType que contiene un character. 
    char content;
    
    /*! \brief Constructor de la clase MyType
     \param a caracter que se le va a asignar al objeto*/
    MyType(char a);
    
    /*! \brief Constructor por copia*/
    MyType(const MyType& orig);
    
    //! Destructor de la clase MyType.
    virtual ~MyType();
    
    /*! Metodo que sobrecarga el operador ==*/
    bool operator==(const MyType &other);
    
    /*! Metodo que sobrecarga el operador * */
    char operator*();
};
    
#endif /* MYTYPE_H */

