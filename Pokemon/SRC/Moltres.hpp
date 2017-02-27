#ifndef MOLTRES_HPP
#define MOLTRES_HPP

#include "Pokemon.hpp"
#include <iostream>
#include "Fire.hpp"
#include "Flying.hpp"

using namespace std;
//Moltres es un pokemon tipo fire y tipo flying, así que hereda de ambas clases. 
class Moltres : public Fire , public Flying {
public:

    Moltres();
    virtual ~Moltres();
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

#endif /* MOLTRES_HPP */
