#include "Animal.h"
#include "Lobo.h"
#include "Juego.h"

using namespace std;

int main(int argc, char** argv){
    int days;
    /*Se deben recibir 2 parámetros, el primero un entero 
     con la cantidad de días que se desea que transcurran
     y un string con el nombre de un archivo donde se 
     encuentra la configuracion inicial del juego*/ 
    if(argc==3){
    stringstream strInt;
    strInt<<argv[1];
    strInt >> days;
    string text = argv[2];
    //Inicia el juego	
    Juego a;
    a.Jugar(days,text);

    }
    return 0;
}