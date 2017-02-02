
#ifndef MATRIZ_H
#define MATRIZ_H

/*Bibliotecas necesarias para leer un archivo*/
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

#include <iostream>
#include "Animal.h"

/*Variables globales*/
const int MAX_CHARS_PER_LINE=15;
const int MAX_TOKENS_PER_LINE=5;
const char* const DELIMITER= " ";

using namespace std;

class Matriz {
    /*La clase Matriz, tiene dentro de ella una clase denominada Elemento, la cual tiene dos atributos:
      1- Un puntero, que direcciona a algun animal.
      2- Un entero que corresponde a la energia en el campo correspondiente.*/
    class Elemento {
    public:
        Elemento(){}
        /*Pequeño destructor de la clase elemento*/
        virtual ~Elemento(){
            /*Se elimina el puntero animal*/
            delete animal;
        }
        /*Atributos*/
        int energia;
        Animal* animal;
    };

public:
    /*Constructor de la clase Matriz, 
     * recibe como parámetro el nombre del archivo que contiene la informacion del juego.*/
    Matriz(string text);
    /*Destructor de la clase Matriz*/
    virtual ~Matriz();
    /*Atributos estáticos, para ser llamados en las otras clases.*/
    static int numfilas;
    static int numcolumnas;
    static Elemento** campo;
    /*Metodos*/
    void imprimir();
};
#endif /* MATRIZ_H */
