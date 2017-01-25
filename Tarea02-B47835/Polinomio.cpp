#include "Polinomio.h"

Polinomio::Polinomio(int arr[], int sizeArr) {
    //El metodo recibe como atributo un arreglo, y el tamano de dicho arreglo.
    //Se declaran los atributos de la clase Polinomio.
    grado = sizeArr-1;
    data = new int[grado+1];
    for (int i=0;i<sizeArr;i++)
    {
        data[i]=arr[i];
    }
}


Polinomio::Polinomio(const Polinomio& orig) {
    //Recibe como atributo un objeto de la clase poliniomio.
    //Y retorna un Polinomio, igual al de la clase original.
    grado = orig.grado;
    data = new int[grado+1];
    for(int i=0;i<orig.grado+1;i++){
        data[i]=orig.data[i];
    }
}

Polinomio::~Polinomio() {
    //Destructor de la clase polinomio.
    //elimina el arreglo dinamico data.
    delete[] data;
}

void Polinomio::result(){
    //Imprime el contenido del Polinomio.
  for(int i=grado;i>0;i--){
      if (data[i-1] >= 0)
      {
          cout<<data[i]<<"x^"<<i<<"+";
      }
      else
      {
          cout<<data[i]<<"x^"<<i;
      }
  }
  cout<<data[0]<<endl;
}

Polinomio& Polinomio::operator+(const Polinomio &other)
{
    /*Inicialmente, compara el grado del primer polinomio, con el segundo polinomio.
     *Si son iguales, simplemente realiza la suma uno por uno de cada elemento de
     *los polinomios y el resultado lo guarda en un arreglo dinamico, de tamano
     *grado + 1. Posteriormente crea un objeto de tipo polinomio,
     *donde se pasa por referencia el arreglo temporal y el tamano.
     */
    if (grado == other.grado)
    {
        int* tempArray = new int[grado+1];

        for(int i=0; i<grado+1;i++)
        {
            tempArray[i]= data[i]+other.data[i];
        }

        Polinomio* result = new Polinomio(tempArray,grado+1);

        delete[] tempArray;
        return *result;
    }
    /* De lo contrario, se suman los elementos de cada Polinomio, hasta alcanzar el elemento que esta en la posicion
     * del polinomio de menor grado. Luego de la posicion menor grado a la posicion mayor grado, se copian los
     * elementos del polinomio de mayor grado.
     * Se crea un Polinomio, el cual tiene como parametro el arreglo temporal donde estan guardados los valores de la
     * operacion anterior y el tamaño de dicho arreglo.
     */
    else
    {
        int menorGrado;
        const Polinomio* mayor;
        if (other.grado > grado)
        {
            menorGrado = grado;
            mayor = &other;
        }
        else
        {
            menorGrado = other.grado;
            mayor = this;
        }
        int* tempArray = new int[mayor->grado+1];
            for(int i=0; i<menorGrado+1;i++)
            {
                tempArray[i]= data[i]+other.data[i];
            }
            for(int i=menorGrado+1;i<mayor->grado+1;i++)
            {
                tempArray[i]=mayor->data[i];
            }

            Polinomio* result = new Polinomio(tempArray,mayor->grado+1);

            delete[] tempArray;
            return *result;
    }
}

Polinomio& Polinomio::operator-(const Polinomio &other)
{
    //Ver sobrecarga del operador +.
    if (grado == other.grado)
    {
        int* tempArray = new int[grado+1];

        for(int i=0; i<grado+1;i++)
        {
            tempArray[i]= data[i]-other.data[i];
        }

        Polinomio* result = new Polinomio(tempArray,grado+1);

        delete[] tempArray;
        return *result;
    }
    /*Se crea un puntero, nombrado mayor que apunta al Polinomio con mayor grado.
    * Se compara el grado de mayor, y el grado de los polinomios recibidos para multiplicar por -1 los valores
      del polinomio de mayor grado, que se encuentran en las posiciones entre menorGrado y el grado de mayor.   */
    else
    {
        int menorGrado;
        const Polinomio* mayor;
        if (other.grado > grado)
        {
            menorGrado = grado;
            mayor = &other;
        }
        else
        {
            menorGrado = other.grado;
            mayor = this;
        }
        int* tempArray = new int[mayor->grado+1];
            for(int i=0; i<menorGrado+1;i++)
            {
                tempArray[i]= data[i]-other.data[i];
            }
            for(int i=menorGrado+1;i<mayor->grado+1;i++)
            {
                if(mayor->grado==grado)
                {
                    tempArray[i]=mayor->data[i];
                }
                else
                {
                    tempArray[i]=mayor->data[i]*(-1);
                }
            }

            Polinomio* result = new Polinomio(tempArray,mayor->grado+1);

            delete[] tempArray;
            return *result;
    }
}

Polinomio& Polinomio::operator*(const Polinomio &other)
{   /*
     * Para la sobrecarga del operador *, se crea un arreglo temporal tempArray, que multiplique los coeficientes
     * de cada uno de los valores guardados en el Polinomio, con los valores del otro Polinomio.
     * Guardando este valor en la posicion en tempArray de la suma de las posiciones de los elementos que se estan multiplicando.
     */

    int nuevoGrado = grado+other.grado;
    int* tempArray = new int[nuevoGrado+1] ();

        for(int i=0; i<grado+1;i++)
        {
            for (int j=0;j<other.grado+1;j++)
            {
                int temp = i+j;
                tempArray[temp]+= data[i]*other.data[j];
            }

        }

        Polinomio* result = new Polinomio(tempArray,nuevoGrado+1);

        delete[] tempArray;
        return *result;

}

 Polinomio& Polinomio::operator/(const Polinomio &other){
     /*La operacion división, se realiza mediante el metodo de division sintetica. El cual tiene como restricciones
      * que el divisor tenga grado 1, y coefieciente 1 en dicha posicion. Ademas que el dividendo tenga grado mayor que
      * uno.
      * Se revisa que las restricciones se cumplan mediante un condicional.
      */
     Polinomio* result = NULL;
     if(other.grado!=1||grado<1||other.data[1]!=1)
     {
         cout<<"No se puede realizar dicha division por el metodo de division sintetica."<<endl;
         result = new Polinomio(NULL,0);
     }
     else{
         int* tempArray = new int[grado-other.grado+1];
         int temp = data[grado];
         int div = other.data[0]*(-1);
         tempArray[grado-other.grado]=temp;
         for(int i=grado-1;i>0;i--){
             int temp2= temp*div;
             tempArray[i-1]=data[i]+temp2;
             temp=tempArray[i-1];

         }
         result = new Polinomio(tempArray,grado-other.grado+1);
         delete[] tempArray;
     }
     return *result;
 }
