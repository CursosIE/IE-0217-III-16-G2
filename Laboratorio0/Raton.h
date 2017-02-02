
#ifndef RATON_H
#define RATON_H

#include <iostream>
#include "Animal.h"
using namespace std;
class Raton : public Animal 
{
public:
    /*Constructor*/
    Raton();
    /*Destructor*/
    virtual ~Raton();
    /*Metodos sobrecargados con operadores unarios*/
    void operator!();
    void operator++(int);
    void operator~();
    void operator--(int);
    void machoAlfa();
};

#endif /* RATON_H */

