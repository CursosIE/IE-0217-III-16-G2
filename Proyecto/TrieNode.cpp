#include "TrieNode.h"

TrieNode::TrieNode() {
    parent = nullptr;
    EOW=false;
    str = "";
    numChar = 0;
}

TrieNode::~TrieNode() {
 
}

