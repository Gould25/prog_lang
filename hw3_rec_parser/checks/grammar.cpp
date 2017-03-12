/*
Programmer: Jeff Gould ID#:12517284
Date: Mar 3, 2017
Instructor: DR. Morales
Section: 1A
File: grammar.cpp
Description: function file
*/

#include <iostream>
#include <string>
#include <sstream>
#include "grammar.h"
#include "tokens.h"
#include "global.h"

/*****     Factor Function     *****/

bool is_factor(string token){
  if ( is_integer(token) | is_decimal(token) |
        is_identifier(token) | is_string(token) )
      return true;
  return false;
} // end is_factor

/*****     Term Function     *****/

bool is_term(string token){
  int state = 0;
  if ( is_factor(token) ){
    get_token();
    if (is_mulop(token)){
      get_token();
      is_factor(token);
    }
    else if (token == "!"){
      state = 1;
    }
    else
      return false;
  } // eif factor*/
  if (state == 1)
    return true;
  return false;
} // end is_term
