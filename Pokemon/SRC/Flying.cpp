#include "Flying.hpp"
//Constructor de Flying
Flying::Flying() {
   
}
//Destructor de Flying
Flying::~Flying() {
}
//Metodos
string Flying::type(){
    return "Flying";
}

string Flying::strongVs() {
    return "Electric, Ice, Rock";
}

string Flying::weakVs() {
    return "Grass, Fight, Bug";
}
