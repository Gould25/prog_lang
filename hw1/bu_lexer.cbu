/*
Programmer: Jeff Gould ID#:12517284
Date: Feb 4, 2017
Instructor: DR. Morales
Section: 1A
File: lexer.hpp
Description: function definitions file
*/

#include <iostream>
#include <string>
#include "lexer.h"

using namespace std;

void print(string type, int j){
  cout << j << ": " << type << endl;
  return;
}// end print function

void lexer(string lex, int j){
  int state = 1;
  int i = 0;

  // check for key words
  if (lex == "while" || lex == "else" || lex == "if" || lex == "print")
    print("Keyword!", j);
  else{
    while ( i < lex.length()) {
      switch (state) {

        /* Beginning state
          check for leading +/- digit or alpha */
        case 1: if ( (lex[i] == '+')||(lex[i] == '-')||( isdigit(lex[i])) )
                  state = 2; // integer state
                else if ( lex[i] == 'A' || lex[i] == 'B' || lex[i] == 'C' ||
                           lex[i] == 'D' || lex[i] == 'E' || lex[i] == 'F')
                  state = 3; // hex check state
                else
                  state = -1; // invalid state
                break;
        /* Integer State
          if digit stay here if . move to decimal check */
        case 2: if ( ( isdigit(lex[i])) )
                  state = 2; // integer state
                else if ( lex[i] == 'A' || lex[i] == 'B' || lex[i] == 'C' ||
                           lex[i] == 'D' || lex[i] == 'E' || lex[i] == 'F')
                  state = 3; // hex check state
                else if ( lex[i] == '.' )
                  state = 4; // decimal check state
                else
                  state = -1; // invalid state
                break;

        /* HEX or Identifier CHECK
            if a-f or digit staty here if h move to hex state
            or if g-z move to identifier state*/
        case 3: if ( ( isdigit(lex[i])) || lex[i] == 'A' || lex[i] == 'B' ||
                      lex[i] == 'C' || lex[i] == 'D' ||
                      lex[i] == 'E' || lex[i] == 'F')
                  state = 3; // integer state
                else if ( lex[i] == 'H' )
                  state = 5; // HEX final state
                else
                  state = -1; // invalid state
                break;

        /* decimal state
          if digit stay here */
        case 4: if ( ( isdigit(lex[i])) )
                  state = 4; // Decimal state
                else
                  state = -1; // invalid state
                break;

        default:
                i = lex.length();
                break;
      } // end switch

        i ++;
    } // end while

    if ( i == lex.length() && state == 2 )
      print("Integer.", j);
    else if ( i == lex.length() && state == 4 )
      print("Decimal.", j);
    else if ( i == lex.length() && state == 5 )
      print("Hexidecimal.", j);
    else
      print("INVALID!", j);
  }
  return;
}// end function
