#ifndef MOLTRES_HPP
#define MOLTRES_HPP

#include "Pokemon.hpp"
#include <iostream>
#include "Fire.hpp"
#include "Flying.hpp"

using namespace std;

class Moltres : public Fire , public Flying {
public:

    Moltres();
    virtual ~Moltres();

    string Type; 
    string strongVs;
    string weakVs;


   void atk1(Pokemon &other);
   void atk2(Pokemon &other);
   void atk3(Pokemon &other);
   void atk4(Pokemon &other);

   void printPokemon();
};

#endif /* MOLTRES_HPP */
