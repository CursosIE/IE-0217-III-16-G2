#include "Trie.h"


Trie::Trie() {
    trieTree=new TrieNode();
}


void Trie::create(string textFile)
{
    
    const int maxchars = 27;
    const char* const DELIMITER= " ";
    ifstream file;
    file.open(textFile.c_str());
    if(!file.good())
    {
        cout<<"No es posible abrir el archivo..."<<endl;
    }
    else
    {
        //cout<<"Creando arbol"<<endl;
        while(!file.eof())
        {
            char* word[1]={};
            char buf[maxchars];
            file.getline(buf,maxchars);
            int n=0;
            word[0]=strtok(buf,DELIMITER);
            //cout<<*word<<endl;
            if(*word != nullptr){
                insert(this->trieTree, *word);
            }
        }
    }
}    

void Trie::insert(TrieNode* trieTree, char* word)
{
    TrieNode* currentNode = trieTree;
    while(*word != '\0')
    {
        if(currentNode->children[*word-CASE]== nullptr)
        {
            currentNode->children[*word-CASE] = new TrieNode();
            currentNode->children[*word-CASE]->parent = currentNode;
        }
        
        currentNode = currentNode->children[*word-CASE];
        ++word;
    }
    currentNode->EOW = true;
    amount++;
}

TrieNode* Trie::search(TrieNode* trieTree, char* word)
{
    while(*word != '\0')
    {
        if(trieTree->children[*word-CASE] != nullptr)
        {
            trieTree = trieTree->children[*word-CASE];
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

