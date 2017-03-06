#include <iostream>
#include <string>
#include "tokens.h"

using namespace std;

int main() {

  /*****     Declarations     *****/
  string input;    // string to run through lexograph

  /*****     Main Body     *****/

  while (cin >> input){

    if ( is_integer(input) )
      print( input, "INTEGER" );
    else if ( is_decimal(input) )
      print( input, "DECIMAL" );
    else if ( is_string(input) )
      print( input, "STRING" );
    else if ( is_keyword(input) )
      print( input, "KEYWORD" );
    else if ( is_identifier(input) )
      print( input, "IDENTIFIER" );
    else
      print( input, "INVALID!" );
  }//end while

  return 0;
}//end main
