#include <iostream>
#include <time.h>
#include "Pokemon.h"
#include "Electric.h"
#include "Flying.h"
#include "Fire.h"
#include "Water.h"
#include "Zapdos.h"
#include "Moltres.h"
#include "Articuno.h"

int main(int argc, char** argv){
    srand (time(NULL));  
  
    Zapdos* p1 = new Zapdos();
    Moltres* p2 = new Moltres();
    Articuno* p3 = new Articuno();

    p1 ->printInf();
    p2 ->printInf();
    p3 ->printInf();

    p1 ->atk1(*p2);
    p2 ->atk2(*p3);
    p3 ->atk3(*p1);
    p1 ->atk4(*p3);
    p2 ->atk3(*p1);
    p3 ->atk2(*p2);

    p1 ->printInf();
    p2 ->printInf();
    p3 ->printInf();

    delete p1;
    delete p2;
    delete p3;

    return 0;
}
