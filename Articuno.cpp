#include "Articuno.hpp"

Articuno::Articuno() {

    Type= Water::type() + "/" + Flying::type();
    strongVs= Water::strongVs() + ", " + Flying::strongVs();
    weakVs= Water::weakVs() + ", " + Flying::weakVs();
}

Articuno::~Articuno() {
 
}

void Articuno::printPokemon(){
 cout << "Tipo: "<< Type << endl;
 cout << "Es fuerte contra los tipo: "<< strongVs << endl;
 cout << "Es debil contra los tipo: "<< weakVs << endl;

}

void Articuno::atk1(Pokemon &other){
if (ATK >= other.DEF)  
   {  
     other.life = other.life - 3*(ATK - other.DEF); 
     EXP=EXP +3;
   }  

   else  
   {  
     life = life - 3*(other.DEF - ATK); 
     other.EXP= other.EXP +3;
   }  
}

void Articuno::atk2(Pokemon &other){
if (sATK >= other.sDEF)  
   {  
     other.life = other.life - 2*(sATK - other.sDEF); 
     EXP=EXP +2;
   }  

   else  
   {  
     life = life - 2*(other.sDEF - sATK); 
     other.EXP= other.EXP +2;
   }  
}

void Articuno::atk3(Pokemon &other){
if (SPD >= other.SPD)  
   {  
     other.life = other.life - (SPD - other.SPD); 
     EXP=EXP +1;
   }  

   else  
   {  
     life = life - (other.SPD - SPD); 
     other.EXP= other.EXP +1;
   }  
}

void Articuno::atk4(Pokemon &other){
if (life < 90)  
   {  
     life = life +4; 
   }  

   else  
   {  
    life=life;
   }  
}
