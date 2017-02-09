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

bool integer(string lex){
  int state = 1;
  int i = 0;

  while ( i < lex.length()) {
    switch (state) {
      /* Beginning state
        check for leading +/- digit  */
      case 1: if ((lex[i] == '+') || (lex[i] == '-') )
                state = 2; // check for an integer state
              else if (isdigit( lex[i]))
                state = 3; // integer accepting state
              else
                state = -1; // invalid state
                break;

      /* Integer State
        if digit move to 3  */
      case 2: if ( ( isdigit(lex[i])) )
                state = 3; // integer check state
              else
                state = -1; // invalid state
              break;

      /* Integer State
        if digit stay in 3  */
      case 3: if ( ( isdigit(lex[i])) )
                state = 3; // integer accept state
              else
                state = -1; // invalid state
              break;

      default:
              i = lex.length();
              break;
    } // end switch

        i ++;
  } // end while

  if ( i == lex.length() && state == 3 )
    return true;
  else
    return false;
}// end integer function

bool decimal(string lex){
  int state = 1;
  int i = 0;

  while ( i < lex.length()) {
    switch (state) {

      /* Beginning state
        check for leading +/- digit  */
      case 1: if ((lex[i] == '+') || (lex[i] == '-') )
                state = 2; // check for an integer state
              else if (isdigit( lex[i]))
                state = 3; // integer accepting state
              else
                state = -1; // invalid state
                break;

      /* Integer State
        if digit move to 3  */
      case 2: if ( ( isdigit(lex[i])) )
                state = 3; // integer check state
              else
                state = -1; // invalid state
              break;

      /* Integer > 0 State
        if digit stay in 3  */
      case 3: if ( ( isdigit(lex[i])) )
                state = 3; // integer accept state
              else if (lex[i] == '.')
                state = 4; // decimal accept state
              else
                state = -1; // invalid state
              break;


      /* Decimal accept State
          if digit stay here  */
      case 4: if ( ( isdigit(lex[i])) )
                state = 4; // decimal accept state
              else
                state = -1; // invalid state
              break;

      default:
              i = lex.length();
              break;
    } // end switch

        i ++;
  } // end while

  if ( i == lex.length() && state == 4 )
    return true;
  else
    return false;
}// end decimal function

bool hex(string lex){
  int state = 1;
  int i = 0;

  while ( i < lex.length()) {
    switch (state) {

      /* Beginning state
        check for leading A-F || digit  */
      case 1: if ( lex[i] == 'A' || lex[i] == 'B' || lex[i] == 'C' ||
                        lex[i] == 'D' || lex[i] == 'E' || lex[i] == 'F')
                state = 2; // hex check state
              else if (isdigit(lex[i]))
                state = 2; // hex check state
              else
                state = -1; // invalid state
                break;

      /* Hex check state
          check for A-F || digit  */
      case 2: if ( lex[i] == 'A' || lex[i] == 'B' || lex[i] == 'C' ||
                      lex[i] == 'D' || lex[i] == 'E' || lex[i] == 'F')
                state = 2; // hex check state
              else if (isdigit(lex[i]))
                state = 2; // hex check state
              else if (lex[i] == 'H')
                state = 3; // hex accepting state
              else
                state = -1; // invalid state
                break;

      default:
              i = lex.length();
              break;
    } // end switch

        i ++;
  } // end while

  if ( i == lex.length() && state == 3 )
    return true;
  else
    return false;
}// end hex function

bool key(string lex){
  if (lex == "print" || lex == "while" || lex == "if" || lex == "else")
    return true;
  else
    return false;
}// end key function

bool ident(string lex) {
  int state = 1;
  int i = 0;

  while (i<lex.length()) {
    switch (state) {

      /* beginning state
        check for alpha character first */
      case 1: if (isalpha(lex[i]))
                state = 2;
              else
                state = -1;
              break;

      /* identifier accepting state
        if alpha || digit || '_' stay here */
      case 2: if (isalpha(lex[i]) || isdigit(lex[i]) || lex[i] == '_')
                state = 2;
              else if (lex[i] == '.')
                state = 3;
              else
                state = -1;
              break;

      /* multiple identifier state
        check for alpha character first */
      case 3: if (isalpha(lex[i]))
                state = 2;
              else
                state = -1;
              break;

      default: i = lex.length();
              break;
    }// end switch
    i++;
  }// end while

  if (i == lex.length() && state == 2)
    return true;
  else
    return false;
}// end ident function

bool email(string lex) {
  int state = 1;
  int i = 0;
  int n = lex.length();
  int at_pos = lex.find('@');
  string sublex;
  string pre_at;
  string post_at;

  // setting sublex to last 4 position of lex if string length is > 5
  if (n > 8 ){
    sublex = lex.substr(n-4,n);
    pre_at = lex.substr(0, at_pos);
    post_at = lex.substr(at_pos+1, n-4);
  }
  else
    sublex = "VOID";

  // check if sublex is a valid suffix
  if (sublex == ".com" || sublex == ".net" || sublex == ".edu")
    state = 1;
  else
    state = -1;

  if (ident(pre_at) && ident(post_at))
    state = 2;
  else
    state = -1;
  if (state == 2)
    return true;
  else
    return false;
}// end email function
