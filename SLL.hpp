#ifndef SLL_HPP_
#define SLL_HPP_
#include "SNode.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

class SLL {
    friend class WebTopic;
    SNode *first;
    SNode *last;
    SNode *p2; //points to the node in the list that is the last node with a
//    priority of 2. If you add another node with a priority of 2 to the list, it will be
//    added after this node
    //Note that you still only have one list
    int size;
public:
    SLL();
    ~SLL();
    void printSLL();
    //used for testing purposes only, and you’ve already written this…
    void printSLL(int p);
    //helper function to print specific priority
    void priorityInsert(string s, int p);
    //(8 pts)
    //This method creates a new node with s as the word and p as the priority and,
    //if the priority is 1, adds the new node to the beginning of the list, if it
    //is 3, adds the node to the end of the list, and if it’s 2, it will insert it
    //into the list right after pointer p2 (which is the last node with a priority
    //of 2. In essence, all the nodes with a priority of 1 are at the beginning
    //of the list, all the nodes with a priority of 2 are in the middle of the
    //list, and all the nodes with a priority of 3 are at the end of the list.
    void push(SNode *n);
    //(4 pts)
    // pushes n onto the end of the stack (remember to reset the last pointer)
    void addAtFront(SNode *n);
    //(5 pts)
    //adds n to the beginning of the list (remember to reset the first pointer)
    void addAtK(SNode *n, int k);
    //helper function to add a the kth position
};
#endif /* SLL_HPP_ */
