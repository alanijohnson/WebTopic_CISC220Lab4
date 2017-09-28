/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WebTopic.hpp
 * Author: Alani
 *
 * Created on March 21, 2017, 5:21 PM
 */

#ifndef WEBTOPIC_HPP_
#define WEBTOPIC_HPP_
#include "SNode.hpp"
#include "SLL.hpp"
#include <stdlib.h>
using namespace std;

class WebTopic {
    int currpriority;
    //This priority changes as the web page is traversed based on the last tag
    //that has been read in
    SLL *wordlist;
    //the list of words ordered by priority
    string file;
    //The name of the web page file being read in
public:
    WebTopic(string file);
    //constructor
    void ReadFile();
    //reads in the web page, character by character, into a a line, setting the
    //current priority based on the latest tag read in. This method calls
    //getPriority when a tag has been read in, and it calls parseString when the
    //text between tags has been read in.
    void parseString(string line);
    //(9 pts)
    //takes a line of characters and breaks the line up into words by creating a
    //new string of only alphabetical characters: Note: I did this by first
    //breaking the string into individual words separated by spaces, and then used
    //the function stripSpace to remove anything that wasn’t an alphanumeric
    //character using the built in isalpha function.
    string stripSpace(string s);
    //Strips out any character that isn’t alphanumeric and returns the stripped
    //string
    void getPriority(string line);
    //(5 pts)
    //The line is the tag, without the first <. This method uses the line to
    //determine the current priority as follows:
    //If the first 5 characters in the line match the word “title” (I used
    //line.compare for this), or the first 2 characters match either h2 or h2,
    //then the current priority is set to 1. If the first 2 characters are
    //anything between h3 and h6, then the priority is set to 2, and if it’s
    //anything else, it’s set to 3.
    void printPage();
    // (4 pts)
    //prints out the list of words on the web page, ordered by their priority (and
    //listing each word’s priority
    bool isalphaStr(string s);
    //helper function to determine if string is alpha
};
#endif /* WEBTOPIC_HPP_ */


