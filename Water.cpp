#include "Water.hpp"

Water::Water() {
    
}

Water::~Water() {
   
}

string Water::type() {
    return "Water";
}

string Water::strongVs() {
    return "Electric, Grass";
}

string Water::weakVs() {
    return "Fire, Ground, Rock";
}

