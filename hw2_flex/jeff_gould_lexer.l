/* Programmer: Jeff Gould */
/* HW2 Flex assignment using regex */

%{
/*****     Declarations     *****/

#include <iostream>
using namespace std;

int total_lines = 0;      // total number of lines
int total_comments = 0;   // total comments
int num_lines_process = 0;  // total lines processed

%}

/*****     Definitions     *****/

%option noyywrap
DIGIT       [0-9]
ALPHA       [a-zA-Z]

/*****     REG EX     *****/
%%

[ \t]                ;
[\n]                 { total_lines++; }
[%]                  { ; }
{DIGIT}+\.{DIGIT}+   { cout << "Found Floating-point number:" << yytext << endl;}
{DIGIT}+             { cout << "Found an integer:" << yytext << endl; }
{ALPHA}{DIGIT}+      { cout << "Found a string:" << yytext << endl; }

%%

/*****     CODE     *****/

main(){
  // lex through the input file
  yylex();
  cout << total_lines - total_comments << " lines processed." << endl;
  cout << "total lines = " << total_lines << endl;
  cout << "total comments = " << total_comments << endl;
  return 0;
}
