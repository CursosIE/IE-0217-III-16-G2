#ifndef FIRE_HPP
#define FIRE_HPP

#include "Pokemon.hpp"
#include <iostream>

using namespace std;

class Fire : virtual public Pokemon {
public:

    Fire();
    virtual ~Fire();

    static string type();
    static string strongVs();
    static string weakVs();
};




#endif /* FIRE_HPP */
