#ifndef ARTICUNO_HPP
#define ARTICUNO_HPP

#include "Pokemon.hpp"
#include <iostream>
#include "Water.hpp"
#include "Flying.hpp"

using namespace std;
//Articuno es un pokemon tipo water y tipo flying, así que hereda de ambas clases. 
class Articuno : public Water, public Flying {
public:

    Articuno();
    virtual ~Articuno();

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

#endif /* ARTICUNO_HPP */
