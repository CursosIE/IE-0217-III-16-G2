#ifndef ZAPDOS_HPP
#define ZAPDOS_HPP

#include "Pokemon.hpp"
#include <iostream>
#include "Electric.hpp"
#include "Flying.hpp"

using namespace std;

class Zapdos : public Electric, public Flying {
public:

    Zapdos();
    virtual ~Zapdos();

    string Type; 
    string strongVs;
    string weakVs;


   void atk1(Pokemon &other);
   void atk2(Pokemon &other);
   void atk3(Pokemon &other);
   void atk4(Pokemon &other);

   void printPokemon();





};

#endif /* ZAPDOS_HPP */
