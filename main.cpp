#include "SLL.hpp"
#include "SNode.hpp"
#include "WebTopic.hpp"
#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

int main() {

      

    WebTopic *x = new WebTopic("webpage.html"); //or another web page – I haven’t
    //tested it extensively, but it should work for any basic html page
    x->ReadFile();
    x->printPage();
    
      //    SNode* n1 = new SNode("apple",1);
    //    SNode* n2 = new SNode ("pear",1);
    //    SNode* n3 = new SNode ("banana",1);
    //    SNode* n4 = new SNode ("purple",2);
    //    SNode* n5 = new SNode ("green",2);
    //    SNode* n6 = new SNode ("yellow",2);
    //    SNode* n7 = new SNode ("dog",3);
    //    SNode* n8 = new SNode ("cat",3);
    //    SNode* n9 = new SNode ("fish",3);
    //    
    //    SLL* testPUSH = new SLL();
    //    testPUSH->push(n1);
    //    testPUSH->push(n4);
    //    testPUSH->push(n7);
    //    testPUSH->printSLL();
    //    
    //    SLL* testADDATFRONT = new SLL();
    //    testADDATFRONT->addAtFront(n1);
    //    testADDATFRONT->addAtFront(n2);
    //    testADDATFRONT->addAtFront(n9);
    //    testADDATFRONT->printSLL();
    //    
    //    SLL* testPRIORITYADD_1 = new SLL();
    //    //testPRIORITYADD_1->priorityInsert("green",2);
    //    //testPRIORITYADD_1->priorityInsert("giraffe",3);
    //    testPRIORITYADD_1->priorityInsert("plum",1);
    //    testPRIORITYADD_1->priorityInsert("blueberry",1);
    //    //testPRIORITYADD_1->priorityInsert("zebra",3);
    //    testPRIORITYADD_1->priorityInsert("yellow",2);
    //    testPRIORITYADD_1->printSLL();
    //    
    //    
    //    
    //
    
    return 0;

}