#include "Pokemon.hpp"

Pokemon::Pokemon() {

     name= "SinNombreDef";
     species= "SinEspecieDef";
     life=100;
     HP = 1;
     ATK = 1;
     DEF = 1;
     sATK = 1;
     sDEF = 1;
     SPD = 1;
     EXP = 1;
     call = "SinSonidoDef"; 
}

Pokemon::~Pokemon() {

}





void Pokemon::printInfo() {
    cout << "Nombre: "<< name << endl;
    cout << "species: "<< species << endl;
    cout << "life: "<< life << endl;
    cout << "HP: "<< HP << endl;
    cout << "ATK: "<< ATK << endl;
    cout << "DEF: "<< DEF << endl;
    cout << "sATK: "<< sATK << endl;
    cout << "sDEF: "<< sDEF << endl;
    cout << "SPD: "<< SPD << endl;
    cout << "EXP: "<< EXP << endl;
    cout << "call: "<< call << endl;
    
}

string Pokemon::callPokemon() {
   return call;
}





