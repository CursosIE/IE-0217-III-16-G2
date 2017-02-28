#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include "TrieNode.h"

const int CASE='a';
using namespace std;

class Trie {
public:
    Trie();
    virtual ~Trie();
    void insert(TrieNode* trieTree, char* word);
    TrieNode* search(TrieNode* trieTree, char* word);
    TrieNode* trieTree;
    int amount;

};

#endif /* TRIE_H */

