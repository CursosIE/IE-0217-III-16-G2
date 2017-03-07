/**
*@file Trie.cpp
*@version 1.0
*@date 6/03/17
*@author Ericka Zúñiga Calvo, Leonardo Hernández
*@title Distancia entre texto   
*@brief Clase Trie
*/
#include "Trie.h"

 int numNodes=0;
 int numWords=0;
Trie::Trie() {
    trieTree=new TrieNode();
}


void Trie::create(string textFile)
{
    const int maxchars = 27; //2
    const char* const DELIMITER= " "; //2
    ifstream file; //1
    file.open(textFile.c_str()); //1
    if(!file.good())//1
    {
        cout<<"No es posible abrir el archivo..."<<endl;//1
    }
    else//1
    {
        //cout<<"Creando arbol"<<endl;
        while(!file.eof()) //N*(7+25M)
        {
            char* word; //1
            char buf[maxchars]; //1
            file.getline(buf,maxchars);//1
            word=strtok(buf,DELIMITER);//1
            if(word!=NULL)//1
            {
                numWords++;//1
                //cout<<word<<endl;
                insert(word);
            }
        }
    }
    cout<<"Read "<< numWords << " into " << numNodes<<" nodes"<<endl; //1
}    

void Trie::insert( char* word) //25M+4
{
    TrieNode* currentNode = trieTree; //1
    while(*word != '\0') //M
    {
        if(currentNode->children[*word-CASE]== nullptr)//2
        {
            numNodes++;//1
            currentNode->children[*word-CASE] = new TrieNode();//2
            currentNode->children[*word-CASE]->parent = currentNode;//2
            if(currentNode->children[*word-CASE]->parent)//1
            {
                if(currentNode->children[*word-CASE]->parent->numChar==0)//2
                {
                    currentNode->children[*word-CASE]->str += *word;//2
                    currentNode->children[*word-CASE]->numChar = 1;//2
                }
                else
                {
                    currentNode->children[*word-CASE]->str = currentNode->children[*word-CASE]->parent->str;//3
                    currentNode->children[*word-CASE]->str += *word;//3
                    currentNode->children[*word-CASE]->numChar = currentNode->children[*word-CASE]->parent->numChar + 1;//3
                }
            }
        }
        
        currentNode = currentNode->children[*word-CASE];//2
        ++word;//1
    }
    currentNode->EOW = true;
}


TrieNode* Trie::search(char* word)
{
    TrieNode* currentNode = trieTree;
    while(*word != '\0')
    {
        if(currentNode->children[*word-CASE] != nullptr)
        {
            currentNode = currentNode->children[*word-CASE];
            ++word;
        }
        
        else {
            cout<<"La palabra no fue encontrada"<<endl;
            return nullptr;
        }
    }
    
    if(trieTree->EOW != false)
    {
        cout<<"La palabra fue encontrada"<<endl;
        return trieTree;
    }
    else {
        cout<<"La palabra no fue encontrada"<<endl;
        return nullptr;
    }
}



Trie::~Trie() {
    
}

