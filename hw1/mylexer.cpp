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
#include "lexer.h"

using namespace std;

int main() {

  /*****     Declarations     *****/
  int num;       // # of lines to read
  string lex;    // string to run through lexograph

  /*****     Main Body     *****/

  cin >> num;

  for (int j=1; j<=num; j++){

    cin >> lex; // read string

    if ( integer(lex) )
      print("Integer.", j);
    else if ( decimal(lex))
      print("DECIMAL.", j);
    else if ( hex(lex))
      print("HEXIDECIMAL.", j);
    else if ( key(lex))
      print("KEYWORD.", j);
    else if ( ident(lex))
      print("IDENTIFIER.", j);
    else if ( email(lex))
      print("EMAIL.", j);
    else
      print("INVALID!", j);
  }//end for

  return 0;
}//end main
