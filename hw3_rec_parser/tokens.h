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
void print(string input, string output);

// function Name: is_integer(input)
// Purpose: to find if the string is an integer
// Postcondition: returns true if integer or false
bool is_integer(string input);

// function Name: is_decimal(input)
// Purpose: to find if the string is a decimal
// Postcondition: returns true if decimal or false
bool is_decimal(string input);

// function Name: is_string(input)
// Purpose: to find if the string is a "string"
// Postcondition: returns true if a string or false
bool is_string(string input);

// function Name: is_keyword(input)
// Purpose: to find if the string is a keyword
// Postcondition: returns true if a keyword or false
bool is_keyword(string input);

// function Name: identifier(input)
// Purpose: to find if the string is an identifier
// Postcondition: returns true if an identifier or false
bool is_identifier(string input);

#endif
