#include "Electric.h"

Electric::Electric(){
    // std::cout<<"Constructor de pokemon tipo electrico"<<std::endl;
}

Electric::~Electric(){
    // std::cout<<"Destructor de pokemon tipo electrico"<<std::endl;
}

std::string Electric::getType(){
    return "Electric";
}

std::string Electric::getStrongVs(){
    return "Water and Flying";
}

std::string Electric::getWeakVs(){
    return " ";
}
