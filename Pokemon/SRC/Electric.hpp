
#ifndef ELECTRIC_HPP
#define ELECTRIC_HPP

#include "Pokemon.hpp"
#include <iostream>

using namespace std;

class Electric : virtual public Pokemon {
public:

    Electric();
    virtual ~Electric();

//Metodos estaticos string
    static string type();
    static string strongVs();
    static string weakVs();
};




#endif /* ELECTRIC_HPP */

