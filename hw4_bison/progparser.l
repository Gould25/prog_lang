/*
Programmer: Jeff Gould ID#:12517284
Date: April 3, 2017
Instructor: DR. Morales
Section: 1B
File: progparser.l
Description: lex file

/* -- PREAMBLE  ------------------------------------------ */
%{
#include <iostream>
#include <iomanip>
#include "progparser.tab.h"      // file generated by Bison
using namespace std;

int line_num = 1;      // to keep line numbers

// Function prototype
void writeToken(const char* toktype);

%}

     /* -- OPTIONS and DEFINITIONS ----------------------- */
%option noyywrap

WHITE      [ \t]
DIGIT      [0-9]
ALPHA      [a-zA-Z]
ALPHANUM   [a-zA-Z0-9]

%%   /* -- REGULAR EXPRESSIONS ---------------------------- */

{WHITE}    ;                /* eat white space */
\n         { line_num++; }  /* count line numbers */

 /* Keyword tokens */
"!"        { writeToken("K_BANG"); return K_BANG; }
":="       { writeToken("K_ASSIGN"); return K_ASSIGN; }
"("        { writeToken("K_LPAREN"); return K_LPAREN; }
")"        { writeToken("K_RPAREN"); return K_RPAREN; }
"PRINT"    { writeToken("K_PRINT"); return K_PRINT; }
"~"        { writeToken("K_NEG"); return K_NEG; }
"RET"      { writeToken("K_RET"); return K_RET; }
"IF"       { writeToken("K_IF"); return K_IF; }
"FI"       { writeToken("K_FI"); return K_FI; }
"ELSE"     { writeToken("K_ELSE"); return K_ELSE; }
"LOOP"     { writeToken("K_LOOP"); return K_LOOP; }
"POOL"     { writeToken("K_POOL"); return K_POOL; }
"FUNC"     { writeToken("K_FUNC"); return K_FUNC; }
"BEGIN"    { writeToken("K_BEGIN"); return K_BEGIN; }
"END."     { writeToken("K_END"); return K_END; }
","        { cout << "AUX COMMA" << endl; return comma;}


 /* Complex Tokens */
[*]?[/]?"AND"?             { writeToken("T_MULOPERATOR"); return T_MULOPERATOR; }
[+]?[-]?[&]?"OR"?          { writeToken("T_ADDOPERATOR"); return T_ADDOPERATOR; }
[<]?[>]?[=]?[#]?           { writeToken("T_RELATION"); return T_RELATION; }
\".*\"                     { writeToken("T_STRING"); return T_STRING; }
[+-]?{DIGIT}+\.{DIGIT}+    { writeToken("T_DECIMAL"); return T_DECIMAL; }
[+-]?{DIGIT}+              { writeToken("T_INTEGER"); return T_INTEGER; }
{ALPHA}{ALPHANUM}*         { writeToken("T_IDENT"); return T_IDENT; }

%%   /* -- EPILOGUE  -------------------------------------- */

// Purpose: prints that a token was found
void writeToken(const char* toktype)
{
  cout << "TOKEN: ";
  cout << left << setw(14) << toktype;
  cout << "LEXEME: " << yytext << endl;
}
