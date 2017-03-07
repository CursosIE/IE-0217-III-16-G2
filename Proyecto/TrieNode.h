#ifndef TRIENODE_H
#define TRIENODE_H
#include <iostream>

using namespace std;
const int ALPHABET_SIZE=26;

class TrieNode {
public:
    /*! Nodo que indica el nodo del que se generó dicho nodo. */
    TrieNode* parent;
    /*! Indica si existe una palabra*/
    bool EOW;
    /*! Corresponde a un arreglo de 26 caracteres en donde se crearan los nodos hijos de ese nodo.*/
    TrieNode* children[ALPHABET_SIZE] = {};
    /*! Palabra que contiene el recorrido a dicho nodo.*/
    string str;
    /*! Número de caracteres de la palabra que contiene el recorrido a dicho nodo. */
    int numChar;
    
    /*! Constructor de la clase TrieNode*/
    TrieNode();
    /*! Destructor de la clase TrieNode*/
    virtual ~TrieNode();

};

#endif /* TRIENODE_H */

