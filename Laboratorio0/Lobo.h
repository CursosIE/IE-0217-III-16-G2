#ifndef LOBO_H
#define LOBO_H
#include <iostream>
#include "Animal.h"
using namespace std;
/*Clase lobo, hereda de la clase animal*/
class Lobo : public Animal{
public:
    Lobo();
    virtual ~Lobo();
    /*Metodos donde se sobrecargan operadores unarios*/
    void operator!();
    void operator++(int);
    void operator~();
    void operator--(int);
    void machoAlfa();
};

#endif /* LOBO_H */

