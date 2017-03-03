#include "Trie.h"

 int numNodes=0;
 int numWords=0;
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
            char* word;
            char buf[maxchars];
            file.getline(buf,maxchars);
            int n=0;
            word=strtok(buf,DELIMITER);
            if(word!=NULL)
            {
                numWords++;
                //cout<<word<<endl;
                insert(this->trieTree,word);
            }
        }
    }
    cout<<"Read "<< numWords << " into " << numNodes<<" nodes"<<endl; 
}    

void Trie::insert(TrieNode* trieTree, char* word)
{
    TrieNode* currentNode = trieTree;
    while(*word != '\0')
    {
        if(currentNode->children[*word-CASE]== nullptr)
        {
            numNodes++;
            currentNode->children[*word-CASE] = new TrieNode();
            currentNode->children[*word-CASE]->parent = currentNode;
            if(currentNode->children[*word-CASE]->parent)
            {
                if(currentNode->children[*word-CASE]->parent->numChar==0)
                {
                    currentNode->children[*word-CASE]->str += *word;
                    currentNode->children[*word-CASE]->numChar = 1;
                }
                else
                {
                    currentNode->children[*word-CASE]->str = currentNode->children[*word-CASE]->parent->str;
                    currentNode->children[*word-CASE]->str += *word;
                    currentNode->children[*word-CASE]->numChar = currentNode->children[*word-CASE]->parent->numChar + 1;
                    
                }
            }
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
           /* if(trieTree->parent)
            {
                cout<<trieTree->str<<endl;
            }*/
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

