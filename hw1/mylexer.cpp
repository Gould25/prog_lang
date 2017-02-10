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
  cout << num << endl;

  for (int j=1; j<=num; j++){

    cin >> lex; // read string

    if ( integer(lex) )
      print( "Integer.", j );
    else if ( decimal(lex) )
      print( "Decimal.", j );
    else if ( scifi(lex) )
      print( "Scientific.", j );
    else if ( hex(lex) )
      print( "Hexidecimal.", j );
    else if ( key(lex) )
      print( "Keyword.", j );
    else if ( ident(lex) )
      print( "Identifier.", j );
    else if ( email(lex) )
      print( "Email.", j );
    else
      print( "INVALID!", j );
  }//end for

  return 0;
}//end main
