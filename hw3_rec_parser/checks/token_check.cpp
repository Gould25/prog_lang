#include <iostream>
#include <string>
#include "tokens.h"

using namespace std;

int main() {

  /*****     Declarations     *****/
  string token;    // string to run through lexograph

  /*****     Main Body     *****/

  while (cin >> token){

    if ( is_integer(token) )
      print( token, "INTEGER" );
    else if ( is_decimal(token) )
      print( token, "DECIMAL" );
    else if ( is_string(token) )
      print( token, "STRING" );
    else if ( is_identifier(token) && !is_keyword(token) )
      print( token, "IDENTIFIER" );
    else if ( is_relation(token) )
      print( token, "Relation" );
    else if ( is_addop(token) )
      print( token, "Addition Operator" );
    else if ( is_mulop(token) )
      print( token, "Multiply Operator" );
    else if ( is_keyword(token) )
      print( token, "KEYWORD" );
    else
      print( token, "INVALID!" );
  }//end while

  return 0;
}//end main
