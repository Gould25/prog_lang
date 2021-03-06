#include <iostream>
#include <string>
#include <sstream>
#include "tokens.h"

using namespace std;

// function Name: get_token()
// Purpose: Retrieve the next token
// Postcondition: token is returned
string get_token();

// function Name: is_factor(token)
// Purpose: to find if the string is a factor
// Postcondition: returns true or false
bool is_factor();

// function Name: is_term()
// Purpose: to find if the string is a term
// Postcondition: returns true or false
bool is_term();

// function Name: is_simple_exp()
// Purpose: to find if the string is a simple expression
// Postcondition: returns true or false
bool is_simple_exp();

// function Name: is_expression()
// Purpose: to find if the string is an expression
// Postcondition: returns true or false
bool is_expression();

// function Name: is_assignment()
// Purpose: to find if the string is an assignment
// Postcondition: returns true or false
bool is_assignment();

// function Name: is_print()
// Purpose: to find if the string is a print statement
// Postcondition: returns true or false
bool is_print();

// function Name: is_ret()
// Purpose: to find if the string is a return statement
// Postcondition: returns true or false
bool is_ret();

// function Name: is_statement()
// Purpose: to find if the string is a statement
// Postcondition: returns true or false
bool is_statement();

// function Name: is_state_seq()
// Purpose: to find if the string is a statement sequence
// Postcondition: returns true or false
bool is_state_seq();

// function Name: is_if()
// Purpose: to find if the string is an if statement
// Postcondition: returns true or false
bool is_if();

// function Name: is_loop()
// Purpose: to find if the string is a loop statement
// Postcondition: returns true or false
bool is_loop();

// function Name: is_parameter()
// Purpose: to find if the string is a parameter
// Postcondition: returns true or false
bool is_parameter();

// function Name: is_fnct_decl()
// Purpose: to find if the string is a function declaration
// Postcondition: returns true or false
bool is_fnct_decl();

// function Name: is_fnct_seq()
// Purpose: to find if the string is a sequence of functions
// Postcondition: returns true or false
bool is_fnct_seq();

string token;     // global variable for input

int main() {

  /*****     Main Body     *****/
  get_token();

    if ( is_fnct_seq() )
      cout << "CORRECT" << endl;
    else
      cout << "INVALID!" << endl;

  return 0;
}//end main

/*****     Get Token Function     *****/

string get_token(){
  if(cin >> token)
    return token;
  else{
    token = "$";
    return token;
  }
}

/*****     Factor Function     *****/

bool is_factor(){
  if ( is_integer(token) | is_decimal(token) |
        is_identifier(token) | is_string(token) )
      return true;
  return false;
} // end is_factor

/*****     Term Function     *****/

bool is_term(){

  bool check;

  if ( is_factor() ) {
    get_token();
    check = true;
  }
  else
    return false;

    while ( is_mulop(token) ){
        get_token();
        if(is_factor()){
            check = true;
            get_token();
        } // end if
        else
          return false;
    } // end while

  /*****    RETURN SECTION     ******/

  if (check )
    return true;
  else
    return false;

} // end is_term

/*****     Simple Expression Function     *****/

bool is_simple_exp(){

  bool check;

  if ( is_term() ) {
    check = true;
  }
  else
    return false;
  if ( is_addop(token) ) {
    while ( is_addop(token) ){
      get_token();
      if(is_term()){
        check = true;
        if ( is_addop(token) || token == "$" || token == "!" || token == ")")
          check = true;
          else
            return false;
      } // end if
      else
        return false;
    } // end while
  } // end if

 /*****    RETURN SECTION     ******/

  if (check)
    return true;
  else {
    return false;
  }
  //get_token();

} // end is_simple_exp

/*****     Expression Function     *****/

bool is_expression(){

  bool check;

  if ( is_simple_exp() ) {
    check = true;
  }
  else
    check = false;

  if (is_relation(token)){
    get_token();
    if (is_simple_exp()){
      return true;
    }
    else
      check = false;
  } // end if

 /*****    RETURN SECTION     ******/

  if (check)
    return true;
  else
    return false;
} // end expression

/*****     assignment Function     *****/

bool is_assignment(){

  if ( is_identifier(token) ) {
    get_token();
    if ( token == ":=" ){
      get_token();
      if ( is_expression() ){
        if ( token == "!"){
          get_token();
          return true;
        }
        else
          return false;
      }
      else
        return false;
    }
    else
      return false;
  }
  else
    return false;
} // end is_assignment

/*****     print statement Function     *****/

