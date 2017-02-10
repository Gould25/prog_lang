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

/*****     Integer Function     *****/

bool integer(string lex){
  int state = 1;
  int i = 0;

  while ( i < lex.length()) {
    switch (state) {

      // Beginning state check for leading +/- digit
      case 1: if ((lex[i] == '+') || (lex[i] == '-') )
                state = 2; // check for an integer state
              else if (isdigit( lex[i]))
                state = 3; // integer accepting state
              else
                state = -1; // invalid state
                break;

      // Integer State if digit move to 3
      case 2: if ( ( isdigit(lex[i])) )
                state = 3; // integer check state
              else
                state = -1; // invalid state
              break;

      // Integer State if digit stay in 3
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

  // if state is correct and i = length return true
  if ( i == lex.length() && state == 3 )
    return true;
  else
    return false;

}// end integer function

/*****     Decimal Function     *****/////

bool decimal(string lex){
  int state = 1;
  int n = lex.length();
  int d_pos = lex.find('.');
  int i = d_pos + 1;
  string pre_d;
  string post_d;

  pre_d = lex.substr(0, d_pos); // create string from 0 to '.'

  // call int funct on pre_d if true check for digits following '.'
  if ( integer(pre_d) ){
    while (i < n){

      if (isdigit(lex[i])) // check for digits folowing '.'
        state = 2; // accepting state
      else
        return false; // invalid state
      i++;
    }// end while
  } // end if
  else
    state = -1;

  // return true if state = 2
  if (i == n && state == 2)
    return true;
  else
    return false;

}// end decimal function

/*****     Scientific     *****/

bool scifi(string lex) {
  int n = lex.length();
  int e_pos = lex.find('E');
  string pre_e;
  string post_e;

  pre_e = lex.substr(0, e_pos); // create string from 0 to E
  post_e = lex.substr(e_pos+1, n-4); // create string from E to end

  /* call decimal and integer functions on strings pre_e and post_e
    if both return true return true */
  if (decimal(pre_e) && integer(post_e))
    return true;
  else
    return false;

}// end scifi function

/*****     Hexidecimal Function     *****/

bool hex(string lex){
  int state = 1;
  int i = 0;

  while ( i < lex.length()) {
    switch (state) {

      // Beginning state check for leading A-F || digit
      case 1: if ( lex[i] == 'A' || lex[i] == 'B' || lex[i] == 'C' ||
                        lex[i] == 'D' || lex[i] == 'E' || lex[i] == 'F')
                state = 2; // hex check state
              else if (isdigit(lex[i]))
                state = 2; // hex check state
              else
                state = -1; // invalid state
                break;

      // Hex check state check for A-F || digit
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

  // if state is correct and i = length return true
  if ( i == lex.length() && state == 3 )
    return true;
  else
    return false;

}// end hex function

/*****     KeyWord Function     *****/

bool key(string lex){

  // check if lex is a keyword
  if (lex == "print" || lex == "while" || lex == "if" || lex == "else")
    return true;
  else
    return false;

}// end key function

/*****     Identifier Function     *****/

bool ident(string lex) {
  int state = 1;
  int i = 0;

  while (i<lex.length()) {
    switch (state) {

      // beginning state check for alpha character first
      case 1: if (isalpha(lex[i]))
                state = 2;
              else
                state = -1;
              break;

      // identifier accepting state if alpha || digit || '_' stay here
      case 2: if (isalpha(lex[i]) || isdigit(lex[i]) || lex[i] == '_')
                state = 2;
              else if (lex[i] == '.')
                state = 3;
              else
                state = -1;
              break;

      // multiple identifier state check for alpha character first
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

  // if state is correct and i = length return true
  if (i == lex.length() && state == 2)
    return true;
  else
    return false;

}// end ident function

/*****     Email Function     *****/

bool email(string lex) {
  int state = 1;
  int n = lex.length();
  int at_pos = lex.find('@');
  string suffix;
  string pre_at;
  string post_at;

  /* setting suffix to the last 4 positions, pre_at to the positions
      before @ sym and post_at to the positions between the @ symbol and
      the last 4 positions of the lex string if the string length is >= 7*/
  if (n >= 7) {
    suffix = lex.substr(n-4,n); // create string from end-4 to end
    pre_at = lex.substr(0, at_pos); // create string from 0 to @
    post_at = lex.substr(at_pos+1, n-4); // create string from @ to end-4
  }
  else
    suffix = "VOID";

  // check if sublex is a valid suffix
  if (suffix == ".com" || suffix == ".net" || suffix == ".edu")
    state = 1;
  else
    state = -1;

  // call ident fnct to check if strings pre_at and post_at are identifiers
  if (ident(pre_at) && ident(post_at))
    state = 2;
  else
    state = -1;

  // if state is correct return true
  if (state == 2)
    return true;
  else
    return false;

}// end email function
