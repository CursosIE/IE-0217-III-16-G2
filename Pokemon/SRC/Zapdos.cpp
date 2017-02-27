#include "Zapdos.hpp"
//Constructor de Zapdos
Zapdos::Zapdos() {
    //Se concatena el llamado a los metodos string type() de Electric y Flying, que retornan el tipo.
    Type= Electric::type() + "/" + Flying::type();
    //Se concatena el llamado a los metodos string strongVs() de Electric y Flying, que retornan el tipo contra contra quien es     fuerte el pokemon.
    strongVs= Electric::strongVs() + ", " + Flying::strongVs();
    //Se concatena el llamado a los metodos string weakVs() de Electric y Flying, que retornan el tipo contra contra quien es debil el pokemon.
    weakVs= Electric::weakVs() + ", " + Flying::weakVs();
}
//Destructor de Zapdos
Zapdos::~Zapdos() {
}

//Metodo para imprimir estado
void Zapdos::printPokemon(){
 cout << "Tipo: "<< Type << endl;
 cout << "Es fuerte contra los tipo: "<< strongVs << endl;
 cout << "Es debil contra los tipo: "<< weakVs << endl;

}
//Ataque 1
void Zapdos::atk1(Pokemon &other){

 if (ATK >= other.DEF)  
   {  
     other.life = other.life - 2*(ATK - other.DEF); 
     EXP=EXP +2;
   }  

   else  
   {  
     life = life - 2*(other.DEF - ATK); 
     other.EXP= other.EXP +2;
   }  
}

//Ataque 2
void Zapdos::atk2(Pokemon &other){
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
//Ataque 3
void Zapdos::atk3(Pokemon &other){
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
//Ataque 4
void Zapdos::atk4(Pokemon &other){
if (life < 50)  
   {  
     life = life +9; 
   }  

   else  
   {  
    life=life;
   }  


}
