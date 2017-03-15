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

// function Name: is_simple_exp()
// Purpose: to find if the string is a simple expression
// Postcondition: returns true or false
bool is_expression();


string token;


int main() {

  /*****     Declarations     *****/

int i = 0;

  /*****     Main Body     *****/
  get_token();

  //do {

    if (is_expression())
      cout << token << "\tCORRECT   " << i << endl;
    else{
      cout << token << "\tINVALID!   " << i << endl;
    }
  //  get_token();
    i++;
  //}while(token != "$");

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
    cerr << "IN TERM before token call " << token << endl;

    get_token();
    cerr << "IN TERM after token call " << token << endl;

    check = true;
  }
  else
    return false;

    while ( is_mulop(token) ){
        get_token();
        if(is_factor()){
            check = true;
            get_token();
            //if ( is_mulop(token) || token == "$")
            //  check = true;
        } // end if
        else
          return false;
    } // end while

  /*****    RETURN SECTION     ******/

  if (check ){
    cerr << "TERM ret truye " << token << endl;
    return true;
  }
  else {
    return false;
  }
  //get_token();

} // end is_term

/*****     Simple Expression Function     *****/

bool is_simple_exp(){

  bool check;

  if ( is_term() ) {
    //get_token();
    cerr << "In Simple " << token << endl;

    check = true;
  }
  else
  cerr << "In Simple FAIIIIIIIIIIIIIIIIILLLLLLL   " << token << endl; //return false;
  if ( is_addop(token) ) {
    cerr << "In Simple  addop before while  " << token << endl;

    while ( is_addop(token) ){
      get_token();
      if(is_term()){
        check = true;
        if ( is_addop(token) || token == "$" || token == "]")
          check = true;
        else
          return false;
      } // end if
      else
        return false;
    } // end while
  } // end if
  //else
    //return false;

 /*****    RETURN SECTION     ******/

  if (check){
    cerr << "Simple Ret Treue " << token << endl;

    return true;
  }
  else {
    return false;
  }
  //get_token();

} // end is_simple_exp

/*****     Expression Function     *****/

bool is_expression(){

  bool check;

  if ( is_simple_exp() ) {
    //get_token();
    check = true;
  }
  else
    check = false;

  if (token == "["){
    cerr << "Begin Bracket before " << token << endl;
    get_token();
    if (is_relation(token)){
      cerr << "Relation before " << token << endl;
      get_token();
      cerr << "Relation after " << token << endl;
      if (is_simple_exp()){
        //get_token();
        cerr << "Simple " << token << endl;
        if (token == "]"){
          return true;
        }
        else
          check = false;
      }
      else
        check = false;
    }
    else
      check = false;
  }
 /*****    RETURN SECTION     ******/

  if (check){
    return true;
  }
  else {
    return false;
  }
  get_token();

} // end expression
