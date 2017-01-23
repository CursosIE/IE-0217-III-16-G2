

#ifndef WATER_H
#define WATER_H

#include <iostream>
#include "Pokemon.h"

/**
 * Esta clase modela el comportamiento de un pokemon de tipo agua por lo que provee metodos para mostrar las ventajas 
 * y desventajas de un pokemon perteneciente a dicho grupo. El hecho de ser de agua es una caracteristica propia de los pokemones 
 * por lo que se hereda todo el comportamiento que hace a un objeto ser Pokemon.
 * 
 * @author Ericka Zuñiga Calvo
 */
class Water : virtual public Pokemon{
    
    public:
        
        /**
         * Constructor de Water.
         */
        Water();
        
        /**
         * Destructor de Water.
         */
        virtual ~Water();
        
        /**
         * Metodo para obtener la cadena de caracteres que describe dicho tipo.
         * 
         * @return El tipo de esta clase.
         */
        static std::string getType();
        
        /**
         * Metodo para obtener las fortalezas de Water contra el resto de tipos.
         * 
         * @return Una cadena de caracteres que detalla sobre que tipos se impone Water.
         */
        static std::string getStrongVs();
        
        /**
         * Metodo para obtener las debilidades de Water contra el resto de tipos.
         * 
         * @return Una cadena de caracteres que detalla que tipos debilitan Water.
         */
        static std::string getWeakVs();
} ;

#endif /* WATER_H */

