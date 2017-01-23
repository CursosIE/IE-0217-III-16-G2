#include "Flying.h"

Flying::Flying(){
    //std::cout<<"Constructor de pokemon tipo Flying"<<std::endl;
}

Flying::~Flying(){
    //std::cout<<"Destructor de pokemon tipo Flying"<<std::endl;
}

std::string Flying::getType(){
    return "Flying";
}

std::string Flying::getStrongVs(){
    return " ";
}

std::string Flying::getWeakVs(){
    return "Electric";
}

