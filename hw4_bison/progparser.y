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
                  { cout << "RULE: FunctionSequence ::= Declaration Sequence" << endl;}
                  ;

FunctionDeclaration : K_FUNC T_IDENT K_LPAREN K_RPAREN K_BEGIN StatementSeq K_END
                    { cout << "RULE: FunctionDeclaration ::= Function" << endl;}
                  | K_FUNC T_IDENT K_LPAREN ParamSequence K_RPAREN K_BEGIN StatementSeq K_END
                    { cout << "RULE: FunctionDeclaration ::= ParameterFunction" << endl;}
                    ;

ParamSequence : T_IDENT
                { cout << "RULE: ParamSequence ::= Identifier" << endl;}
              | T_IDENT comma ParamSequence
                { cout << "RULE: ParamSequence ::= Identifier ParamSequence" << endl;}
                ;

StatementSeq : statement
              { cout << "RULE: StatementSeq ::= Statement" << endl; }
            | statement StatementSeq
              { cout << "RULE: StatementSeq ::= Statement StatementSeq" << endl; }
              ;

statement : /* empty */   { cout << "RULE: Statement ::= empty" << endl; }
         | assignment     { cout << "RULE: Statement ::= Assignment" << endl; }
         | PrintStatement { cout << "RULE: Statement ::= PrintStatement" << endl; }
         | RetStatement   { cout << "RULE: Statement ::= RetStatement" << endl; }
         | IfStatement    { cout << "RULE: Statement ::= IfStatement" << endl; }
         | LoopStatement  { cout << "RULE: Statement ::= LoopStatement" << endl; }
         ;

assignment : T_IDENT K_ASSIGN Expression K_BANG
          { cout << "RULE: Assignment ::= ident := Expression ! " << endl; }

PrintStatement : K_PRINT K_LPAREN Expression K_RPAREN K_BANG
              { cout << "RULE: PrintStatement ::= PRINT ( Expression ) !" << endl; }
              ;

RetStatement : K_RET T_IDENT K_BANG
              { cout << "RULE: RetStatement ::= Ret identifier !" << endl; }
              ;

IfStatement : K_IF K_LPAREN Expression K_RPAREN StatementSeq K_FI
              { cout << "RULE: IfStatement ::= IF ( EXPR ) StmSeq FI !" << endl; }
            | K_IF K_LPAREN Expression K_RPAREN StatementSeq K_ELSE StatementSeq K_FI
              { cout << "RULE: IfElseStatement ::= IF ( EXPR ) StmSeq ELSE StmSeq FI !" << endl; }
              ;

LoopStatement : K_LOOP K_LPAREN Expression K_RPAREN StatementSeq K_POOL
              { cout << "RULE: LoopStatement ::= LOOP ( EXPR ) StmSeq POOL !" << endl; }
              ;
Expression : SimpleExpression
              { cout << "RULE: Expression ::= Simple Expression !" << endl; }
            | SimpleExpression T_RELATION Expression
              { cout << "RULE: Expression ::= Relation !" << endl; }
              ;

SimpleExpression : Term
              { cout << "RULE: Simple Expression ::= Term !" << endl; }
            | Term T_ADDOPERATOR SimpleExpression
              { cout << "RULE: Simple Expression ::= ADDOPERATOR !" << endl; }
              ;

Term : Factor
              { cout << "RULE: Term ::= Factor !" << endl; }
            | Factor T_MULOPERATOR Term
              { cout << "RULE: Term ::= MULOPERATOR !" << endl; }
            | K_NEG Factor
              { cout << "RULE: Term ::= NEGATIVE FACTOR !" << endl; }
              ;

Factor : T_INTEGER { cout << "RULE: FACTOR ::= INTEGER" << endl; }
            | T_DECIMAL  { cout << "RULE: FACTOR ::= DECIMAL" << endl; }
            | T_STRING   { cout << "RULE: FACTOR ::= STRING" << endl; }
            | T_IDENT    { cout << "RULE: FACTOR ::= IDENTIFIER" << endl; }
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
 cout << "Hello Flex + Bison" << endl;
 failcode = yyparse();

 if (failcode)
   cout << "INVALID!" << endl;
 else
   cout << "CORRECT" << endl;
 return 0;
}
