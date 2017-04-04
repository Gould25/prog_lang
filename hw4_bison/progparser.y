/*
Programmer: Jeff Gould ID#:12517284
Date: April 3, 2017
Instructor: DR. Morales
Section: 1B
File: progparser.l
Description: bison file
*/
// -- PREAMBLE ------------------------------------------
%{
#include <iostream>
using namespace std;

 // Things from Flex that Bison needs to know
extern int yylex();
extern int line_num;
extern char* yytext;

 // Prototype for Bison's error message function
int yyerror(const char *p);
%}

//-- TOKEN DEFINITIONS --
// what tokens to expect from Flex
%token T_IDENT
%token T_INTEGER
%token T_DECIMAL

%token K_BANG
%token K_ASSIGN
%token K_LPAREN
%token K_RPAREN
%token K_PRINT


%%   //-- GRAMMAR RULES ------------------------------------
/* NOTE: Bison likes the start symbol to be the first rule */
statementSeq : statement
              { cout << "RULE: StatementSeq ::= Statement" << endl; }
            | statement statementSeq
        { cout << "RULE: StatementSeq ::= Statement StatementSeq" << endl; }
            ;

statement : /* empty */     { cout << "RULE: Statement ::= empty" << endl; }
         | assignment      { cout << "RULE: Statement ::= Assignment" << endl; }
         | PrintStatement  { cout << "RULE: Statement ::= PrintStatement" << endl; }
         ;

assignment : T_IDENT K_ASSIGN T_DECIMAL K_BANG
          { cout << "RULE: Assignment ::= ident := decimal ! " << endl; }

PrintStatement : K_PRINT K_LPAREN T_INTEGER K_RPAREN K_BANG
              { cout << "RULE: PrintStatement ::= PRINT ( integer ) !" << endl; }


%% //-- EPILOGUE ---------------------------------------------
// Bison error function
int yyerror(const char *p)
{
 cout << "ERROR: In line " << line_num << " with token \'"
      << yytext << "\'" << endl;
}

int main()
{
 int failcode;
 cout << "Hello Flex + Bison" << endl;
 failcode = yyparse();

 if (failcode)
   cout << "INVALID!" << endl;
 else
   cout << "CORRECT" << endl;
 return 0;
}
