#include "Matriz.h"
#include "Animal.h"
#include "Lobo.h"
#include "Oveja.h"
#include "Zorro.h"
#include "Raton.h"

#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>

using namespace std;
class Juego  
{
public:
    Juego();
    virtual ~Juego();
    //Metodo que inicia el juego.
    void Jugar(int dias,string file);  
};

#endif /* JUEGO_H */



