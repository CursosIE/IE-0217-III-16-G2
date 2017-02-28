#include "TrieNode.h"

TrieNode::TrieNode() {
    parent = nullptr;
    EOW=false;
}

void TrieNode::printArray()
{
    if(this->children[0]==nullptr)
    {
        cout<<"El arreglo esta vacio"<<endl;
    }
    else cout<<"Ni idea de que estoy haciendo"<<endl;
}

TrieNode::~TrieNode() {
 
}

