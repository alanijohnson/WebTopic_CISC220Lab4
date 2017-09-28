/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WebTopic.cpp
 * Author: Alani
 * 
 * Created on March 21, 2017, 5:21 PM
 */

#include "SLL.hpp"
#include "SNode.hpp"
#include "WebTopic.hpp"
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <cctype>
using namespace std;

/*WebTopic(string) - 1 arg constructor
 *                   sets the filename
 *                   creates the wordlist (singly linked list)
 *                   defaults the current priority to 3
 *
 */
WebTopic::WebTopic(string filename) {
    file = filename;
    wordlist = new SLL();
    currpriority = 3; //default priority; will be changed
}

/*getPriority(string) - determines the priority using the html tags
 *                      html tag priorities:
 *                          priority 1 (high):
 *                              title, h1, h2
 *                          priority 2:
 *                              h3-h6
 *                          priority 3 (low):
 *                              anything else
 * input: string - line containing html tag to be analyzed to set priority 
 * return: void
 */
void WebTopic::getPriority(string line) {
    // determine the current priority, based on the tag that starts the line
    //See the header file for more details
    //(5 pts)
    //The line is the tag, without the first <. This method uses the line to
    //determine the current priority as follows:
    //If the first 5 characters in the line match the word “title” (I used
    //line.compare for this), or the first 2 characters match either h2 or h2,
    //then the current priority is set to 1. If the first 2 characters are
    //anything between h3 and h6, then the priority is set to 2, and if it’s
    //anything else, it’s set to 3.


    if ((line.compare(0, 5, "title") == 0) || (line.compare(0, 2, "h1") == 0)
            || (line.compare(0, 2, "h2") == 0)) { //if the first characters match priority 1 tags
        currpriority = 1; //change priority to 1
    } else if ((line.compare(0, 2, "h3") == 0) || (line.compare(0, 2, "h4") == 0)
            || (line.compare(0, 2, "h5") == 0) || (line.compare(0, 2, "h6") == 0)) { //if the first characters match priority 2 tags
        currpriority = 2; //change priority 2
    } else { //otherwise make priority 3
        currpriority = 3;
    }
}

/*printPage() - prints the list of web page words with their priorities
 *        initializes first and last and p2 as NULL and sets size to 0
 *
 * input: none
 * return: void
 */
void WebTopic::printPage() {
    //Prints out the list of web page words and their priority. You can

    //prints priority words 1-3
    for (int i = 1; i <= 3; i++) {
        cout << "Priority " << i << ":" << endl;
        wordlist->printSLL(i); //uses printSLL(priority) as helper to print one priority at a time
        cout << endl; //leave space
    }
}

/*ReadFile() - read in the file
 *             call parseString() and getPriority()
 *
 * input: none
 * return: void
 */
void WebTopic::ReadFile() {

    ifstream infile(file.c_str(), ios::in); // open file
    string line = "";
    char c;
    while (infile.get(c)) { //get the characters in the html file
        if (c == '<') { //when encountering < check the existing line
            if (!line.empty()) { //make sure line isn't empty
                parseString(line);
                line = "";
            }
        } else if (c == '>') { //check priority of items between <>
            getPriority(line);
            line = "";
        } else { //add characters to the line
            line += c;
        }
    }
    cout << endl;
    infile.close(); //close file
}

/*stropSpace(string) - remove spaces at the beginning of the line
 *               will remove all the spaces (and non alpha) characters 
 *               from the beginning of the string 
 *               and return the remainder of the string
 * input: string - line from html webpage
 * return: string - line without spaces at the beginning
 */
string WebTopic::stripSpace(string s) {
    unsigned int i = 0;

    //iterates through the string removing spaces until an alpha character is reached
    while (i < s.length()) {
        if (!isalpha(s[i])) { //if non alpha character is encountered it is erased
            //modified from s.erase(i), s.erase(i,1) removes the character if
            //it is not an alpha character
            //s.erase(i) erases the rest of the string starting at i
            s.erase(i, 1);
        } else if (isalpha(s[i])) { //when an alpha character is reached, break loop
            break;
        }
        i++; //iterate
    }
    return s; //return string starting with an alpha character
}

/*parseString(string) - breaks up a line of characters into words
 *                      words were separated by spaces in html file
 *
 * input: string - line from html
 * return: void
 */
void WebTopic::parseString(string line) {
    //takes the line and breaks it down into words (separated by space), calls
    //stripSpace to get rid of anything not alphanumeric, and then inserts each
    //word into the list along with its priority
    //(9 pts)
    //takes a line of characters and breaks the line up into words by creating a
    //new string of only alphabetical characters: Note: I did this by first
    //breaking the string into individual words separated by spaces, and then used
    //the function stripSpace to remove anything that wasn’t an alphanumeric
    //character using the built in isalpha function.

    string s = stripSpace(line); //strip spaces from the beginning of the line
    string a = ""; //alpha string (single word)
    int i = 0; //position in string

    //iterate through the string
    //i continues to iterate adding alpha characters to a until a space is reached
    //at that point a is string
    //ensures a is an alpha string and then adds the word to wordlist using the current priority
    //reassigns s to the remaining characters after removing spaces at the beginning of the lline
    //loop begins again checking new string
    while (i < s.length()) {
        if (isalpha(s[i])) { //alpha characters from string added to a
            a += s[i];
        } else if (isblank(s[i])) { //blank reached
            if (isalphaStr(a)) { //make sure a is an alpha string and not an empty string, or any other incorrect string
                wordlist->priorityInsert(a, currpriority); //insert word into wordlist
            }
            //remove spaces from substring after i
            s = stripSpace(s.substr(i));

            //initialize a and i
            //i is set to -1 because it will be incremented by 1
            //will start over using new string
            a = "";
            i = -1;
        }
        i++; //increment for iteration
    }

    //add the last alpha string to wordlist after loop is complete
    //necessary if there isn't a blank after the last word in the line
    if (isalphaStr(a)) {
        wordlist->priorityInsert(a, currpriority);
    }
}

/*WebTopic(string) - determines whether or not a string consists of only alpha characters
 *                   string is alpha until proven false
 * input: string of characters
 * return: bool:
 *           true - string is of only alpha characters
 *           false  string contains non-alpha character(s)
 */
bool WebTopic::isalphaStr(string s) {
    int i = 0; //initialize increment variable
    if (s.length() == 0) { //if the string is empty, not alpha
        return false;
    }
    while (i < s.length()) { //iterate through string
        if (!isalpha(s[i])) { //return false if a non alpha character is reached
            return false;
        }
        i++; //increment iterator
    }
    return true; //passed conditions; return true
}




