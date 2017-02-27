#include "Moltres.hpp"
//Constructor de Moltres
Moltres::Moltres() {
    //Se concatena el llamado a los metodos string type() de Fire y Flying, que retornan el tipo. 
    Type= Fire::type() + "/" + Flying::type();
   //Se concatena el llamado a los metodos string strongVs() de Fire y Flying, que retornan el tipo contra contra quien es     fuerte el pokemon. 
    strongVs= Fire::strongVs() + ", " + Flying::strongVs();
 //Se concatena el llamado a los metodos string weakVs() de Fire y Flying, que retornan el tipo contra contra quien es debil el pokemon. 
    weakVs= Fire::weakVs() + ", " + Flying::weakVs();
}
//Destructor de Moltres
Moltres::~Moltres() {
}
//Metodo para imprimir estado 
void Moltres::printPokemon(){
 cout << "Tipo: "<< Type << endl;
 cout << "Es fuerte contra los tipo: "<< strongVs << endl;
 cout << "Es debil contra los tipo: "<< weakVs << endl;

}

//Primer ataque
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
//Segundo ataque
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
//Tercer ataque
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
//Cuarto ataque
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
