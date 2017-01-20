#include "Moltres.hpp"

Moltres::Moltres() {
    cout << "Constructor de Moltres" << endl;
    Type= Fire::type() + "/" + Flying::type();
    strongVs= Fire::strongVs() + ", " + Flying::strongVs();
    weakVs= Fire::weakVs() + ", " + Flying::weakVs();
}

Moltres::~Moltres() {
    cout << "Destructor de Moltres" << endl;
}

void Moltres::printPokemon(){
 cout << "Tipo: "<< Type << endl;
 cout << "Es fuerte contra los tipo: "<< strongVs << endl;
 cout << "Es debil contra los tipo: "<< weakVs << endl;

}

void Moltres::atk1(Pokemon &other){
if (ATK >= other.DEF)  
   {  
     other.life = other.life - (ATK - other.DEF); 
     EXP=EXP +1;
   }  

   else  
   {  
     life = life - (other.DEF - ATK); 
     other.EXP= other.EXP +1;
   }  

}

void Moltres::atk2(Pokemon &other){
if (sATK >= other.sDEF)  
   {  
     other.life = other.life - 3*(sATK - other.sDEF); 
     EXP=EXP +3;
   }  

   else  
   {  
     life = life - 3*(other.sDEF - sATK); 
     other.EXP= other.EXP +3;
   }  
}

void Moltres::atk3(Pokemon &other){
if (SPD >= other.SPD)  
   {  
     other.life = other.life - 2*(SPD - other.SPD); 
     EXP=EXP +2;
   }  

   else  
   {  
     life = life - 2*(other.SPD - SPD); 
     other.EXP= other.EXP +2;
   }  
}

void Moltres::atk4(Pokemon &other){
if (life < 70)  
   {  
     life = life +6; 
   }  

   else  
   {  
    life=life;
   }  
}
