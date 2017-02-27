#include "Polinomio.hpp"

//Destructor
Polinomio::~Polinomio(){


}

//Constructor
//Recibe un int tamaño, que equivale al grado -1.
//Recibe un arreglo, que le pasa los coeficientes
Polinomio::Polinomio(double arr[], int Size){

    
    this->Size= Size;
    data= new double[Size];
    for(int i=0; i<Size; i++){
    	data[i]= arr[i];
	}
}


//Permite imprimir un polinomio.

void Polinomio::Imprimir(){

	for(int i=0; i<Size; i++){
			cout << data[i] << " ";
		}
			cout << endl;

}



//Se sobrecarga el operador = que más adelante es necesario
//Para hacer las pruebas
Polinomio& Polinomio::operator=(const Polinomio &rhs) {
     this->Size = rhs.Size;

	for(int i=0; i<rhs.Size; i++){
		    data[i]= rhs.data[i];
		}

    return *this;
}


//Se sobrecarga el operador +
Polinomio& Polinomio::operator+(const Polinomio &rhs) {
	//Se determina el tamaño del polinomio resultante
	//tomando en cuenta cual es más grande y asignando 
	//ese.
       int SizeRes=0;
       if (Size > rhs.Size){
		SizeRes= Size;
	}
	else{
		SizeRes= rhs.Size;
	}

	double dataRes[SizeRes];
	for (int c = 0; c < SizeRes; c++) {
            dataRes[c] = data[c] + rhs.data[c];
        }
	
	//Retornamos un polinomio, a la operación suma
    	Polinomio* p = new Polinomio(dataRes, SizeRes);  
    return *p;
}

//Sobrecargamos el operador resta. Muy similar a la suma. 
Polinomio& Polinomio::operator-(const Polinomio &rhs){
	int SizeRes=0;
       if (Size > rhs.Size){
		SizeRes= Size;
	}
	else{
		SizeRes= rhs.Size;
	}

	double dataRes[SizeRes];


	 if (Size >= rhs.Size){
			for (int c = 0; c < rhs.Size; c++) {
           		 dataRes[c] = data[c] - rhs.data[c];
        		}
			for (int c = rhs.Size; c < SizeRes; c++) {
           		 dataRes[c] = data[c];
        		}
	 }
	 else{
		        for (int c = 0; c < Size; c++) {
           		dataRes[c] = data[c] - rhs.data[c];
        		}
			for (int c = Size; c < SizeRes; c++) {
           		 dataRes[c] = -1 * rhs.data[c];
        		}
	 }
	//Retornamos un polinomio, a la operación resta
    	Polinomio* p = new Polinomio(dataRes, SizeRes);  
        return *p;
}

//Sobrecargamos el operador multiplicacion.
Polinomio& Polinomio::operator*(const Polinomio &rhs){
    int SizeRes=(Size + rhs.Size -1);

    double dataRes [Size + rhs.Size - 1]; 
	//LLenamos el arreglo dataRes con 0. Como valor inicial.
    for (int c = 0; c < Size + rhs.Size - 1; c++)
        dataRes[c] = 0;
	//Sumamos a dataRes los términos multiplicados que equivalen al grado
	//de la equiz asociada a esa posición. 
   for (int a = 0; a < Size; a++){
        for (int b = 0; b < rhs.Size; b++){
           dataRes[a+b] += data[a] * rhs.data[b];  
        }
    }

	//Retornamos un polinomio, a la operación multiplicacion
    	Polinomio* p = new Polinomio(dataRes, SizeRes);  
        return *p;
}

//Para sobrecargar el metodo division, utilizamos división sintética
//Cabe destacar que si el divisor no es un monomio, no es válido 
//Utilizar esta técnica.

//Además para esta técnica se omite el residuo.

Polinomio& Polinomio::operator/(const Polinomio &rhs){
int SizeRes= Size -1;

double dataRes [SizeRes]; 
//Se llena dataRes con 0.
for (int c = 0; c < SizeRes; c++)
	dataRes[c] = 0;
//Se verifica que el divisor ser un monomio
if (rhs.Size!= 2){
cout << "No es posible aplicar division sintetica" << endl;
}


else{
double coef= -1* rhs.data[0];


for (int c = 0; c < SizeRes; c++)
	if(c==0){
	//cout<< "data[SizeRes-c+1]"<<data[SizeRes-c+1]<< endl;
	dataRes[SizeRes-c-1] = data[SizeRes-c];
	
	}
	else{
dataRes[SizeRes-c-1] = data[SizeRes-c]+ (dataRes[SizeRes-c]*coef);
	}


}
//Retornamos un polinomio, a la operación division
Polinomio* p = new Polinomio(dataRes, SizeRes);  
return *p;

}






