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
#include "grammar.h"
#include "tokens.h"

/*****     Factor Function     *****/

bool is_factor(string token){
  if ( is_integer(token) | is_decimal(token) |
        is_identifier(token) | is_string(token) )
      return true;
  return false;
} // end is_factor

/*****     Term Function     *****/

bool is_term(string token){
  if ( is_factor(token) ){
    cin >> token;
    if (token == "\n")
      return true;
    else if (is_mulop(token))
  }
      return true;
  return false;
} // end is_factor
