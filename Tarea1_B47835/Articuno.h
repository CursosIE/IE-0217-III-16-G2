
#ifndef ARTICUNO_H
#define ARTICUNO_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Pokemon.h"
#include "Water.h"
#include "Flying.h"

/**
 * Esta clase modela el comportamiento y estadisticas propias de un pokemon de especie Articuno por lo que provee metodos
 * para mostrar los diferentes datos propios del pokemon y para combatir contra otros pokemones. Al ser un pokemon de tipo
 * agua y volador debe heredar el comportamiento que lo hace pertenecer a dichos grupos.
 * 
 * @author Ericka Zuñiga Calvo
 */
class Articuno : public Water, public Flying{
    
    public:
        std::string type;
        std::string strongVs;
        std::string weakVs;
        
        /**
         * Constructor de Articuno.
         * <p>
         * Construye un nuevo Articuno e inicializa los diferentes atributos que lo conforman y lo hacen unico.
         */
        Articuno();
        
        /**
         * Destructor de Articuno.
         */
        virtual ~Articuno();
        
        /**
         * Este metodo es usado para atacar y el proposito es rebajarle puntos de vida a otro pokemon que se encuentra en batalla
         * con el actual Articuno. El ataque posee ciertas caracteristicas que lo distinguen como su tasa de golpeo y poder.
         *
         * @param other Una referencia al otro pokemon que recibira el primer ataque de este Articuno.
         */
        void atk1(Pokemon &other);
        
        /**
         * Este metodo es usado para atacar y el proposito es rebajarle puntos de vida a otro pokemon que se encuentra en batalla
         * con el actual Articuno. El ataque posee ciertas caracteristicas que lo distinguen como su tasa de golpeo y poder.
         *
         * @param other Una referencia al otro pokemon que recibira el segundo ataque de este Articuno.
         */
        void atk2(Pokemon &other);
        
        /**
         * Este metodo es usado para atacar y el proposito es rebajarle puntos de vida a otro pokemon que se encuentra en batalla
         * con el actual Articuno. El ataque posee ciertas caracteristicas que lo distinguen como su tasa de golpeo y poder.
         *
         * @param other Una referencia al otro pokemon que recibira el tercer ataque de este Articuno.
         */
        void atk3(Pokemon &other);
        
        /**
         * Este metodo es usado para atacar y el proposito es rebajarle puntos de vida a otro pokemon que se encuentra en batalla
         * con el actual Articuno. El ataque posee ciertas caracteristicas que lo distinguen como su tasa de golpeo y poder.
         *
         * @param other Una referencia al otro pokemon que recibira el cuarto ataque de este Articuno.
         */
        void atk4(Pokemon &other);
        
        /**
         * Metodo para obtener los grupos de tipos a los cuales pertenece un Articuno.
         * 
         * @return Los tipos de los Articuno.
         */
        std::vector<std::string> getTypes();
        
        /**
         * Metodo que se encarga de imprimir en terminal la información del Articuno como individuo particular.
         */
        void printInf();
        
        /**
         * Metodo que se encarga de generar secuencias aleatorias alfanumerica de cierta longitud.
         * 
         * @param s Un puntero a la direccion donde se guardara el arreglo de tipo caracter resultante.
         * @param len La longitud que tendra la cadena de caracteres generada.
         */
        static void gen_random(char *s, const int len);
};

#endif /* ARTICUNO_H */

