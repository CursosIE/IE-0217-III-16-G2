/**
*@file TrieNode.cpp
*@version 1.0
*@date 6/03/17
*@author Ericka Zúñiga Calvo, Leonardo Hernández
*@title Distancia entre texto   
*@brief Clase TrieNode
*/
#include "TrieNode.h"

TrieNode::TrieNode() {
    parent = nullptr;
    EOW=false;
    str = "";
    numChar = 0;
}

TrieNode::~TrieNode() {
 
}

