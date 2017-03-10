/*
Programmer: Jeff Gould ID#:12517284
Date: Mar 3, 2017
Instructor: DR. Morales
Section: 1A
File: tokens.cpp
Description: function file
*/

#include <iostream>
#include <string>
#include "tokens.h"

/*****     Print Function     *****/

void print(string token, string output){
  cout << token << "  " << output << endl;
  return;
}// end print function

/*****     Integer Function     *****/

bool is_integer(string token){
  int state = 1;
  int i = 0;

  while ( i < token.length()) {
    switch (state) {

      // Beginning state check for leading +/- digit
      case 1: if ((token[i] == '+') || (token[i] == '-') )
                state = 2; // check for an integer state
              else if (isdigit( token[i]))
                state = 3; // integer accepting state
              else
                state = -1; // invalid state
                break;

      // Integer State if digit move to 3
      case 2: if ( ( isdigit(token[i])) )
                state = 3; // integer check state
              else
                state = -1; // invalid state
              break;

      // Integer State if digit stay in 3
      case 3: if ( ( isdigit(token[i])) )
                state = 3; // integer accept state
              else
                state = -1; // invalid state
              break;

      default:
              i = token.length();
              break;
    } // end switch

        i ++;
  } // end while

  // if state is correct and i = length return true
  if ( i == token.length() && state == 3 )
    return true;
  else
    return false;

}// end is_integer function

/*****     Decimal Function     *****/////

bool is_decimal(string token){
  int state = 1;
  int n = token.length();
  int d_pos = token.find('.');
  int i = d_pos + 1;
  string pre_d;
  string post_d;

  pre_d = token.substr(0, d_pos); // create string from 0 to '.'

  // call int funct on pre_d if true check for digits following '.'
  if ( is_integer(pre_d) ){
    while (i < n){

      if (isdigit(token[i])) // check for digits folowing '.'
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

}// end is_decimal function

/*****     String Function     *****/

bool is_string(string token){
  int n = token.length();
  if (token[0] == '"' && token[n-1] == '"')
    //cout << token[n] << endl;
    return true;
  return false;
} // end is_string function

/*****     Keyword Function     *****/

bool is_keyword(string token){
  string keyword[25] = {":=", "+", "-", "*", "OR", "AND", "~", ",", "<", ">",
                        "/", "=", "#", "&", "!", "PRINT", "ELSE", "LOOP",
                        "POOL", "IF", "FI", "FUNC", "RET", "BEGIN", "END" };
  for (int i=0; i<25; i++){
    if (keyword[i] == token)
      return true;
  }
  return false;
}

/*****     Identifier Function     *****/

bool is_identifier(string token) {
  int state = 1;
  int i = 0;

  while (i<token.length()) {
    switch (state) {

      // beginning state check for alpha character first
      case 1: if (isalpha(token[i]))
                state = 2;
              else
                state = -1;
              break;

      // identifier accepting state if alpha || digit || '_' stay here
      case 2: if (isalpha(token[i]) || isdigit(token[i]) )
                state = 2;
              else if (token[i] == '.')
                state = 3;
              else
                state = -1;
              break;

      // multiple identifier state check for alpha character first
      case 3: if (isalpha(token[i]))
                state = 2;
              else
                state = -1;
              break;

      default: i = token.length();
              break;

    }// end switch

    i++;

  }// end while

  // if state is correct and i = length return true
  if (i == token.length() && state == 2 && !is_keyword(token))
    return true;
  else
    return false;

}// end is_identifier function

/*****     relation Function     *****/

bool is_relation(string token){
  string relation[4] = {"<", ">", "=", "#"};
  for (int i=0; i<4; i++){
    if (relation[i] == token)
      return true;
  }
  return false;
} // end is_relation

/*****     add operators Function     *****/

bool is_addop(string token){
  string addop[4] = {"+", "-", "OR", "&"};
  for (int i=0; i<4; i++){
    if (addop[i] == token)
      return true;
  }
  return false;
} // end is addop

/*****     multiply operators Function     *****/

bool is_mulop(string token){
  string mulop[3] = {"*", "/", "AND"};
  for (int i=0; i<3; i++){
    if (mulop[i] == token)
      return true;
  }
  return false;
} // end is_ mulop
