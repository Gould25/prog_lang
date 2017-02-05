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
#include <regex>
#include <string.h>
#include "lexer.h"

using namespace std;

void print(string lex, string type, int i){
  cout << i << ": " << type << "\t\t : " << lex << endl;
  return;
}// end print function

void lexer(string lex, int i){

  string type;
  regex integer("(\\+|-)?[[:digit:]]+");
  regex decimal("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?");
  regex scifi("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?((e|E)((\\+|-)?)[[:digit:]]+)?");
  regex hex("([[:xdigit:]]+)(\\H|h)");
  regex identifier("[[:alpha:]]+((\\'_')?[[:alnum:]])");

  if (regex_match(lex, integer)){
    type = "Integer.";
    print(lex, type, i);
  }
  else if (regex_match(lex, decimal)){
    type = "Decimal.";
    print(lex, type, i);
  }
  else if (regex_match(lex, scifi)){
    type = "Scientific.";
    print(lex, type, i);
  }
  else if (regex_match(lex, hex)){
    type = "Hexidecimal.";
    print(lex, type, i);
  }
  else if ((lex == "while")||(lex == "if")||(lex == "else")||(lex == "print")){
    type = "Keyword.";
    print(lex, type, i);
  }
  else if (regex_match(lex, identifier)){
    type = "Identifier.";
    print(lex, type, i);
  }
  else {
    type = "INVALID!";
    print(lex, type, i);
  }
  return;
}
