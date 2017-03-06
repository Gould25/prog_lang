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

void print(string input, string output){
  cout << input << "  " << output << endl;
  return;
}// end print function

/*****     Integer Function     *****/

bool is_integer(string input){
  int state = 1;
  int i = 0;

  while ( i < input.length()) {
    switch (state) {

      // Beginning state check for leading +/- digit
      case 1: if ((input[i] == '+') || (input[i] == '-') )
                state = 2; // check for an integer state
              else if (isdigit( input[i]))
                state = 3; // integer accepting state
              else
                state = -1; // invalid state
                break;

      // Integer State if digit move to 3
      case 2: if ( ( isdigit(input[i])) )
                state = 3; // integer check state
              else
                state = -1; // invalid state
              break;

      // Integer State if digit stay in 3
      case 3: if ( ( isdigit(input[i])) )
                state = 3; // integer accept state
              else
                state = -1; // invalid state
              break;

      default:
              i = input.length();
              break;
    } // end switch

        i ++;
  } // end while

  // if state is correct and i = length return true
  if ( i == input.length() && state == 3 )
    return true;
  else
    return false;

}// end is_integer function

/*****     Decimal Function     *****/////

bool is_decimal(string input){
  int state = 1;
  int n = input.length();
  int d_pos = input.find('.');
  int i = d_pos + 1;
  string pre_d;
  string post_d;

  pre_d = input.substr(0, d_pos); // create string from 0 to '.'

  // call int funct on pre_d if true check for digits following '.'
  if ( is_integer(pre_d) ){
    while (i < n){

      if (isdigit(input[i])) // check for digits folowing '.'
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

bool is_string(string input){
  int n = input.length();
  if (input[0] == '"' && input[n-1] == '"')
    //cout << input[n] << endl;
    return true;
  return false;
} // end is_string function

/*****     Keyword Function     *****/

bool is_keyword(string input){
  string keyword[4] = {"LOOP", "POOL", "IF", "FI"};
  for (int i=0; i<4; i++){
    if (keyword[i] == input)
      return true;
  }
  return false;
}

/*****     Identifier Function     *****/
bool is_identifier(string input) {
  int state = 1;
  int i = 0;

  while (i<input.length()) {
    switch (state) {

      // beginning state check for alpha character first
      case 1: if (isalpha(input[i]))
                state = 2;
              else
                state = -1;
              break;

      // identifier accepting state if alpha || digit || '_' stay here
      case 2: if (isalpha(input[i]) || isdigit(input[i]) )
                state = 2;
              else if (input[i] == '.')
                state = 3;
              else
                state = -1;
              break;

      // multiple identifier state check for alpha character first
      case 3: if (isalpha(input[i]))
                state = 2;
              else
                state = -1;
              break;

      default: i = input.length();
              break;

    }// end switch

    i++;

  }// end while

  // if state is correct and i = length return true
  if (i == input.length() && state == 2)
    return true;
  else
    return false;

}// end is_identifier function
