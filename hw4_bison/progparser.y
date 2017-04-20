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
%token T_STRING
%token T_RELATION
%token T_ADDOPERATOR
%token T_MULOPERATOR

%token K_BANG
%token K_ASSIGN
%token K_LPAREN
%token K_RPAREN
%token K_PRINT
%token K_NEG
%token K_RET
%token K_IF
%token K_FI
%token K_ELSE
%token K_LOOP
%token K_POOL
%token K_FUNC
%token K_BEGIN
%token K_END
%token comma

%%   // GRAMMAR RULES ------------------------------------

FunctionSequence : FunctionDeclaration
                  { cout << "RULE: FunctionSequence ::= FunctionDeclaration" << endl;}
                 | FunctionDeclaration FunctionSequence
                  { cout << "RULE: FunctionSequence ::= FunctionDeclaration FunctionSequence" << endl;}
                  ;

FunctionDeclaration : K_FUNC T_IDENT K_LPAREN K_RPAREN K_BEGIN StatementSeq K_END
                    { cout << "RULE: FunctionDeclaration ::= FUNC identifier ( ) BEGIN StatementSequence END." << endl;}
                  | K_FUNC T_IDENT K_LPAREN ParamSequence K_RPAREN K_BEGIN StatementSeq K_END
                    { cout << "RULE: FunctionDeclaration ::= FUNC identifier ( ParamSequence ) BEGIN StatementSequence END." << endl;}
                    ;

ParamSequence : T_IDENT comma ParamSequence
                { cout << "RULE: ParamSequence ::= identifier , ParamSequence" << endl;}
              | T_IDENT
                { cout << "RULE: ParamSequence ::= identifier" << endl;}
                ;

StatementSeq : statement
              { cout << "RULE: StatementSequence ::= Statement" << endl; }
            | statement StatementSeq
              { cout << "RULE: StatementSequence ::= Statement StatementSequence" << endl; }
              ;

statement : assignment    { cout << "RULE: Statement ::= Assignment" << endl; }
         | PrintStatement { cout << "RULE: Statement ::= PrintStatement" << endl; }
         | RetStatement   { cout << "RULE: Statement ::= RetStatement" << endl; }
         | IfStatement    { cout << "RULE: Statement ::= IfStatement" << endl; }
         | LoopStatement  { cout << "RULE: Statement ::= LoopStatement" << endl; }
         ;

assignment : T_IDENT K_ASSIGN Expression K_BANG
          { cout << "RULE: Assignment ::= identifier := Expression !" << endl; }

PrintStatement : K_PRINT K_LPAREN Expression K_RPAREN K_BANG
              { cout << "RULE: PrintStatement ::= PRINT ( Expression ) !" << endl; }
              ;

RetStatement : K_RET T_IDENT K_BANG
              { cout << "RULE: RetStatement ::= RET identifier !" << endl; }
              ;

IfStatement : K_IF K_LPAREN Expression K_RPAREN StatementSeq K_FI
              { cout << "RULE: IfStatement ::= IF ( EXPR ) StmSeq FI" << endl; }
            | K_IF K_LPAREN Expression K_RPAREN StatementSeq K_ELSE StatementSeq K_FI
              { cout << "RULE: IfStatement ::= IF ( Expression ) StatementSequence ELSE StatementSequence FI" << endl; }
              ;

LoopStatement : K_LOOP K_LPAREN Expression K_RPAREN StatementSeq K_POOL
              { cout << "RULE: LoopStatement ::= LOOP ( Expression ) StatementSequence POOL" << endl; }
              ;
Expression : SimpleExpression
              { cout << "RULE: Expression ::= SimpleExpression" << endl; }
            | SimpleExpression T_RELATION Expression
              { cout << "RULE: Expression ::= SimpleExpression Relation Expression" << endl; }
              ;

SimpleExpression : Term
              { cout << "RULE: SimpleExpression ::= Term" << endl; }
            | Term T_ADDOPERATOR SimpleExpression
              { cout << "RULE: SimpleExpression ::= Term AddOperator SimpleExpression" << endl; }
              ;

Term : Factor
              { cout << "RULE: Term ::= Factor" << endl; }
            | Factor T_MULOPERATOR Term
              { cout << "RULE: Term ::= Factor MulOperator Term" << endl; }
            | K_NEG Factor
              { cout << "RULE: Term ::= NEGATIVE FACTOR" << endl; }
              ;

Factor : T_INTEGER { cout << "RULE: Factor ::= integer" << endl; }
            | T_DECIMAL  { cout << "RULE: Factor ::= decimal" << endl; }
            | T_STRING   { cout << "RULE: Factor ::= string" << endl; }
            | T_IDENT    { cout << "RULE: Factor ::= identifier" << endl; }
            | K_LPAREN Expression K_RPAREN { cout << "RULE: FACTOR ::= Expression" << endl; }
            ;

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
 failcode = yyparse();

 if (failcode)
   cout << "INVALID!" << endl;
 else
   cout << "CORRECT" << endl;
 return 0;
}
