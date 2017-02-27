#ifndef ZAPDOS_HPP
#define ZAPDOS_HPP

#include "Pokemon.hpp"
#include <iostream>
#include "Electric.hpp"
#include "Flying.hpp"

using namespace std;
//Zapdos es un pokemon tipo electric y tipo flying, así que hereda de ambas clases.
class Zapdos : public Electric, public Flying {
public:

    Zapdos();
    virtual ~Zapdos();
//Atributos
    string Type; 
    string strongVs;
    string weakVs;

//Implementación de los métodos virtuales puros. 
   void atk1(Pokemon &other);
   void atk2(Pokemon &other);
   void atk3(Pokemon &other);
   void atk4(Pokemon &other);

   void printPokemon();

};

#endif /* ZAPDOS_HPP */
