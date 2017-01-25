#ifndef POLINOMIO_H
#define POLINOMIO_H
#include <iostream>
using namespace std;

class Polinomio {
public:

    //Se crea un constructor de Polinomio, que reciba como argumento un arreglo estatico de tipo int.
    template<size_t X> Polinomio(int (&arr)[X]){
        grado = X-1;
        data = new int[grado+1];
        for (int i=0;i<X;i++)
        {
            data[i]=arr[i];
        }
    }
    //Se crea un constructor de Poliniomio, que recibe como
    //argumento un arreglo dinamico o estatico y el tamano de dicho arreglo.
    Polinomio(int arr[], int sizeArr);

    //Se crea el constructor por copia de la clase polinomio.
    Polinomio(const Polinomio& orig);

    //Este metodo es el destructor de la clase polinomio.
    virtual ~Polinomio();

    //Este metodo se encarga de imprimir el resultado de la operacion realizada.
    void result();

    //Los metodos siguientes, son la sobrecarga de los operadores +,-,*,/.
    //Para poder ser utilizados con objetos de la clase Polinomios.
    Polinomio& operator+(const Polinomio &other);
    Polinomio& operator-(const Polinomio &other);
    Polinomio& operator*(const Polinomio &other);
    Polinomio& operator/(const Polinomio &other);

    //Estos son los atributos de la clase Polinomio,
    int grado;
    int* data;

};

#endif /* POLINOMIO_H */
