

#ifndef ELECTRIC_H
#define ELECTRIC_H
#include <iostream>
#include "Pokemon.h"

/**
 * Esta clase modela el comportamiento de un pokemon de tipo electrico por lo que provee metodos para mostrar las ventajas 
 * y desventajas de un pokemon perteneciente a dicho grupo. El hecho de ser electrico es una caracteristica propia de los pokemones 
 * por lo que se hereda todo el comportamiento que hace a un objeto ser Pokemon.
 * 
 * @author Ericka Zuñiga Calvo
 */
class Electric : virtual public Pokemon{
    
    public:
        
        /**
         * Constructor de Electric.
         */
        Electric();
        
        /**
         * Destructor de Electric.
         */
        virtual ~Electric();
        
        /**
         * Metodo para obtener la cadena de caracteres que describe dicho tipo.
         * 
         * @return El tipo de esta clase.
         */
        static std::string getType();
        
        /**
         * Metodo para obtener las fortalezas de Electric contra el resto de tipos.
         * 
         * @return Una cadena de caracteres que detalla sobre que tipos se impone Electric .
         */
        static std::string getStrongVs();
        
        /**
         * Metodo para obtener las debilidades de Electric contra el resto de tipos.
         * 
         * @return Una cadena de caracteres que detalla que tipos debilitan Electric .
         */
        static std::string getWeakVs();
} ;

#endif /* ELECTRIC_H */

