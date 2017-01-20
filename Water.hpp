#ifndef WATER_HPP
#define WATER_HPP

#include "Pokemon.hpp"
#include <iostream>

using namespace std;

class Water : virtual public Pokemon {
public:

    Water();
    virtual ~Water();

    static string type();
    static string strongVs();
    static string weakVs();
};




#endif /* WATER_HPP */
