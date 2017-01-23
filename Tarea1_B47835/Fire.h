

#ifndef FIRE_H
#define FIRE_H

#include <iostream>
#include "Pokemon.h"

/**
 * Esta clase modela el comportamiento de un pokemon de tipo fuego por lo que provee metodos para mostrar las ventajas 
 * y desventajas de un pokemon perteneciente a dicho grupo. El hecho de ser de fuego es una caracteristica propia de los 
 * pokemones por lo que se hereda todo el comportamiento que hace a un objeto ser Pokemon.
 * 
 * @author Ericka Zuñiga Calvo
 */
class Fire : virtual public Pokemon{
    public:
        
        /**
         * Constructor de Fire.
         */
        Fire();
        
        /**
         * Destructor de Fire.
         */
        virtual ~Fire();
        
        /**
         * Metodo para obtener la cadena de caracteres que describe dicho tipo.
         * 
         * @return El tipo de esta clase.
         */
        static std::string getType();
        
        /**
         * Metodo para obtener las fortalezas de Fire contra el resto de tipos.
         * 
         * @return Una cadena de caracteres que detalla sobre que tipos se impone Fire.
         */
        static std::string getStrongVs();
        
        /**
         * Metodo para obtener las debilidades de Fire contra el resto de tipos.
         * 
         * @return Una cadena de caracteres que detalla que tipos debilitan Fire.
         */
        static std::string getWeakVs();
} ;

#endif /* FIRE_H */

