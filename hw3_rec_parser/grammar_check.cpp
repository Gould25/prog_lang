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
bool is_factor(string token);

// function Name: is_term(token)
// Purpose: to find if the string is a term
// Postcondition: returns true or false
bool is_term(string token);

string token;


int main() {

  /*****     Declarations     *****/


  /*****     Main Body     *****/

  get_token();
  while (token != "$"){

    if (is_term(token))
      cout << token << " TRUE" << endl; ;
    cout << token << " FALSE" << endl;;

  }//end while

  return 0;
}//end main

/*****     Get Token Function     *****/

string get_token(){
  cin >> token;
  return token;
}

/*****     Factor Function     *****/

bool is_factor(string token){
  if ( is_integer(token) | is_decimal(token) |
        is_identifier(token) | is_string(token) )
      return true;
  return false;
} // end is_factor

/*****     Term Function     *****/

bool is_term(string token){

  if ( is_factor(token) ){
    cout << "before call " << token << endl;
    token = get_token();
    cout << "after call " << token << endl;
    if (is_mulop(token)){
      cout << "before mulop call " << token << endl;
      token = get_token();
      cout << "after mulop call " << token << endl;
      is_term(token);
    }
    else if (token == "!"){
      get_token();
      return true;
    }
    else
      return false;
  } // eif factor*/
} // end is_term
