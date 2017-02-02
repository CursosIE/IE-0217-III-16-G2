#include "Zorro.h"
#include "Matriz.h"
/*Constructor de la clase Lobo, se inicializan los atributos: especie, energia y el sexo del Zorro.*/
Zorro::Zorro() {
    especie="Zorro";
    energia=50;
    if(identificador[1]=='M')
    {
        sexo="Macho";
    }
    else
    {
        sexo="Hembra";
    }
}
/*Destructor de la clase Zorro*/
Zorro::~Zorro() {
}

/*Metodo sobrecargado del operador unario ! que se encarga de mover al animal*/
void Zorro::operator!()
{
    int counter=0;
    while(counter<2)/*A la clase Zorro le corresponde moverse dos veces por dia*/
    {
        int* espacio = getEspacio();/*Se llama a la funcion getEspacio dentro de la clase Animal*/
        if(espacio==NULL)/*Si el arreglo espacio esta vacio, no existen espacios vacios alrededor del Zorro*/
        {
            cout<<"No se puede desplazar, no hay espacios libres"<<endl;
            break;
        }
        else /*De lo contrario, el Zorro se mueve a las coordenadas guardadas en el arreglo espacio*/
        {
            Matriz::campo[espacio[0]][espacio[1]].animal=Matriz::campo[ubicacion[0]][ubicacion[1]].animal;
            Matriz::campo[ubicacion[0]][ubicacion[1]].animal=NULL;
            Matriz::campo[espacio[0]][espacio[1]].animal->ubicacion[0]=espacio[0];
            Matriz::campo[espacio[0]][espacio[1]].animal->ubicacion[1]=espacio[1];
            counter++;
        }
         /*Se elimina el arreglo dinamico espacio*/
        delete [] espacio;
    }
    seMovio=true;
}
/*Metodo comer, sobrecargado con el operador unario ++*/
void Zorro::operator++(int)
{
    int* ubpresa=buscar("R");//El Zorro busca a sus alrededores un animal tipo Raton.
    if(ubpresa!=NULL) // Existe alimento, gana 3e.
    {
        cout<<"El Zorro se ha comido a un raton"<<endl;
        Matriz::campo[ubpresa[0]][ubpresa[1]].animal=NULL;
        energia = energia+3;
    }
    else //Si ubpresa esta vacio, no existe alimento alrededor de zorro.
    {
        cout<<"No existe alimento cerca de Zorro"<<endl;
    }
}

/*Metodo reproducir, sobrecargado con operador unario ~*/
void Zorro::operator~()
{
    string buscado;
    
	if(identificador=="ZM")
            buscado= "ZH";
	if(identificador=="ZH")
            buscado= "ZM";

    /*Se crea un arreglo dinamico, donde se guarda
    *la ubicacion de la pareja, en caso de no existir permanece vacio.*/	
    int* ubicPareja= NULL;
    ubicPareja= buscar(buscado);
    
    if (ubicPareja!= NULL){  //Tiene pareja para reproducirse en su vecindario
        /*Se busca un espacio vacio alrededor de alguno de los dos animales involucrados*/
	string buscado2= "--";
	int* ubicEspacioVacio= NULL;
	ubicEspacioVacio= buscar(buscado2);
	
	if (ubicEspacioVacio== NULL){/*Si despues de buscar espacios alrededor del animal1 el arreglo esta vacio,
                                       *Se buscan espacios alrededor de la pareja.*/
            ubicEspacioVacio= Matriz::campo[ubicPareja[0]][ubicPareja[1]].animal->buscar(buscado2);
	}
        
        if (ubicEspacioVacio!= NULL && (Matriz::campo[ubicPareja[0]][ubicPareja[1]].animal->seReprodujo==false && seReprodujo==false)){
            /*Si se encuentra un espacio vacio,
            *los animales se reproducen, por lo tanto cambia su estado de seReprodujo*/
            Matriz::campo[ubicPareja[0]][ubicPareja[1]].animal->seReprodujo=true;
            seReprodujo=true;

            //Se crea un bebe en la posicion vacia
            Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal=new Zorro;
            Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->ubicacion[0]=ubicEspacioVacio[0];
            Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->ubicacion[1]=ubicEspacioVacio[1];
            Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->sexo= getSex();
            
           
            //Se asigna el sexo
            if (Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->sexo=="M"){
                Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->identificador="ZM";
            }
            if(Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->sexo=="H"){
                Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->identificador="ZH";
            }  
	cout << "Se Reprodujo " << Matriz::campo[ubicacion[0]][ubicacion[1]].animal->especie<< " en "<< ubicacion[0] << ", " << ubicacion[0] <<endl;
	cout << "nace animal " << Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->especie<< " en "<< ubicEspacioVacio[0] << ", " << ubicEspacioVacio[1] <<endl;
        }
    }
}


/*Metodo morir sobrecargado operador unario
 *Si la energia del animal alcanza un valor igual a cero este muere*/
void Zorro::operator--(int)
{
	if(energia==0){
            Matriz::campo[ubicacion[0]][ubicacion[1]].animal=NULL;
	}
}

void Zorro::machoAlfa(){

}