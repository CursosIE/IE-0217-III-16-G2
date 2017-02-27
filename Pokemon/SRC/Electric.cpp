#include "Electric.hpp"
//Constructor de Electric
Electric::Electric() {
}
//Destructor de Electric
Electric::~Electric() {
}
//Metodos
string Electric::type() {
    return "Electric";
}

string Electric::strongVs() {
    return "Ground";
}

string Electric::weakVs() {
    return "Water, Flying";
}




