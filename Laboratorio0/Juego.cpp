#include "Juego.h"
/*Se tiene a continuacion un metodo emplantillado util para 
imprimir el estado de cualquier animal, imprimiento sus 
atributos*/
template<typename Any>
void ImprimirEstado (Any elemento){
cout <<"Identificador: " << elemento->identificador << endl;
cout << "Especie: " << elemento->especie<<endl;
//cout << "Sexo: " << elemento->sexo<< endl;
}


Juego::Juego() {
}

Juego::~Juego() {
}

void Juego::Jugar(int dias, string text){

    Matriz matriz(text);
    matriz.imprimir();
 
    cout<< "Inicia el Juego" << endl;

    //Este for, se encarga de repetir el ciclo la cantidad de dias indicada
    for (int i=0; i<dias; i++){
        
        /*A continuacion se tiene una variable llamada esMultiplo que contiene 0
          si el numero de dias no es multiplo de 3 o 1 si si lo es*/

	int esMultiplo=0;
		if((i+1) >= 3){
	        //si el modulo es cero, entonces es multiplo
        	if((i+1)%3 == 0)
            		esMultiplo=1;
		else
			esMultiplo=0;
            					}
        /*Para todas las posiciones del campo, se dan condiciones iniciales luego de cada día, al final del 
        dia los animales pierden 1e y si es un día multiplo de 3 el campo gana 5 de energía*/
	for(int m=0; m<matriz.numfilas; m++){
		for(int b=0;b<matriz.numcolumnas;b++){
			if (matriz.campo[m][b].animal !=NULL){
				//VALORES INICIALES DIA:
				matriz.campo[m][b].animal->seReprodujo= false;
				matriz.campo[m][b].animal->seMovio= false;
                               

				//VALORES FINAL DIA:
				matriz.campo[m][b].animal->energia= (matriz.campo[m][b].animal->energia -1);  
			}
				//ENERGIA
				if (matriz.campo[m][b].energia>0 && (matriz.campo[m][b].energia<=95 && esMultiplo==1)){
					matriz.campo[m][b].energia=matriz.campo[m][b].energia+5;
				}
		}
	}
	//Se recorren todas las casillas dando orden de moverse a todos los animales, si ya se movio una vez no 
        //se vuelve a mover durante el día
        cout<< "movimiento dia: " << i<< endl;
        for(int j=0; j<matriz.numfilas; j++){
            for(int k=0;k<matriz.numcolumnas;k++){
                if(matriz.campo[j][k].animal!=NULL && matriz.campo[j][k].animal->seMovio==false){
                    ImprimirEstado(matriz.campo[j][k].animal);
		    !(*matriz.campo[j][k].animal);
                    matriz.imprimir();
                }
            }    
	}
        
        //Se recorren todas las casillas dando orden de comer a todos los animales, si ya comio una vez no 
        // vuelve a comer durante el día
	for(int j=0; j<matriz.numfilas; j++){
		for(int k=0;k<matriz.numcolumnas;k++){
			if (matriz.campo[j][k].animal !=NULL){
				(*matriz.campo[j][k].animal)++;
                                matriz.imprimir();
				
			}
		}
	}

	//Se recorren todas las casillas verificando si algun animal se reproduce, si ya lo hizo una vez no 
        //se vuelve a reproducir durante el día        
	for(int j=0; j<matriz.numfilas; j++){
		for(int k=0;k<matriz.numcolumnas;k++){
			if (matriz.campo[j][k].animal !=NULL && matriz.campo[j][k].animal->seReprodujo==false){
				~(*matriz.campo[j][k].animal);
				if (matriz.campo[j][k].animal->seReprodujo==true){
					matriz.imprimir();
					
				}			
			}
		}
	}
        
	 cout<< "muerte dia: " << i<< endl;
	//Revisa que la cantidad de energía de un animal sea mayor a 0, sino el animal muere
	for(int j=0; j<matriz.numfilas; j++){
		for(int k=0;k<matriz.numcolumnas;k++){
			if (matriz.campo[j][k].animal !=NULL){
				(*matriz.campo[j][k].animal)--;
				}
		}
	}


    matriz.imprimir();
    cout<< "ha acabado el dia..."<<endl;
    }
    cout<<"Fin del juego!!"<<endl;
  }

