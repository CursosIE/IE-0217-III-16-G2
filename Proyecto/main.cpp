#include <cstdlib>
#include "TrieNode.h"
#include "Trie.h"
#include <cstring>
using namespace std;

int main(int argc, char** argv) {
    
    Trie* a1 = new Trie; 
    a1->create("textFile.txt");
    string str ="address";
    char* c = const_cast<char *>(str.c_str());
    TrieNode* a = a1->search(a1->trieTree,c);
    
    delete a1;
    return 0;
}

