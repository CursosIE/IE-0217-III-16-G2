#include "Pokemon.h"
#include <iostream>
#include <stdlib.h>

Pokemon::Pokemon(){
    // std::cout << "Este es el constructor de mi Pokemon" << std::endl;
}

Pokemon::~Pokemon(){
    // std::cout << "Este es el destructor de mi Pokemon" << std::endl;
}

void Pokemon::inf(){
    std::cout<<"Name:  "<< name <<std::endl;
    std::cout<<"Species: "<< species <<std::endl;
    std::cout<<"HP:  "<< HP <<std::endl;
    std::cout<<"ATK:  "<< ATK <<std::endl;
    std::cout<<"DEF: "<< DEF <<std::endl;
    std::cout<<"sATK: "<< sATK <<std::endl;
    std::cout<<"sDEF: "<< sDEF <<std::endl;
    std::cout<<"SPD: "<< SPD <<std::endl;
    std::cout<<"EXP: "<< EXP <<std::endl;
    std::cout<<"cry"<< cry <<std::endl;
};

double Pokemon::getModifier(double stab,double type){
    int critMult = 1;
    if (isCritHit(SPD))
    {
        critMult = 2;
    }
    return stab*type*critMult*fRand(0.85,1.0);
}

int Pokemon::getDamage(int pwr,int atk, int def,double stab, double type)
{
    double modifier=getModifier(stab,type);
    double damage = ((12/250)*(atk/def)*pwr+2)*modifier*5;
    return (int) damage;
    
}

double Pokemon::fRand(double fMin, double fMax)
{
    double f = (double)rand() / (double)(RAND_MAX);
    return fMin + f * (fMax - fMin);
}

bool Pokemon::isCritHit(int speed)
{
    double treshold = speed /2;
    double x = fRand(0.0,255.0);
    std::cout<<"El valor de x en critical es "<<x<<std::endl;
    if (x <= treshold)
    {
        return true;
        std::cout << "A critical hit!" << std::endl;
    }
    else
    {
        return false;
    }
}

bool Pokemon::hasMissed(int accuracy)
{
    double x = fRand(0.0,1.0);
    std::cout<<"El valor de x en miss es "<<x<<std::endl;
    if (x > accuracy/100)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string Pokemon::doCry(){
    return cry;
}

