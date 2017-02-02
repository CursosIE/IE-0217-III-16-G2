#ifndef ZORRO_H
#define ZORRO_H

#include <iostream>
#include "Animal.h"

using namespace std;
class Zorro : public Animal 
{
public:
    /*Constructor*/
    Zorro();
    /*Destructor*/
    virtual ~Zorro();
    /*Metodos sobrecargados de operadores unarios*/
    void operator!();
    void operator++(int);
    void operator~();
    void operator--(int);
    void machoAlfa();
};

#endif /* ZORRO_H */

