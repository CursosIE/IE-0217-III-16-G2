Universidad de Costa Rica
Escuela de Ingeniería Eléctrica
Estructuras Abstractas de Datos y Algoritmos.
Prof: Ricardo Román
Laboratorio 0 : Juego de Ecología en C++.
Estudiantes:
  Ericka Zúñiga Calvo - B47835
  Leonardo Hernández Chacón - B43262

Este archivo contiene la implementación en C++, de un juego que simula
la interacción de cuatro especies de animales entre ellos y con su entorno
en un lapso determinado de días. Estos animales cumplen con comportamientos
básicos: movilizarse, comer, reproducirse y morir.

El programa recibe como parámetros dos valores definidos por el usuario:
1-La cantidad de días de la prueba.
2-Un archivo donde se define el tamaño del campo de juego(Matriz), el animal y
la energía que estarán en cada celda de la matriz.

Ejemplo de archivo:

3                     //Número de Columnas
3                     //Número de Filas
0 0 100 LM            // En la posición 0,0 de la matriz, se tendrá una energía de 100e y un Lobo Macho.

El resto de animales disponibles son: Ovejas, Ratones y Zorros.
El identificador que es el que se solicita en el archivo se escribe con la inicial del animal y la inicial del sexo.

Para correr el archivo:
  1- Poner en DAYS, los días de prueba.
  2- Poner en FILE, el nombre del archivo.
  3- make
  4- make run.
