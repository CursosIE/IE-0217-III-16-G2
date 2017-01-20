#ifndef ARTICUNO_HPP
#define ARTICUNO_HPP

#include "Pokemon.hpp"
#include <iostream>
#include "Water.hpp"
#include "Flying.hpp"

using namespace std;

class Articuno : public Water, public Flying {
public:

    Articuno();
    virtual ~Articuno();

    string Type; 
    string strongVs;
    string weakVs;


   void atk1(Pokemon &other);
   void atk2(Pokemon &other);
   void atk3(Pokemon &other);
   void atk4(Pokemon &other);

   void printPokemon();





};

#endif /* ARTICUNO_HPP */
