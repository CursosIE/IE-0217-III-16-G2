#include <iostream>
#include "Pokemon.hpp"

#include "Electric.hpp"
#include "Flying.hpp"
#include "Fire.hpp"
#include "Water.hpp"

#include "Zapdos.hpp"
#include "Moltres.hpp"
#include "Articuno.hpp"


using namespace std;

int main(int argc, char** argv) {

cout << "Valores Iniciales:   " << endl;
cout <<  endl;
//Creamos objeto tipo Zapdos:
     Zapdos pZ0;
//Asiganamos estos valores los atributos, los demas mantienen su valor por defecto.
     pZ0.name= "Juancito";
     pZ0.species= "Zapdos";
     pZ0.HP = 5;
     pZ0.ATK = 6;
     pZ0.DEF = 4;
     pZ0.sATK = 8;
     pZ0.sDEF = 6;
     pZ0.SPD = 9;
     pZ0.EXP = 0;
     pZ0.call = "Grrrr"; 



//Creamos Objeto tipo Articuno:
     Articuno pZ1;
//Asiganamos estos valores los atributos, los demas mantienen su valor por defecto.
     pZ1.name= "Pedrito";
     pZ1.species= "Articuno";
     pZ1.HP = 3;
     pZ1.ATK = 8;
     pZ1.DEF = 7;
     pZ1.sATK = 7;
     pZ1.sDEF = 5;
     pZ1.SPD = 11;
     pZ1.EXP = 0;
     pZ1.call = "Brrrr"; 


//Vamos a simular una batalla pokemon. 
// Estado inicial
     pZ0.printInfo();
  cout << endl << endl;
     pZ1.printInfo();
  cout << endl << endl;

//PRIMER ATAQUE
    pZ1.atk1(pZ0);
    pZ0.atk1(pZ1);

     cout << "PRIMERA RONDA ATAQUE: " << endl << endl;

     pZ0.printInfo();
  cout << endl << endl;
     pZ1.printInfo();
  cout << endl << endl;

//SEGUNDO ATAQUE
    pZ1.atk2(pZ0);
    pZ0.atk2(pZ1);

     cout << "SEGUNDA RONDA ATAQUE: " << endl << endl;

     pZ0.printInfo();
  cout << endl << endl;
     pZ1.printInfo();
  cout << endl << endl;

//TERCER ATAQUE
   pZ1.atk3(pZ0);
   pZ0.atk3(pZ1);
     
  cout << "TERCERA RONDA ATAQUE: " << endl << endl;

    pZ0.printInfo();
  cout << endl << endl;
    pZ1.printInfo();
  cout << endl << endl;

//Se puede continuar con los ataques, y definir una regla para que un pokemon gane la batalla. Esto era una demostración de los pokemon interactuan correctamente. 

    return 0;
};

