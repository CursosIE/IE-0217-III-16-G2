/**
*@file main.cpp
*@version 1.0
*@date 6/03/17
*@author Ericka Zúñiga Calvo, Leonardo Hernández
*@title Distancia entre texto   
*@brief Clase main
*/

#include "TrieNode.h"
#include "Trie.h"
#include "Levenshtein.h"
#include <iostream>
#include <time.h>
using namespace std;

int main(int argc, char** argv) {
    
    string word = argv[1];
    string file = argv[2];
    int n;
    stringstream strInt;
    strInt<<argv[3];
    strInt>>n;
    
    clock_t t_init, t_fin;
    double secs;
    
    Levenshtein* a = new Levenshtein(n,file,word);
    ListWithPointer<string,Cell<string>*>* resultsRow;
    
    t_init=clock();
    resultsRow=a->LevenshteinRow();
    t_fin=clock();
    
    secs=(double)(t_fin-t_init)/CLOCKS_PER_SEC;
    cout<<"El tiempo de ejecucion del metodo por Trie fila fue: "<<secs<<endl;
    resultsRow->printList();
    
    ListWithPointer<string,Cell<string>*>* resultsMatrix = new ListWithPointer<string,Cell<string>*>();
    t_init=clock();
    a->LevenshteinMatrix(a->a1->trieTree,resultsMatrix);
    t_fin=clock();
    
    secs=(double)(t_fin-t_init)/CLOCKS_PER_SEC;
    cout<<"El tiempo de ejecucion del metodo por Trie Matrix fue: "<<secs<<endl;
    resultsMatrix->printList();
    
     ListWithPointer<string,Cell<string>*>* resultsList;
     t_init=clock();
     resultsList=a->LevenshteinList();
     t_fin=clock();
     secs=(double)(t_fin-t_init)/CLOCKS_PER_SEC;
     cout<<"El tiempo de ejecucion del metodo por Lista fue: "<<secs<<endl;
     resultsList->printList();
   
    delete a;
    return 0;
}

