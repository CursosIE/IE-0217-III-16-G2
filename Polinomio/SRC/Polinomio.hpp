#ifndef POLINOMIO_HPP
#define POLINOMIO_HPP

#include <iostream>

using namespace std;

class Polinomio {
	public:
		
		//metodos
		Polinomio(double data[], int Size);
		virtual ~Polinomio();
		void Imprimir();

		//Atributos:
		int Size; 
		double* data;

	//Sobrecarga Operadores:
	Polinomio& operator=(const Polinomio &rhs);
        Polinomio& operator+(const Polinomio &rhs);
	Polinomio& operator-(const Polinomio &rhs);
	Polinomio& operator*(const Polinomio &rhs);
	Polinomio& operator/(const Polinomio &rhs);
     
	
};



#endif /* POLINOMIO_HPP */
