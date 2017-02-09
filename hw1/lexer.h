/*
Programmer: Jeff Gould ID#:12517284
Date: Feb 4, 2017
Instructor: DR. Morales
Section: 1A
File: lexer.h
Description: function def file
*/

#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <string>

using namespace std;

// function Name: print(type, j)
// Purpose: Print lex string and corresponding type of string
// Postcondition: Lex and type has been printed
void print(string type, int j);

// function Name: integer(lex)
// Purpose: to find if string lex is an integer
// Postcondition: returns true if integer or false
bool integer(string lex);

// function Name: decimal(lex)
// Purpose: to find if string lex is a decimal
// Postcondition: returns true if decimal or false
bool decimal(string lex);

// function Name: hex(lex)
// Purpose: to find if string lex is a hexidecimal
// Postcondition: returns true if hexidecimal or false
bool hex(string lex);

// function Name: key(lex)
// Purpose: to find if string lex is a keyword
// Postcondition: returns true if a keyword or false
bool key(string lex);

// function Name: ident(lex)
// Purpose: to find if string lex is an identifier
// Postcondition: returns true if an identifier or false
bool ident(string lex);

// function Name: email(lex)
// Purpose: to find if string lex is an email
// Postcondition: returns true if an email or false
bool email(string lex);

#endif
