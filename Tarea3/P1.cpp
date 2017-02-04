#include<iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <time.h> 
#include <string>
#include <cstring>
#include <sstream>
int MAX_CHARS_PER_LINE=20;
int MAX_TOKENS_PER_LINE=20;
using namespace std;
//Metodo Binary search.
int BinarySearch(int* Arr, int TamArr, int Buscado){
	int L=0;
	int R= TamArr-1;
	int encontrado=0;
	int salida=0;


	while (salida==0){
	int m= (L+R)/2;
	if(Arr[m]<Buscado){
		L=m+1;	
	}
	if(Arr[m]>Buscado){
		R= m-1;	
	}

        if(Arr[m]==Buscado){
	encontrado=1;
	salida=1;
	}

	
	if(L>R && encontrado==0){
		salida=1;
	}
	}
	
	return encontrado;
}


int Cuenta(string s, const char Separadorr, int &TotalChars) {
    for (int i = 0; i < s.size(); i++)
        if (s[i] == Separadorr) TotalChars++;
    return 0;
}

void split(string Linea, char Separador, vector<string> &TempBuff, int &TotalVector) {
    TempBuff.resize(0);
    TotalVector = 0;
    int Nums = -1;
    int NumPos = -1;
    int ValorNum = 0;
    int TotalChars = 0;
    int TotalEspacios = Linea.length();
    string Valor;
    Cuenta(Linea, Separador, TotalChars);
    if (TotalChars != 0) {
        while (Nums < TotalChars) {
            Nums++;
            ValorNum = Linea.find(Separador, NumPos + 1);
            Valor = Linea.substr(NumPos + 1,ValorNum);
            Valor = Valor.substr(0, Valor.find_first_of(Separador));
            TempBuff.push_back(Valor);
            NumPos = ValorNum;
            TotalEspacios++;
        }
        TotalVector = TempBuff.size();
    }
    else {
      
        TotalVector = 0;
    }
}

void imprimir(int* arr,int num)
{
    for(int i=0;i<num;i++)
    {
        if(i==0)
        {
            cout<<"["<<arr[i]<<",";
        } else{
            if(i!=num-1)
            {
                cout<<arr[i]<<",";
            }
            else
            {
                cout<<arr[i]<<"]"<<endl;
            }
            
        }
    }
}

int* generarArreglo(string textfile){
    int* arr=NULL;
    int counter=0;
    ifstream file;
    file.open(textfile.c_str());
    if(!file.good())
    {
        cout<<"No es posible abrir el archivo :("<<endl;
    }
    else
    {
        while(!file.eof())
        {
            char buf[MAX_CHARS_PER_LINE];
            file.getline(buf,MAX_CHARS_PER_LINE);
            int n=0;
            const char* token[MAX_TOKENS_PER_LINE];
            token[0]=strtok(buf," ");
            if(token[0])
            {
                for(n=1;n<MAX_TOKENS_PER_LINE;n++)
                {
                    token[n]=strtok(0," ");
                    if(!token[n]) break;
                }
               
                if(counter==0)
                {
                    int numelementos;
                    stringstream elementos;
                    elementos<<token[0];
                    elementos >> numelementos;
                    arr= new int[numelementos+1];
                    arr[0]=numelementos;
                }
                if(counter==1)
                {
                    for(int i=0;i<MAX_TOKENS_PER_LINE;i++)
                    {
                        int num;
                        stringstream numstr;
                        numstr<<token[i];
                        numstr>>num;
                        arr[i+1]=num;
                        if(!token[i]) break;
                    }
                }
                
            }
            counter++;
        }
    }
    return arr;
}

void selectionSort(int* arr, int n)
{
    for(int i=0;i<n;i++)
    {
        int pos=i;
        int menor=arr[i];
        int temp=arr[i];
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<menor)
            {
                menor=arr[j];
                pos=j;
            }
        }
        if(arr[i]!=menor){
            arr[i]=menor;
            arr[pos]=temp;
        } 
    }
	imprimir(arr,n);
}



int main(int argc, char** argv){

 string metodo= (string)argv[1]; 
 //Si el metodo es BS entonces procedemos con Binary search
if(metodo=="BS"){
 	ifstream ficheroEntrada;
 	string valores;
 	string Buscado2= argv[2];
 	int Buscado= atoi(Buscado2.c_str());
 	ficheroEntrada.open (argv[3]);
 	getline(ficheroEntrada, valores);
 	ficheroEntrada.close();

 	//cout << "Frase leida: " << valores << endl;


    
    	int TotalVector2;
    	vector<string> TempBuff2(0);
    	split(valores, *" ",  TempBuff2, TotalVector2);

   	// cout << TotalVector2 << endl; // Devuelve el tamaño del vector: 4
    
    	int ArrValores[TotalVector2];

    	for (int i=0; i<TotalVector2; i++){
		string temporal= TempBuff2[i];
		ArrValores[i]= atoi(temporal.c_str());
		}




  	clock_t t_ini, t_fin;
  	double secs;

 	 t_ini = clock();
 
	  int a= BinarySearch(ArrValores,TotalVector2, Buscado);
      
  	t_fin = clock();

  	secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;

	 cout << "Se encontro: " << a << endl; 
 	 cout << "El tiempo de ejecucion fue :" << secs << endl; //en s

}
if(metodo=="SS"){
    int* arr = generarArreglo("arr.txt");
    int* arr2 = new int[arr[0]];
    for(int i=1;i<arr[0]+1;i++)
    {
        arr2[i-1]=arr[i];
    }

	clock_t t_ini, t_fin;
  	double secs;

 	 t_ini = clock();
 
		 selectionSort(arr2,arr[0]);
      
  	t_fin = clock();

  	secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;

 	 cout << "El tiempo de ejecucion fue :" << secs << endl; //en s



   

}

  return 0;
};
