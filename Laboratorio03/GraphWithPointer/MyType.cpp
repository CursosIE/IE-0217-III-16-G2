#include "MyType.h"

/*! Constructor de la clase MyType. 
    Asigna el valor de a al atributo content.
    \param a caracter que se desea que tenga el objeto*/
MyType::MyType(char a) {
    this->content = a;
}

//! \brief Constructor por copia
MyType::MyType(const MyType& orig) {
}

//! \brief Destructor 
MyType::~MyType() {
}

/*! Sobrecarga del operador ==
    \return true si los objetos son iguales
 *  \return false si los objetos son diferentes
 */
bool MyType::operator==(const MyType &other)
{
    if (this->content == other.content)
    {
        return true;
    }
    else return false;
}

/*! Sobrecarga del operador * 
    \return el atributo content del objeto*/
char MyType::operator*()
{
    return this->content;
}
