#include <iostream>
#include "Polinomio.hpp"
using namespace std;


int main(int argc, char** argv)
{
//Creamos Primer Objeto Polinomio
double data0[2]= {2.0,1.0};
int Size0=2;

Polinomio* p0 = new Polinomio(data0, Size0);

//Creamos Segundo Objeto Polinomio
double data1[4]= {8.0,-4.0,2.0, 1.0};
int Size1=4;

Polinomio* p1 = new Polinomio(data1, Size1);

//A continuación, se inician las pruebas 
//Mostrar que los operadores sobrecargados
//Funcionan correctamente
cout <<"Primer Polinomio"<< endl; 
p0->Imprimir();

cout <<"Segundo Polinomio"<< endl; 
p1->Imprimir();

cout <<"//////////////////////////////////"<< endl; 
//SUMA:
Polinomio* c = new Polinomio(data1, Size1);
cout <<"Suma"<< endl;
*c =  *p1 + *p0 ;
c->Imprimir();

//RESTA
cout <<"Resta"<< endl;
*c =  *p1 - *p0 ;
c->Imprimir();

//MULTIPLICACION
cout <<"Multiplicacion"<< endl;
*c =  *p1 * *p0 ;
c->Imprimir();

//DIVISION
cout <<"Division"<< endl;
*c =  *p1 / *p0 ;
c->Imprimir();

delete p0;
delete p1;
delete c;


return 0;

};




