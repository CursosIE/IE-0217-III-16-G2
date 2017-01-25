#include <cstdlib>
#include "Polinomio.h"
using namespace std;

int main(int argc, char** argv) {

    //se crea el arreglo del coeficiente con menor grado al de mayor grado, en este caso p1, p2.
    // p1= x^4-8x^3+2x-16.
    // p2= x-8
    int array1[] = {-16,2,0,-8,1};
    int array2[] = {-8,1};

    //se crean dos polinomios, p1 y p2, pasando por argumento los arreglos anteriores.
    Polinomio* p1=new Polinomio(array1);
    Polinomio* p2=new Polinomio(array2);

    //Prueba de la sobrecarga del operador suma.
    Polinomio p3 = *p2+*p1;
    p3.result();
    //Prueba de la sobrecarga del operador resta.
    Polinomio p4 = *p2-*p1;
    p4.result();
    //Prueba de la sobrecarga del operador multiplicacion.
    Polinomio p5 = (*p1)*(*p2);
    p5.result();

    //Prueba de la sobrecarga del operador division, mediante el metodo de division sintetica.
    Polinomio p6 = (*p1)/(*p2);
    p6.result();
    delete p1;
    delete p2;
    return 0;
}
