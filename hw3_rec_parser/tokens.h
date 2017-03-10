/*
Programmer: Jeff Gould ID#:12517284
Date: Mar 3, 2017
Instructor: DR. Morales
Section: 2A
File: tokens.h
Description: function def file for tokens.cpp
*/

#ifndef TOKENS_H
#define TOKENS_H

using namespace std;

// function Name: print(output)
// Purpose: Print either CORRECT or INVALID!
// Postcondition: CORRECT or INVALID! has been printed
void print(string token, string output);

// function Name: is_integer(token)
// Purpose: to find if the string is an integer
// Postcondition: returns true if integer or false
bool is_integer(string token);

// function Name: is_decimal(token)
// Purpose: to find if the string is a decimal
// Postcondition: returns true if decimal or false
bool is_decimal(string token);

// function Name: is_string(token)
// Purpose: to find if the string is a "string"
// Postcondition: returns true if a string or false
bool is_string(string token);

// function Name: is_keyword(token)
// Purpose: to find if the string is a keyword
// Postcondition: returns true if a keyword or false
bool is_keyword(string token);

// function Name: is_identifier(token)
// Purpose: to find if the string is an identifier
// Postcondition: returns true if an identifier or false
bool is_identifier(string token);

// function Name: is_relation(token)
// Purpose: to find if the string is an relation operator
// Postcondition: returns true if a relation operator or false
bool is_relation(string token);

// function Name: is_relation(token)
// Purpose: to find if the string is an add operator
// Postcondition: returns true if an add operator or false
bool is_addop(string token);

// function Name: is_mulop(token)
// Purpose: to find if the string is a multiplier operator
// Postcondition: returns true if an multilpier operator or false
bool is_mulop(string token);

#endif
