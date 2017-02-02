#ifndef OVEJA_H
#define OVEJA_H

#include <iostream>
#include "Animal.h"
using namespace std;
class Oveja : public Animal 
{
public:
    /*Constructor*/
    Oveja();
    /*Destructor*/
    virtual ~Oveja();
    /*Metodos sobrecargados*/
    void operator!();
    void operator++(int);
    void operator~();
    void operator--(int);
    void machoAlfa();
};

#endif /* OVEJA_H */

