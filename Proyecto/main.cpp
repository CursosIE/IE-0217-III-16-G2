#include <cstdlib>
#include "TrieNode.h"
#include "Trie.h"
using namespace std;

int main(int argc, char** argv) {
    
    Trie* A1 = new Trie; 
    A1->insert(A1->trieTree,"abba");
    A1->insert(A1->trieTree,"avion");
    A1->insert(A1->trieTree,"caloria");
    A1->insert(A1->trieTree,"calor");
    A1->insert(A1->trieTree,"zorro");
    A1->search(A1->trieTree,"abba");
    A1->search(A1->trieTree,"carro");
    
    delete A1;
    return 0;
}

