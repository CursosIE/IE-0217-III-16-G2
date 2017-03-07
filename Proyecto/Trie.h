/**
*@file Trie.h
*@version 1.0
*@date 6/03/17
*@author Ericka Zúñiga Calvo, Leonardo Hernández
*@title Distancia entre texto   
*@brief Clase Trie
*/
#ifndef TRIE_H
#define TRIE_H

#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include "TrieNode.h"

const int CASE='a';
using namespace std;

class Trie {
public:
    Trie();
    virtual ~Trie();
    /*! Crea el trie a partir de un archivo.
     * Va leyendo línea por línea el archivo, y va insertando la palabra al trie.
     \param textFile archivo.*/
    void create(string textFile);
    
    /*! Inserta palabras en el trie. De manera que tiene un nodo currentNode que se iguala a la raíz (trieTree)
     *  y busca si currentNode tiene un nodo hijo en la posición de la primera letra de la palabra, si no la tiene, crea un trieNode,
     * de lo contrario currentNode pasa a ser el nodo hijo y se continua con la siguiente letra de la palabra.
     * \param word palabra a insertar. */
     void insert(char* word);
    /*! Busca si existe dentro del árbol la palabra word.
     * Tiene un nodo currentNode que inicia en el root del trie y se inicia con la primera letra de la palabra. 
     * Se ve si currentNode tiene un trieNode (hijo) en la posición de la letra a buscar de children. 
     * De si tenerlo, currentNode pasa a ser el nodo hijo y se continua con la siguiente letra de la palabra.
     * Si se alcanza la última letra de la palabra, se verifica si EOW en dicho nodo es true. Si esto ocurre la palabra existe, de lo contrario no existe.
     * 
     \param word palabra buscada
     \return nodo donde se ubica la palabra.*/
    TrieNode* search(char* word);
    
    /*! Raíz del árbol*/
    TrieNode* trieTree;
};

#endif /* TRIE_H */

