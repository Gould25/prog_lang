/* Programmer: Jeff Gould */
/* HW2 Flex assignment using regex */

%{
/*****     Declarations     *****/

#include <iostream>
using namespace std;

int total_lines = 0;        // total number of lines
int process_num = 0;        // processed number

%}

/*****     Definitions     *****/

%option noyywrap
DIGIT       [0-9]
ALPHA       [a-zA-Z]
HEX         [0-9ABCDEF]

/*****     REG EX     *****/
%%


[ \t]                     ;
[\n]                     { total_lines++;  }

%(.)*                     ;



[+-]?{DIGIT}+             { // check for integer
  process_num ++; // increment process number
  cout << "#" << process_num << ": TOKEN: INTCONST\tLEXEME: " << yytext << endl;
}

[+-]?{DIGIT}+[.]{DIGIT}+  { // check for decimal
  process_num ++; // increment process number
  cout << "#" << process_num << ": TOKEN: DECCONST \tLEXEME: " << yytext << endl;
}

{HEX}+[H]                 { // check for hexidecimal
  process_num ++; // increment process number
  cout << "#" << process_num << ": TOKEN: HEXCONST \tLEXEME: " << yytext << endl;
}

\"(\\.|[^"])*\"           { // check for string literal
  process_num ++; // increment process number
  cout << "#" << process_num << ": TOKEN: STRCONST\tLEXEME: " << yytext << endl;
}

.                         { // default rule
  process_num ++; // increment process number
  cout << "#" << process_num << ": TOKEN: ?       \tLEXEME: " << yytext << endl;
}
%%

/*****     CODE     *****/

main(){
  // lex through the input file
  yylex();
  cout << total_lines  << " lines processed." << endl;

  return 0;
}
