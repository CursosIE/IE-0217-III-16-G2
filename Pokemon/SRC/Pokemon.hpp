
#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <iostream>

using namespace std;

class Pokemon {
public:
    Pokemon();
    virtual ~Pokemon();
   
    //Metodos
    void printInfo();
    string callPokemon();
    
    //Metodos virtuales puros, que estan implementados en una clase inferior
    virtual void atk1(Pokemon &other)=0;
    virtual void atk2(Pokemon &other)=0;
    virtual void atk3(Pokemon &other)=0;
    virtual void atk4(Pokemon &other)=0;

    //Atributos
    string name;
    string species;
    int life;
    int HP;
    int ATK;
    int DEF;
    int sATK;
    int sDEF;
    int SPD;
    int EXP;
    string call; 
   
};

#endif /* POKEMON_HPP */
