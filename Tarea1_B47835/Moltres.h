
#ifndef MOLTRES_H
#define MOLTRES_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Pokemon.h"
#include "Fire.h"
#include "Flying.h"

/**
 * Esta clase modela el comportamiento y estadisticas propias de un pokemon de especie Moltres por lo que provee metodos
 * para mostrar los diferentes datos propios del pokemon y para combatir contra otros pokemones. Al ser un pokemon de tipo
 * fuego y volador debe heredar el comportamiento que lo hace pertenecer a dichos grupos.
 * 
 * @author Ericka Zuñiga Calvo
 */
class Moltres : public Fire, public Flying{
    
    public:
        std::string type;
        std::string strongVs;
        std::string weakVs;
        
        /**
         * Constructor de Moltres.
         * <p>
         * Construye un nuevo Moltres e inicializa los diferentes atributos que lo conforman y lo hacen unico.
         */
        Moltres();
        
        /**
         * Destructor de Moltres.
         */
        virtual ~Moltres();
        
        /**
         * Este metodo es usado para atacar y el proposito es rebajarle puntos de vida a otro pokemon que se encuentra en batalla
         * con el actual Moltres. El ataque posee ciertas caracteristicas que lo distinguen como su tasa de golpeo y poder.
         *
         * @param other Una referencia al otro pokemon que recibira el primer ataque de este Moltres.
         */
        void atk1(Pokemon &other);
        
        /**
         * Este metodo es usado para atacar y el proposito es rebajarle puntos de vida a otro pokemon que se encuentra en batalla
         * con el actual Moltres. El ataque posee ciertas caracteristicas que lo distinguen como su tasa de golpeo y poder.
         *
         * @param other Una referencia al otro pokemon que recibira el segundo ataque de este Moltres.
         */
        void atk2(Pokemon &other);
        
        /**
         * Este metodo es usado para atacar y el proposito es rebajarle puntos de vida a otro pokemon que se encuentra en batalla
         * con el actual Moltres. El ataque posee ciertas caracteristicas que lo distinguen como su tasa de golpeo y poder.
         *
         * @param other Una referencia al otro pokemon que recibira el tercer ataque de este Moltres.
         */
        void atk3(Pokemon &other);
        
        /**
         * Este metodo es usado para atacar y el proposito es rebajarle puntos de vida a otro pokemon que se encuentra en batalla
         * con el actual Moltres. El ataque posee ciertas caracteristicas que lo distinguen como su tasa de golpeo y poder.
         *
         * @param other Una referencia al otro pokemon que recibira el cuarto ataque de este Moltres.
         */
        void atk4(Pokemon &other);
        
        /**
         * Metodo que se encarga de imprimir en terminal la información del Moltres como individuo particular.
         */
        void printInf();
        
        /**
         * Metodo para obtener los grupos de tipos a los cuales pertenece un Moltres.
         * 
         * @return Los tipos de los Moltres.
         */
        std::vector<std::string> getTypes();
        
        /**
         * Metodo que se encarga de generar secuencias aleatorias alfanumerica de cierta longitud.
         * 
         * @param s Un puntero a la direccion donde se guardara el arreglo de tipo caracter resultante.
         * @param len La longitud que tendra la cadena de caracteres generada.
         */
        static void gen_random(char *s, const int len);
};

#endif /* MOLTRES_H */

