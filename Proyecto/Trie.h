#ifndef TRIE_H
#define TRIE_H

#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include "TrieNode.h"

const int CASE='a';
using namespace std;

class Trie {
public:
    Trie();
    virtual ~Trie();
    void create(string textFile);
    void insert(TrieNode* trieTree, char* word);
    TrieNode* search(TrieNode* trieTree, char* word);
    void getWord(TrieNode* last);
    TrieNode* trieTree;
    int amount;

};

#endif /* TRIE_H */

