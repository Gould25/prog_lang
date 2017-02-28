/* Programmer: Jeff Gould */
/* HW2 Flex assignment using regex */

%{
/*****     Declarations     *****/

#include <iostream>
using namespace std;

int total_lines = 0;        // total number of lines
int process_num = 0;        // processed number
string s;                   // lexeme type
void print_lex(string s);   // print function

%}

/*****     Definitions     *****/

%option noyywrap
DIGIT       [0-9]
ALPHA       [a-zA-Z]
ALPHANUM    [a-zA-z0-9]
HEX         [0-9ABCDEF]
BIN         [0|1]
OPERATOR    [+|*|/|<|>|&|-]
SUFFIX      [\.com|\.net|\.edu]
KEYWORD     [while|if|then|else|end|bannana]

/*****     REG EX     *****/
%%


[ \t]                     {; // skipping white space
}

[\n]                      { total_lines++; // incrementing total_lines
}

%(.)*                     {; // skip comment
}

[+-]?{DIGIT}+             { // check for integer
  print_lex("INTCONST");
}

[+-]?{DIGIT}+[.]{DIGIT}+  { // check for decimal
  print_lex("DECCONST");
}

[+-]?{DIGIT}+[.]{DIGIT}+[E][+|-]?{DIGIT}+  { // check for scientific number
  print_lex("SCICONST");
}

{HEX}+[H]                 { // check for hexidecimal
  print_lex("HEXCONST");
}

{BIN}+[B]                 { // check for binary number
  print_lex("BINCONST");
}

{OPERATOR}                { // check for OPERATOR
  print_lex("OPERATOR");
}

while|if|then|else|banana { // check for keyword
  print_lex("KEYWORD");
}

({ALPHA}+{ALPHANUM}*([\.]{ALPHA}+{ALPHANUM}*)*[@]{ALPHA}+{ALPHANUM}*((\.{ALPHA}+({ALPHANUM}*))*(([\.com]|[\.net]|[\.edu])+))) {
 // check for email
  print_lex("EMCONST");
}

{ALPHA}+{ALPHANUM}*       { // check for identifier
  print_lex("IDENT");
}

\".*\"                    { // check for string literal
  print_lex("STRCONST");
}

[\^]                      { // new line character add 1 to num_lines_process
  print_lex("?     ");
  total_lines++;
}

.                         { // default rule
  print_lex("?     ");
}

%%

/*****     CODE     *****/

void print_lex(string s){
  cout << "#" << process_num <<": TOKEN: "<< s <<"\tLEXEME: "<< yytext << endl;
  process_num ++; // increment process number
}

main(){
  // lex through the input file
  yylex();
  cout << total_lines  << " lines processed." << endl;

  return 0;
}
