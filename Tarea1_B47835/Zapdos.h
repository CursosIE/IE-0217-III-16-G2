
#ifndef ZAPDOS_H
#define ZAPDOS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Pokemon.h"
#include "Electric.h"
#include "Flying.h"

/**
 * Esta clase modela el comportamiento y estadisticas propias de un pokemon de especie Zapdos por lo que provee metodos
 * para mostrar los diferentes datos propios del pokemon y para combatir contra otros pokemones. Al ser un pokemon de tipo
 * electrico y volador debe heredar el comportamiento que lo hace pertenecer a dichos grupos.
 * 
 * @author Ericka Zuñiga Calvo
 */
class Zapdos : public Electric, public Flying{
    
    public:
        
        std::string type;
        std::string strongVs;
        std::string weakVs;
        
        /**
         * Constructor de Zapdos.
         * <p>
         * Construye un nuevo Zapdos e inicializa los diferentes atributos que lo conforman y lo hacen unico.
         */
        Zapdos();
        
        /**
         * Destructor de Zapdos.
         */
        virtual ~Zapdos();
        
        /**
         * Este metodo es usado para atacar y el proposito es rebajarle puntos de vida a otro pokemon que se encuentra en batalla
         * con el actual Zapdos. El ataque posee ciertas caracteristicas que lo distinguen como su tasa de golpeo y poder.
         *
         * @param other Una referencia al otro pokemon que recibira el primer ataque de este Zapdos.
         */
        void atk1(Pokemon &other);
        
        /**
         * Este metodo es usado para atacar y el proposito es rebajarle puntos de vida a otro pokemon que se encuentra en batalla
         * con el actual Zapdos. El ataque posee ciertas caracteristicas que lo distinguen como su tasa de golpeo y poder.
         *
         * @param other Una referencia al otro pokemon que recibira el segundo ataque de este Zapdos.
         */
        void atk2(Pokemon &other);
        
        /**
         * Este metodo es usado para atacar y el proposito es rebajarle puntos de vida a otro pokemon que se encuentra en batalla
         * con el actual Zapdos. El ataque posee ciertas caracteristicas que lo distinguen como su tasa de golpeo y poder.
         *
         * @param other Una referencia al otro pokemon que recibira el tercer ataque de este Zapdos.
         */
        void atk3(Pokemon &other);
        
        /**
         * Este metodo es usado para atacar y el proposito es rebajarle puntos de vida a otro pokemon que se encuentra en batalla
         * con el actual Zapdos. El ataque posee ciertas caracteristicas que lo distinguen como su tasa de golpeo y poder.
         *
         * @param other Una referencia al otro pokemon que recibira el cuarto ataque de este Zapdos.
         */
        void atk4(Pokemon &other);
        
        /**
         * Metodo para obtener los grupos de tipos a los cuales pertenece un Zapdos.
         * 
         * @return Los tipos de los Zapdos.
         */
        std::vector<std::string> getTypes();
        
        /**
         * Metodo que se encarga de imprimir en terminal la información del Zapdos como individuo particular.
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

#endif /* ZAPDOS_H */

