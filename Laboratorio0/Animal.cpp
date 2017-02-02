#include "Animal.h"
#include "Matriz.h"

/*Constructor de la clase animal, inicializa todos los bools en false.*/
Animal::Animal() {
    seReprodujo=false;
    seMovio=false;
}

/*Constructor por copia de la clase animal*/
Animal::Animal(const Animal& orig) {
    this->identificador= orig.identificador;
    this->energia= orig.energia;
    this->especie= orig.especie;
    this->sexo = orig.sexo;
}

/*Destructor de la clase animal*/
Animal::~Animal() {
}

/*getSex, genera un numero aleatorio entre 0-10. De manera que si el numero es menor que 6 el
 *el animal sera macho y de lo contrario sera hembra.*/
string Animal::getSex(){

srand(time(NULL)); 
int aleatorio = rand() % 11;
string Sex; //Implementar funcion aleatoria

if(aleatorio<6){
	Sex="M";
	} 
else{
	Sex="H";
	}
//cout << "Sexo aleatorio: "<< Sex << endl; 
return Sex;
}

/*Este metodo tiene como parametro una string, que me dice lo que el metodo va a buscar alrededor
 *del animal que lo llama.*/
int* Animal::buscar(string busq)
{
    /*Se crea un arreglo dinamico, en donde se va a guardar la ubicacion en la que se encuentra 
     *el animal buscado, de lo contrario permanece nulo*/
    int* arr = NULL;
    for (int i= (ubicacion[0]>0 ? ubicacion[0]-1:0); 
            i<= (ubicacion[0]<Matriz::numfilas-1 ? ubicacion[0]+1:ubicacion[0]);i++)
    {
        for(int j= (ubicacion[1]>0 ? ubicacion[1]-1:0); 
                j<=(ubicacion[1]<Matriz::numcolumnas-1 ? ubicacion[1]+1:ubicacion[1]);j++)
        {
            if(i==ubicacion[0] && j==ubicacion[1]){ continue;}
            else{
                if(busq=="--")
                {
                    if(Matriz::campo[i][j].animal == NULL)
                    {
                        arr=new int[2];
                        arr[0]=i;
                        arr[1]=j;
                        i=ubicacion[0]+2;
                        j=ubicacion[1]+2;
                    }
                }
                else{
                    if(Matriz::campo[i][j].animal!=NULL){
                        if(Matriz::campo[i][j].animal->identificador[0]==busq[0])
                        {
                            if(!busq[1]){
                                arr=new int[2];
                                arr[0]=i;
                                arr[1]=j;
                                i=ubicacion[0]+2;
                                j=ubicacion[1]+2;
                            }
                            else if(Matriz::campo[i][j].animal->identificador[1]==busq[1])
                            {
                                arr=new int[2];
                                arr[0]=i;
                                arr[1]=j;
                                i=ubicacion[0]+2;
                                j=ubicacion[1]+2; 
                            }
                        }
                    }else {continue;}
                }
                
            }
        }
    }
    return arr;
}
/*getEspacio, es un metodo que se encarga de guardar todos los campos que se encuentran libres
 *de animales alrededor del animal que lo llama en un arreglo dinamico. 
 * y genera un numero aleatorio entre 0 y la cantidad de espacios libres y retorna su ubicacion. 
 * En el caso de que no existan, retorna un arreglo nulo.*/
int* Animal::getEspacio()
{
    int** arr = new int*[8];
    for(int i = 0; i < 8; ++i){
        arr[i] = new int[2];
    }
    
    int counter = 0;
    for (int i= (ubicacion[0]>0 ? ubicacion[0]-1:0); i<= (ubicacion[0]<Matriz::numfilas-1 ? ubicacion[0]+1:ubicacion[0]);i++)
    {
        for(int j= (ubicacion[1]>0 ? ubicacion[1]-1:0); j<=(ubicacion[1]<Matriz::numcolumnas-1 ? ubicacion[1]+1:ubicacion[1]);j++)
        {
            if(i==ubicacion[0] && j==ubicacion[1]){ continue;}
            else{
                    if(Matriz::campo[i][j].animal == NULL)
                    {
                        arr[counter][0]=i;
                        arr[counter][1]=j;
                        counter ++;
                    }
                    else{
                        continue;
                    }
                }
        }
    }
    if(counter==0)
    {
        int* arr2 = NULL;
        for(int i=0;i<8;i++){
            delete [] arr[i];
        } delete [] arr;
        return arr2;
    }
    
    else
    {
        srand(time(NULL)); 
        int aleatorio = rand() % counter;
        for(int i=0;i<8;i++){
            if(i!=aleatorio)
            {
                delete [] arr[i];
            }
        }
        return arr[aleatorio];
    }
}


