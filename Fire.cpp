#include "Fire.hpp"

Fire::Fire() {

}

Fire::~Fire() {

}

string Fire::type() {
    return "Fire";
}

string Fire::strongVs() {
    return "Water, Ground, Rock";
}

string Fire::weakVs() {
    return "Grass, Ice, Bug, Steel";
}

