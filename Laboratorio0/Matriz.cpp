#include "Matriz.h"
#include "Lobo.h"
#include "Oveja.h"
#include "Zorro.h"
#include "Raton.h"

/*Inicializacion de los atributos de la clase Matriz*/
int Matriz::numfilas = 0;
int Matriz::numcolumnas = 0;
Matriz::Elemento** Matriz::campo = NULL;

Matriz::Matriz(string text) {
    /*El constructor de la clase Matriz, se encarga de leer el archivo linea por linea
     *cada linea sera separada por el delimitador " ", y los tokens seran guardados en un arreglo 
     *hasta alcanzar el fin del archivo.*/
    int counter=0; /*El contador se utiliza para saber cual linea del archivo esta leyendo*/
    campo = NULL;
    ifstream file;
    file.open(text.c_str());
    if(!file.good())
    {
        cout<<"No es posible abrir el archivo..."<<endl;
    }
    else
    {
        while(!file.eof())
        {
            char buf[MAX_CHARS_PER_LINE];
            file.getline(buf,MAX_CHARS_PER_LINE);
            int n=0;
            const char* token[MAX_TOKENS_PER_LINE]={};
            token[0]=strtok(buf,DELIMITER);
            if(token[0])
            {
                for(n=1;n<MAX_TOKENS_PER_LINE;n++)
                {
                    token[n]=strtok(0,DELIMITER);
                    if(!token[n]) break;
                }
                if (counter == 0){
                    /*Se obtiene como string el valor del numero de filas de la matriz, este debe
                     *transformarse a entero*/
                    stringstream strValue;
                    strValue<<token[0];
                    strValue >> numfilas;
                }
                
                if (counter==1){
                    /*Se obtiene como string el valor del numero de columnas de la matriz, este debe
                     *transformarse a entero*/
                    stringstream strValue2;
                    strValue2<<token[0];
                    strValue2 >> numcolumnas;
                    
                    /*Se crea una matriz dináica de tipo Elemento, de tamaño numfilas x numcolumnas*/
                    campo=new Elemento*[numfilas];
                    for(int k=0;k<numfilas;k++)
                    {
                        campo[k]= new Elemento[numcolumnas];
                    }
                }
                
                else if(counter>1)
                {
                    /*Si counter es mayor a 1, quiere decir que se entro a la parte del archivo,
                     *donde se designa el tipo de animal y la energía de cada uno de los elementos
                     *de la matriz.
                     *Lo primeros dos valores de token, corresponden a la ubicacion dentro de la matriz.
                     *El tercero corresponde a la energía y el cuarto al identificador del animal.
                     */
                    int i;
                    int j;
                    stringstream posfila;
                    posfila<<token[0];
                    posfila>>i;
                    
                    stringstream poscolumna;
                    poscolumna<<token[1];
                    poscolumna>>j;
                    
                    stringstream strenergia;
                    strenergia<<token[2];
                    strenergia>>campo[i][j].energia;
                    
                    /*Segun el primer caracter del identificador, se crea el animal correspondiente.
                     *Es decir si es L, se crea un Lobo, y se inicializan algunos atributos correspondientes
                     *como la ubicacion y el identificador.*/
                    
                    if(token[3][0]=='L')
                    {
                        campo[i][j].animal = new Lobo;
                        campo[i][j].animal->identificador = token[3];
                        campo[i][j].animal->ubicacion[0]=i;
                        campo[i][j].animal->ubicacion[1]=j;
                        
                    } 
                    if(token[3][0]=='O')
                    {
                        campo[i][j].animal = new Oveja;
                        campo[i][j].animal->identificador = token[3];
                        campo[i][j].animal->ubicacion[0]=i;
                        campo[i][j].animal->ubicacion[1]=j;
                    }
                    if(token[3][0]=='Z')
                    {
                        campo[i][j].animal = new Zorro;
                        campo[i][j].animal->identificador = token[3];
                        campo[i][j].animal->ubicacion[0]=i;
                        campo[i][j].animal->ubicacion[1]=j;
                    }
                    if(token[3][0]=='R')
                    {
                        campo[i][j].animal = new Raton;
                        campo[i][j].animal->identificador = token[3];
                        campo[i][j].animal->ubicacion[0]=i;
                        campo[i][j].animal->ubicacion[1]=j;
                    }
                    if(token[3]=="--")
                    {
                        campo[i][j].animal = NULL;
                    }
                }      
                counter++;
            }
        }
    }
}

Matriz::~Matriz() {
    /*En el destructor de Matriz, se elimina el arreglo en 2D creado dinámicamente en el 
     * constructor de la clase Matriz.*/
    for (int i = 0; i < numfilas; ++i){
       delete [] campo[i];
    } delete [] campo;
}

void Matriz::imprimir(){
    /*Este metodo se encarga de imprimir, en forma matricial, el contenido de 
     * cada uno de los elementos del objeto Matriz de forma [Energia, Animal]*/
    for(int i=0;i<numfilas;i++)
    {
        for(int j=0;j<numcolumnas;j++)
        {
            if(campo[i][j].animal!=NULL){
                if(campo[i][j].energia!=100)
                {
                    
                    cout<<"| "<<campo[i][j].energia<<", "<<campo[i][j].animal->identificador;
                }else{
                    cout<<"|"<<campo[i][j].energia<<", "<<campo[i][j].animal->identificador;
                }
                if(j==numcolumnas-1)
                {
                    cout<<"|"<<endl;
                }
            }
            else
            {    
                if(campo[i][j].energia!=100)
                {
                    
                    cout<<"| "<<campo[i][j].energia<<", --";
                }else{
                    cout<<"|"<<campo[i][j].energia<<", --";
                }
                if(j==numcolumnas-1){
                    cout<<"|"<<endl;
                }
            }
        }
        
    }
    cout<<"----------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<endl;
}