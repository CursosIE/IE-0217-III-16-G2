#include "Fire.h"

Fire::Fire(){
    //std::cout<<"Constructor de pokemon tipo Fire"<<std::endl;
}

Fire::~Fire(){
    //std::cout<<"Destructor de pokemon tipo Fire"<<std::endl;
}

std::string Fire::getType(){
    return "Fire";
}

std::string Fire::getStrongVs(){
    return " ";
}

std::string Fire::getWeakVs(){ 
    return "Water and Fire";
}



