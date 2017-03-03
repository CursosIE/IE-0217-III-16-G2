#ifndef TRIENODE_H
#define TRIENODE_H
#include <iostream>

using namespace std;
const int ALPHABET_SIZE=26;

class TrieNode {
public:
    TrieNode* parent;
    bool EOW;
    TrieNode* children[ALPHABET_SIZE] = {};
    string str;
    int numChar;
    TrieNode();
    virtual ~TrieNode();
private:

};

#endif /* TRIENODE_H */

