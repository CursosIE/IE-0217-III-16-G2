#ifndef FLYING_H
#define FLYING_H
#include <iostream>
#include "Pokemon.h"

/**
 * Esta clase modela el comportamiento de un pokemon de tipo volador por lo que provee metodos para mostrar las ventajas 
 * y desventajas de un pokemon perteneciente a dicho grupo. El hecho de ser volador es una caracteristica propia de los pokemones 
 * por lo que se hereda todo el comportamiento que hace a un objeto ser Pokemon.
 * 
 * @author Ericka Zuñiga Calvo
 */
class Flying : virtual public Pokemon{
    
    public:
        
        /**
         * Constructor de Flying.
         */
        Flying();
        
        /**
         * Destructor de Flying.
         */
        virtual ~Flying();
        
        /**
         * Metodo para obtener la cadena de caracteres que describe dicho tipo.
         * 
         * @return El tipo de esta clase.
         */
        static std::string getType();
        
         /**
         * Metodo para obtener las fortalezas de Flying contra el resto de tipos.
         * 
         * @return Una cadena de caracteres que detalla sobre que tipos se impone Flying.
         */
        static std::string getStrongVs();
        
        /**
         * Metodo para obtener las debilidades de Flying contra el resto de tipos.
         * 
         * @return Una cadena de caracteres que detalla que tipos debilitan Flying.
         */
        static std::string getWeakVs();
} ;
#endif/*FLYING_H*/

