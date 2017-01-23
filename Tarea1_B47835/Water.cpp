#include "Water.h"

Water::Water(){
    //std::cout<<"Constructor de pokemon tipo Water"<<std::endl;
}

Water::~Water(){
    //std::cout<<"Destructor de pokemon tipo Water"<<std::endl;
}

std::string Water::getType(){
    return "Water";
}

std::string Water::getStrongVs(){
    return "Fire";
}

std::string Water::getWeakVs(){ 
    return "Water";
}

