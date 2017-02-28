#include "Trie.h"


Trie::Trie() {
    trieTree=new TrieNode();
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

