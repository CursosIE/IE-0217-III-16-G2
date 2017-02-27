#include "Fire.hpp"
//Constructor de Fire
Fire::Fire() {

}
//Destructor de Fire
Fire::~Fire() {

}

//Metodos 
string Fire::type() {
    return "Fire";
}

string Fire::strongVs() {
    return "Water, Ground, Rock";
}

string Fire::weakVs() {
    return "Grass, Ice, Bug, Steel";
}

