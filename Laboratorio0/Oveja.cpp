#include "Oveja.h"
#include "Matriz.h"
/*Constructor de la clase Oveja,inicializa los atributos:especie, energia, sexo.*/
Oveja::Oveja() {
    especie="Oveja";
    energia=75;
    if(identificador[1]=='M')
    {
        sexo="Macho";
    }
    else
    {
        sexo="Hembra";
    }
}
/*Destructor de la clase oveja*/
Oveja::~Oveja() {
}

/*Metodo mover sobrecargando operador unario, la oveja se mueve dos veces por turno.*/
void Oveja::operator!()
{
    int counter=0;
    while(counter<2)
    {
        int* espacio = getEspacio();//Busca espacios vacios, y retorna uno aleatoriamente.
        if(espacio==NULL)//Si espacio es igual a nulo, no existen espacios vacios.
        {
            cout<<"No se puede desplazar, no hay espacios libres"<<endl;
            break;
        }
        else //De lo contrario se realiza el cambio de posicion.
        {
            Matriz::campo[espacio[0]][espacio[1]].animal=
                    Matriz::campo[ubicacion[0]][ubicacion[1]].animal;
            Matriz::campo[ubicacion[0]][ubicacion[1]].animal=NULL;
            Matriz::campo[espacio[0]][espacio[1]].animal->ubicacion[0]=espacio[0];
            Matriz::campo[espacio[0]][espacio[1]].animal->ubicacion[1]=espacio[1];
            counter++;
        }
        /*Se elimina el arreglo creado dinamicamente*/
        delete [] espacio;
    }
    seMovio=true;
}

/*Metodo comer sobrecargando operador unario.*/
void Oveja::operator++(int)
{
    
    if(Matriz::campo[ubicacion[0]][ubicacion[1]].energia>10)/*Si la energia es mayor que 10,
                                                             la oveja se puede alimentar.*/
    {
        energia = energia + 10; //Se aumenta 10e en la energia de la Oveja
        //Y decrece en 10e el valor de la energia del campo.
        Matriz::campo[ubicacion[0]][ubicacion[1]].energia =
                Matriz::campo[ubicacion[0]][ubicacion[1]].energia - 10;
        cout<<"La oveja se ha comido 10e..."<<endl;
       
    }
}

/*Metodo reproducir sobrecargado operador unario*/
void Oveja::operator~()
{
    string buscado;
    
	if(identificador=="OM")
            buscado= "OH";
	if(identificador=="OH")
            buscado= "OM";

    /*Se crea un arreglo dinamico, donde se guarda
    *la ubicacion de la pareja, en caso de no existir permanece vacio.*/	
    int* ubicPareja= NULL;
    ubicPareja= buscar(buscado);
    
    if (ubicPareja!= NULL){  //Tiene pareja para reproducirse en su vecindario
        
	/*Se busca un espacio vacio alrededor de alguno de los dos animales involucrados*/
	string buscado2= "--";
	int* ubicEspacioVacio= NULL;
	ubicEspacioVacio= buscar(buscado2);
	
	if (ubicEspacioVacio== NULL){/*Si despues de buscar espacios alrededor del
                                       *animal1 el arreglo esta vacio,
                                       *Se buscan espacios alrededor de la pareja.*/
            ubicEspacioVacio= Matriz::campo[ubicPareja[0]][ubicPareja[1]].animal->buscar(buscado2);
	}
        if (ubicEspacioVacio!= NULL && 
                (Matriz::campo[ubicPareja[0]][ubicPareja[1]].animal->seReprodujo==false
                && seReprodujo==false)){
       		/*Si se encuentra un espacio vacio, los animales se reproducen,
                 *por lo tanto cambia su estado de seReprodujo*/
            Matriz::campo[ubicPareja[0]][ubicPareja[1]].animal->seReprodujo=true;
            seReprodujo=true;

            //Se crea un bebe en la posicion vacia
            Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal=new Oveja;
            Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->ubicacion[0]
                    =ubicEspacioVacio[0];
            Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->ubicacion[1]
                    =ubicEspacioVacio[1];
            Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->sexo= getSex();
            
           
            //Se asigna el  sexo
            if (Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->sexo=="M"){
                Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->identificador
                        ="OM";
            }
            if(Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->sexo=="H"){
                Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->identificador
                        ="OH";
            }  
	cout << "Se Reprodujo " << Matriz::campo[ubicacion[0]][ubicacion[1]].animal->especie<< " en "<< ubicacion[0] << ", " << ubicacion[0] <<endl;
	cout << "nace animal " << Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->especie<< " en "<< ubicEspacioVacio[0] << ", " << ubicEspacioVacio[1] <<endl;
        }
    }
}

/*Metodo morir sobrecargado operador unario
 *Si la energia del animal alcanza un valor igual a cero este muere*/
void Oveja::operator--(int)
{
	if(energia==0){
            Matriz::campo[ubicacion[0]][ubicacion[1]].animal=NULL;
	}
}

void Oveja::machoAlfa(){

}

