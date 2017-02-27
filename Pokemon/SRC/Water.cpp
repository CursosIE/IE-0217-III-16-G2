#include "Water.hpp"
//Constructor de Water
Water::Water() {
    
}
//Destructor de Water
Water::~Water() {
   
}
//Metodos 
string Water::type() {
    return "Water";
}

string Water::strongVs() {
    return "Electric, Grass";
}

string Water::weakVs() {
    return "Fire, Ground, Rock";
}

