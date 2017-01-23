
#ifndef POKEMON_H
#define POKEMON_H
#include<iostream>
#include <vector>

/**
 * Esta clase modela el comportamiento y propiedades propias de un Pokemon por lo que provee metodos para mostrar los
 * diferentes datos propios del pokemon y para combatir contra otros pokemones.
 *
 * @author Ericka Zuñiga Calvo
 */
class Pokemon {

    public:
      std::string name;
      std::string species;
      int HP;
      int ATK;
      int DEF;
      int sATK;
      int sDEF;
      int SPD;
      int EXP;
      std::string cry;

      /**
       * Constructor de Pokemon.
       * <p>
       * Construye un nuevo Pokemon e inicializa los diferentes atributos que lo conforman y lo hacen unico.
      */
        Pokemon();

        /**
         * Destructor de Pokemon.
         */
        virtual ~Pokemon();

        /**
         * Metodo que se encarga de imprimir en terminal la información del Pokemon como individuo particular.
         */
        void inf();

        /**
         * Metodo que se encarga de retornar el canto del Pokemon.
         */
        std::string doCry();

        /**
         * Estos metodos son usados para atacar y el proposito es rebajarle puntos de vida a otro pokemon que se encuentra en batalla
         * con el actual Pokemon. Son virtuales, para que sus clases hijos puedan utilizarlo y declararlo como se necesite.
         *
         * @param other Una referencia al otro pokemon que recibira el cuarto ataque de este Zapdos.
         */
        virtual void atk1(Pokemon &other)=0;
        virtual void atk2(Pokemon &other)=0;
        virtual void atk3(Pokemon &other)=0;
        virtual void atk4(Pokemon &other)=0;
        /**
        *Este metodo virtual es utilizado para obtener los tipos del pokemon, en forma de un vector.
        */
        virtual std::vector<std::string> getTypes()=0;

        /**
        *Este metodo se utiliza para obtener el Modificador, el cual es necesario para calcular el daño que genera el ataque.
        *@param stab : Si el ataque utilizado es del mismo tipo que el Pokemon que lo utiliza, stab=1.5. De lo contrario es 1.
        *@param type : Pueden ser valores como: 0.5,1.0,2.0,4.0.
        */
        double getModifier(double stab, double type);

        /**
        *Este metodo se utiliza para obtener el dano causado al Pokemon.
        @param stab:Si el ataque utilizado es del mismo tipo que el Pokemon que lo utiliza, stab=1.5. De lo contrario es 1.
        @param type: Pueden ser valores como: 0.5,1.0,2.0,4.0.
        @param pwr, atk, def: Son atributos del Pokemon.
        */
        int getDamage(int pwr,int atk, int def,double stab, double type);

        /**
        *Este metodo genera un numero aleatorio entre fMax y fMin.
        */
        static double fRand(double fMin, double fMax);

        /**
        Este metodo devuelve true, si el metodo es critico.
        De lo contrario devuelve false.
        */
        bool isCritHit(int speed);

        /**
        Este metodo devuelve true, si el ataque no fue exitoso.
        De lo contrario devuelve false.
        */
        bool hasMissed(int accuracy);
};

#endif /* POKEMON_H */