bool is_print(){

  if ( token == "PRINT" ) {
    get_token();
    if ( token == "(" ){
      get_token();
      if ( is_expression() ){
        if ( token == ")"){
          get_token();
          if ( token == "!" ){
            get_token();
            return true;
          }
          else
            return false;
        }
        else
          return false;
      }
      else
        return false;
    }
    else
      return false;
  }
  else
    return false;
} // end is_print

/*****     return statement Function     *****/

bool is_ret(){

  if ( token == "RET" ) {
    get_token();
    if ( is_identifier(token) ){
      get_token();
      if ( token == "!" ){
        get_token();
        return true;
      }
      else
        return false;
    }
    else
      return false;
  }
  else
    return false;
} // end is_ret

/*****     statement Function     *****/

bool is_statement(){
  if ( is_print() | is_assignment() | is_loop() |
        is_ret() | is_if() )
      return true;
  return false;
} // end is_statement

/*****     statement sequence Function     *****/

bool is_state_seq(){

  bool check;
  bool state;

  if ( is_statement() ){
    check = true;

    if ( is_statement() ){
      state = true;
      check = true;
      while( state ){
        if ( is_statement() ){
          check = true;
          state = true;
        }
        else
        state = false;
      } // end while
    }
  }
  else
    check = false;
  /*****    RETURN SECTION     ******/
  if (check )
    return true;
  else
    return false;
} // end is_state_seq

/*****     if statement Function     *****/

bool is_if(){
  if ( token == "IF" ){
    get_token();
    if ( token == "(" ){
      get_token();
      if ( is_expression() ){
        if ( token == ")" ){
          get_token();
          if ( is_state_seq() ){
            if ( token == "FI"){
              get_token();
              return true;
            }
            else if ( token == "ELSE" ){
              get_token();
              if ( is_state_seq() ){
                if ( token == "FI"){
                  get_token();
                  return true;
                }
                else
                  return false;
              }
              else
                return false;
            }
            else{
              return false;
            }
          }
          else
            return false;
        }
        else
          return false;
      }
      else
        return false;
    }
    else
      return false;
  }
  else
    return false;
} // end is_if

/*****     loop statement Function     *****/

bool is_loop(){
  if ( token == "LOOP" ){
    get_token();
    if ( token == "(" ){
      get_token();
      if ( is_expression() ){
        if ( token == ")" ){
          get_token();
          if ( is_state_seq() ){
            if ( token == "POOL"){
              get_token();
              return true;
            }
            else
              return false;
          }
          else
            return false;
        }
        else
          return false;
      }
      else
        return false;
    }
    else
      return false;
  }
  else
    return false;
} // end is_loop

/*****     Parameter Function     *****/

bool is_parameter(){

  bool check;

  if ( is_identifier(token) ) {
    get_token();
    check = true;
    while ( token == "," ){
        get_token();
        if ( is_identifier(token) ){
            get_token();
            check = true;
        } // end if
        else
          check = false;
    } // end while
  }
  else
    check = false;

  /*****    RETURN SECTION     ******/

   if (check)
     return true;
   else
     return false;
} // end is_parameter

/*****     function declaration Function     *****/

bool is_fnct_decl(){
  if ( token == "FUNC" ){
    get_token();
    if ( is_identifier(token) ){
      get_token();
      if ( token == "(" ){
        get_token();
        if ( token == ")" ){
          get_token();
          if ( token == "BEGIN"){
            get_token();
            if ( is_state_seq()){
              //get_token();
              if ( token == "END." ){
                return true;
              }
              else
                return false;
            }
            else
              return false;
          }
          else
            return false;
        }
        else if ( is_parameter() ){
          if ( token == ")" ){
            get_token();
            if ( token == "BEGIN"){
              get_token();
              if ( is_state_seq()){
                //get_token();
                if ( token == "END." ){
                  return true;
                }
                else
                  return false;
              }
              else
                return false;
            }
            else
              return false;
          }
          else
            return false;
        }
        else
          return false;
      }
      else
        return false;
    }
    else
      return false;
  }
  else
    return false;
} // end is_fnct_decl

/*****     Function sequence Function     *****/

bool is_fnct_seq(){

  bool check;

  if ( is_fnct_decl() ){
    get_token();
    if ( token == "$" ) {
      return true;
    }
    else if ( is_fnct_decl() ){
      while( is_fnct_decl() ){
        if ( is_fnct_decl() ){
          check = true;
          get_token();
        }
        else
          check = false;
      }
      if (token == "$"){
        return true;
      }
    } // end el if
    else
      check = false;
  }
  else
    check = false;
  /*****    RETURN SECTION     ******/
  if (check )
    return true;
  else
    return false;
} // end is_fnct_seq
