
#ifndef FLYING_HPP
#define FLYING_HPP

#include "Pokemon.hpp"
#include <iostream>

using namespace std;

class Flying : virtual public Pokemon {
public:
    Flying();
    virtual ~Flying();

    static string type();
    static string strongVs();
    static string weakVs();
};


#endif /* FLYING_HPP */

