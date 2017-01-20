#include "Flying.hpp"

Flying::Flying() {
   
}

Flying::~Flying() {
}

string Flying::type(){
    return "Flying";
}

string Flying::strongVs() {
    return "Electric, Ice, Rock";
}

string Flying::weakVs() {
    return "Grass, Fight, Bug";
}
