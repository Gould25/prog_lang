/*
Programmer: Jeff Gould ID#:12517284
Date: Feb 4, 2017
Instructor: DR. Morales
Section: 1A
File: mylexer.cpp
Description: HW1 C++ program encoding a lexical analyser
*/

#include <iostream>
#include <string>
#include <string.h>
#include "lexer.h"

using namespace std;

int main() {

  /*****     Declarations     *****/
  int num;       // # of lines to read
  string lex;    // string to run through lexograph

  /*****     Main Body     *****/

  cin >> num;

  for (int i=1; i<=num; i++){
    cin >> lex;
    //cout << "call fnct lexer on " << lex << endl;
    lexer(lex, i);
  }//end for

  return 0;
}//end main
