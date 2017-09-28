
#include "SLL.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

/*SLL() - no arg constructor
 *        initializes first and last and p2 as NULL and sets size to 0
 *
 */
SLL::SLL() {
    first = NULL;
    last = NULL;
    p2 = NULL;
    size = 0;
}

/*~SLL() - destructor
 *         remove nodes in SLL
 */
SLL::~SLL() {
    SNode* node = first;
    SNode* tmp; //prevents memory leak; holds onto next node
    while (node != NULL) {
        tmp = node->next;
        node->next = NULL;
        //cout << "node " << node->data << " destroyed" << endl;
        delete node;
        node = tmp;
    }
    first = NULL;
    last = NULL;
}

/*printSLL() - prints the list
 *        
 * input: none
 * return: void
 */
void SLL::printSLL() {
    SNode *tmp = first; //create a temp variable set at the first node
    while (tmp != NULL) { //iterate till tmp equals NULL (no more nodes)
        tmp->printNode(); //print node
        cout << ", "; //separate node data with comma
        tmp = tmp->next; //iterate to next node
    }
    cout << endl; //flush buffer
}

/*printSLL(int) - prints the elements of a specific priority 
 *        
 * int: specified priority to pring
 * return: void
 */
void SLL::printSLL(int p) {
    SNode *tmp = first; //create a temp variable set at the first node

    while (tmp != NULL) { //iterate till tmp equals NULL (no more nodes)
        if (tmp->priority == p) { //check to make sure you are only printing words of the right priority
            tmp->printNode(); //print node
            cout << ", "; //separate node data with comma
        }
        tmp = tmp->next; //iterate to next node
    }
    cout << endl; //flush buffer
}

/*priorityInsert(string, int) - inserts the node into the proper location based on priority
 *                              priority 1 - at the beginning of the list
 *                              priority 2 - in the middle of the list
 *                              priority 3 - at the end of the list
 * input: string - the word
 *        int - the priority of the word
 * return: void
 */
void SLL::priorityInsert(string s, int p) {
    //(8 pts)
    //This method creates a new node with s as the word and p as the priority and,
    //if the priority is 1, adds the new node to the beginning of the list, if it
    //is 3, adds the node to the end of the list, and if it’s 2, it will insert it
    //into the list right after pointer p2 (which is the last node with a priority
    //of 2. In essence, all the nodes with a priority of 1 are at the beginning
    //of the list, all the nodes with a priority of 2 are in the middle of the
    //list, and all the nodes with a priority of 3 are at the end of the list.

    SNode *n = new SNode(s, p); //create the node

    if ((size == 0) || (p == 1)) { //no elements in the list or priority is 1: node gets added to front
        addAtFront(n);
        if (n->priority == 2) { //if the priority is 2, need to set p2
            p2 = n;
        }
    } else if (p == 2) { //node's priority is 2 and there are elements in the list
        if (p2 == NULL) { //there aren't any priority 2 items in the list
            if (last->priority == 1) { //list only has priority 1 items can be added at the end of the list
                push(n);
                p2 = n;
            } else { //priority 3 & 1 exists
                SNode* tmp = first;
                for (int i = 1; i < size; i++) { //iterate to the last p1 node
                    if (tmp->next->priority != 3) {
                        tmp = tmp->next;
                    } else {
                        break; //exits the for loop
                    }
                }

                //insert the new node after the last priority 1 element
                n->next = tmp->next;
                tmp->next = n;
                p2 = n; //set p2 as the new node
                size++; //increase the size
            }
        } else { //priority 2 items already exist
            if (p2->next == NULL) { //p2 is the last item in the list
                push(n); //add node to the end of the list
            } else { //p2 isn't the last element in the list

                //add new node after p2
                n->next = p2->next;
                p2->next = n;
                p2 = n;
                size++;
            }
        }
    } else if (p == 3) { //priority is 3
        push(n); //add to end of list
    }
}

/*push(SNode) - adds new node to the end of the list
 * input: SNode - node to be added
 * return: void
 */
void SLL::push(SNode* n) {
    //(4 pts)
    // pushes n onto the end of the stack (remember to reset the last pointer)

    if (size == 0) { //check to see if list is empty
        //list is empty; node is the first and last in the list; list size is 1
        first = n;
        last = n;
        size = 1;
    } else { //list has elements; last 
        last->next = n; //point last node to n
        last = n; //make n the new last
        size++; //increment size
    }
}

/*addAtFront(SNode) - adds new node to the front of the list
 * input: SNode - node to be added
 * return: void
 */
void SLL::addAtFront(SNode* n) {
    //(5 pts)
    //adds n to the beginning of the list (remember to reset the first pointer)

    if (size == 0) { //no elements in the list
        //the new node is the first and last node
        first = n;
        last = n;
        size++; //increment the size by 1
    } else { //elements exist in the list
        n->next = first; //point n to the first item of the list
        first = n; //update first to the new node
        size++; //increment size by 1
    }

}

/*addAtK(SNode, int k) - adds new node to position k
 * input: SNode - node to be added
 *        int - position to add the node in the list
 * return: void
 */
void SLL::addAtK(SNode* n, int k) {
    if (k == 0) { //k = 0 add to the beginning
        addAtFront(n);
    } else if (k == size) { //k is last index added to the end
        push(n);
    } else if (k < size) { //ensures k is less than size
        SNode* tmp = first; //initialize tmp as the first node in the list
        for (int i = 1; i < k; i++) { //iterate to node at k-1
            tmp = tmp->next;
        }

        //insert node
        n->next = tmp->next;
        tmp->next = n;
        size++;
    }
}





