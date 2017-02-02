#ifndef ANIMAL_H
#define ANIMAL_H
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



using namespace std;
class Animal {
public:
    Animal();
    Animal(const Animal& orig);
    virtual ~Animal();
    /*Atributos*/
    int energia;
    string identificador;
    string sexo;
    string especie;
    int ubicacion[2];
    bool seReprodujo;
    bool seMovio;
    
    /*Metodos*/
    string getSex();
    virtual void operator!()=0;
    virtual void operator++(int)=0;
    virtual void operator~()=0;
    virtual void operator--(int)=0;
    virtual void machoAlfa()=0;
    int* buscar(string busq);
    int* getEspacio();
};

#endif /* ANIMAL_H */