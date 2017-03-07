/**
*@file Levenshtein.h
*@version 1.0
*@date 6/03/17
*@author Ericka Zúñiga Calvo, Leonardo Hernández
*@title Distancia entre texto   
*@brief Clase Levenshtein
*/
#ifndef LEVENSHTEIN_H
#define LEVENSHTEIN_H

#include "Trie.h"
#include "ListWithPointer.h"

#include <iostream>
#include <string>

using namespace std;

class Levenshtein {
public:
    /*! Objeto de tipo trie, donde se almacenan las palabras del archivo.*/
    Trie* a1;
    /*! Parámetro que indica la mayor distancia permitida entre palabras*/
    int maxCost;
    /*! Palabra a la cual se le quiere encontrar coincidencias con una distancia menor a maxCost dentro del archivo*/
    string word;
    /*! Arreglo de punteros en el cual se encuentran guardadas las palabras del archivo.*/
    ListWithPointer<string,Cell<string>*>* dictionary;
    
    /*! Constructor de la clase Levenshtein.
     \param maxCost mayor distancia permitida entre palabras
     * \param file archivo en el cual se van a buscar las coincidencias.
     * \param word palabra a la cual se le quiere encontrar coincidencias dentro del archivo. */
    Levenshtein(int maxCost,string file, string word);
    
    /*! 
     Este método crea una fila, que corresponde a la primera fila de la matriz = 0,1,2,.. hasta llegar al tamaño de la palabra buscada.
     Y llama al método searchRecursive, que toma como prevRow esta fila y como nodo a los hijos de la raiz del trie.
     \return results arreglo que contiene todas las coincidencias dentro del archivo.* 
     */
    ListWithPointer<string,Cell<string>*>* LevenshteinRow();
    
    /*! Da el valor minimo entre 3 enteros.
     \return valor minimo*/
    int min(int a, int b, int c);
    /*!Se encarga de recorrer el árbol, nodo por nodo, de manera que se va creando un arreglo por punteros
     que indica la distancia entre la palabra y el string obtenido en el nodo. 
     * De tal forma, si aún existe una posibilidad de que el o los nodos hijos de dicho nodo contengan una palabra
     *  que esté en el rango de la distancia permitida, necesita únicamente el arreglo de la string analizada previamente y un arreglo por punteros nuevo 
     * para obtener la distancia de la nueva string, en vez de crear una matriz entera por cada palabra nueva.
     \param node indica el nodo dentro del trie en el que se está buscando
     \param letter indica la letra que contiene dicho nodo.
     \param prevRow  análisis de distancia del string que contiene el nodo padre.
     \param result arreglo que contiene las coincidencias encontradas.*/
    void searchRecursive(TrieNode* node, char letter, ListWithPointer<int,Cell<int>*>* prevRow, ListWithPointer<string,Cell<string>*>* result);
    
    /*! Crea la matriz que indica la distancia entre la string s1 y la palabra buscada.
     \param s1 string a la cual se le va a sacar la distancia con respecto a word.
     * \return distancia entre las palabras.
     */
    int Levenshtein_alg(string s1);
    
    /*! Indica si la palabra cumple con el rango de caracteres necesarios, es decir, si la string que contiene a
     tiene un tamaño entre la cantidad de caracteres de la palabra + maxCost y la cantidad de caracteres de la palabra - maxCost.
     * \param s1, string por comparar.
     * \return true si si la cumple.
     * \return false de lo contrario. */
    bool inRange(TrieNode* a);
    
    /*!* Este metodo recorre los nodos del árbol cuyo root es el nodo a.
    * Es recursivo, pero solamente recorre los nodos que están en el rango para ser una coincidencia
    *de acuerdo con el metodo inRange()
    *Para los nodos que son EOW, si tienen una distancia de Levenshtein menor o igual a la tolerancia
    *(utilizando el metodo  Levenshtein_alg() ) se agregan a la lista listaCoincid.
     \param a nodo en el que se encuentra.
     \return arreglo que contiene las coincidencias dentro del archivo.*/
    ListWithPointer<string,Cell<string>*>* LevenshteinMatrix(TrieNode* a,ListWithPointer<string,Cell<string>*>* results);
    
    /*! Este metodo recorre todas las palabras guardadas en dictionary, les aplica el método Levenshtein_alg y
     si cumple con la condición de que la distancia sea menor o igual a maxCost, la guarda dentro del arreglo results.
     \return todas las coincidencias dentro del archivo*/
    ListWithPointer<string,Cell<string>*>* LevenshteinList();
  
    virtual ~Levenshtein();

};

#endif /* LEVENSHTEIN_H */

