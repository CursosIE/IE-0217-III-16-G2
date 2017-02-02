#include "Lobo.h"
#include "Matriz.h"

/*Constructor de la clase Lobo, se inicializan los atributos: especie, energia y el sexo del Lobo.*/
Lobo::Lobo() {
    especie="Lobo";
    energia=100;
    if(identificador[1]=='M')
    {
        sexo="Macho";
    }
    else
    {
        sexo="Hembra";
    }
}

/*Destructor de la clase Lobo*/
Lobo::~Lobo() {
}

/*Metodo sobrecargado del operador unario ! que se encarga de mover al animal*/
void Lobo::operator!()
{
    int counter=0; /*A la clase Lobo le corresponde moverse tres veces por dia*/
    while(counter<3)
    {
        int* espacio = getEspacio(); /*Se llama a la funcion getEspacio dentro de la clase Animal*/
        if(espacio==NULL) /*Si el arreglo espacio esta vacio, no existen espacios vacios alrededor del lobo*/
        {
            cout<<"No se puede desplazar, no hay espacios libres"<<endl;
            break;
        }
        else /*De lo contrario, el Lobo se mueve a las coordenadas guardadas en el arreglo espacio*/
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
    /*Busca si existen Lobos en su nueva posicion*/
    Matriz::campo[ubicacion[0]][ubicacion[1]].animal->machoAlfa();
    seMovio=true;
}

/*Metodo comer, el animal lobo se puede alimentar de cualquier otro animal excepto el mismo. */
 
int opcion=0;
void Lobo::operator++(int)
{
    int haPasadoCiclo=0;
    bool encontrado = false;
    string comida[3]={"O","Z","R"};/*Tiene un arreglo nombrado comida,
                                     que se utiliza para ir variando su presa.*/
    while(!encontrado){
        int* ubpresa = buscar(comida[opcion]);
        /*se utiliza el metodo buscar, para buscar alguna de sus tres presas, solo interesa el
        *primer caracter del identificador del animal.*/
        if(ubpresa!=NULL){
            cout<<"El lobo se ha comido a un/una "<<Matriz::campo[ubpresa[0]][ubpresa[1]].animal->especie<<endl;
            /*Dependiendo de que haya comido su energia aumentara 10, 5 o 3*/
            if(opcion==0)
            {
                energia=energia+10;
            }
            if(opcion==1)
            {
                energia=energia+5;
            }
            if(opcion==2)
            {
                energia=energia+3;
            }
            Matriz::campo[ubpresa[0]][ubpresa[1]].animal=NULL;
            if(opcion!=2){
                opcion++;
            }
            else
            {
                opcion=0;
            }
            encontrado = true;
        }
        else
        {
            if(opcion<2)
            {
                opcion++;
            }
            else if(opcion==2)
            {
                opcion=0;
            }
            /*Si se han buscado los tres animales, y aun asi el arreglo continua 
             *vacio quiere decir que no hay alimento alrededor del lobo.*/
            if(haPasadoCiclo==3)
            {
                cout<<"No existe alimento alrededor de Lobo... :("<<endl;
                encontrado = true;
                haPasadoCiclo=0;
            }
        }
        haPasadoCiclo++;
        delete [] ubpresa;
    }
        
}
    
/*Metodo reproducir sobrecargado operador unario*/
void Lobo::operator~()
{
    string buscado;
    
	if(identificador=="LM")
            buscado= "LH";
	if(identificador=="LH")
            buscado= "LM";

	/*Se crea un arreglo dinamico, donde se guarda
         *la ubicacion de la pareja, en caso de no existir permanece vacio.*/	
    int* ubicPareja= NULL;
    ubicPareja= buscar(buscado);
    
    if (ubicPareja!= NULL){  //Tiene pareja para reproducirse en su vecindario
	/*Se busca un espacio vacio alrededor de alguno de los dos animales involucrados*/
        string buscado2= "--";
	int* ubicEspacioVacio= NULL;
	ubicEspacioVacio= buscar(buscado2);
	
	if (ubicEspacioVacio== NULL){ /*Si despues de buscar espacios alrededor del animal1 el arreglo esta vacio,
                                       *Se buscan espacios alrededor de la pareja.*/
            ubicEspacioVacio= Matriz::campo[ubicPareja[0]][ubicPareja[1]].animal->buscar(buscado2);
	}
        if (ubicEspacioVacio!= NULL && (Matriz::campo[ubicPareja[0]][ubicPareja[1]].animal->seReprodujo==false && seReprodujo==false)){
       		/*Si se encuentra un espacio vacio,
                 *los animales se reproducen, por lo tanto cambia su estado de seReprodujo*/
            Matriz::campo[ubicPareja[0]][ubicPareja[1]].animal->seReprodujo=true;
            seReprodujo=true;

            //Se crea un bebe en la posicion vacia
            Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal=new Lobo;
            Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->ubicacion[0]=ubicEspacioVacio[0];
            Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->ubicacion[1]=ubicEspacioVacio[1];
            Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->sexo= getSex();
            
           
            //Se asigna el sexo
            if (Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->sexo=="M"){
                Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->identificador="LM";
            }
            if(Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->sexo=="H"){
                Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->identificador="LH";
            }  
	cout << "Se Reprodujo " << Matriz::campo[ubicacion[0]][ubicacion[1]].animal->especie<< " en "<< ubicacion[0] << ", " << ubicacion[0] <<endl;
	cout << "nace animal " << Matriz::campo[ubicEspacioVacio[0]][ubicEspacioVacio[1]].animal->especie<< " en "<< ubicEspacioVacio[0] << ", " << ubicEspacioVacio[1] <<endl;
        }
    }
}
/*Metodo morir sobrecargado operador unario
 *Si la energia del animal alcanza un valor igual a cero este muere*/
void Lobo::operator--(int)
{
    
	if(energia==0){
		Matriz::campo[ubicacion[0]][ubicacion[1]].animal=NULL;
	}
}

void Lobo::machoAlfa()
{
    
    if(identificador=="LM"){
    int* ubVs=buscar("LM");/*Un lobo Macho busca si hay algun otro lobo macho a su alrededor*/
    if(ubVs!=NULL)
    {
        cout<<"Enfrentamiento de Lobos"<<endl;
        /*Si existe alguno, el que tenga menor energia morira.*/
        if(energia>Matriz::campo[ubVs[0]][ubVs[1]].animal->energia)
        {
            Matriz::campo[ubVs[0]][ubVs[1]].animal=NULL;   
        }
        else
        {
            Matriz::campo[ubicacion[0]][ubicacion[1]].animal=NULL;
        }
    }
    else
    {
        cout<<"No se defiende territorio..."<<endl;
    }
    }
}