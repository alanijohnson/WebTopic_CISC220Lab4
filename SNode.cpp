#include "SNode.hpp"
#include <stdlib.h>
#include <iostream>


using namespace std;

SNode::SNode(string word, int p) {
    this->word = word;
    this->priority = p;
    next = NULL;

}

SNode::~SNode() {
}

void SNode::printNode() {
    cout << word << ":" << priority;
}