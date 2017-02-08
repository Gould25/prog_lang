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

// function Name: print(lex, type)
// Purpose: Print lex string and corresponding type of string
// Postcondition: Lex and type has been printed
void print(string type, int j);

// function Name: lexer(lex)
// Purpose: to find what type of string lex is
// Postcondition: returns the type of string lex is
void lexer(string lex, int j);

#endif
