/*
Programmer: Jeff Gould ID#:12517284
Date: Jan 31, 2017
Instructor: DR. Morales
Section: 1A
File: cpp_automata_encode.cpp
Description: C++ program for encoding an automata
*/

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

/*****     Declarations     *****/

// Recognize language Function
// Purpose: to check string s if it is in the languge of the automata
// Post Conditions: returns true if s is in language false if not
bool recognize(string s);

string s;
char retry;
bool check = true;

// end Declarations

int main() {

  do {

    cout << "Enter a string from the alphabet (a,b) ";
    cin >> s;
    cout << endl;

    check = recognize(s);

    if (check){
      cout << "YAY String " << s << " is in the alphabet (a,b)!!!!!";
      cout << endl << endl;
    }
    else {
      cout << "Sorry String " << s << " isn't in the alphabet (a,b)";
      cout << endl << endl;
    }

    cout << "Do you want to check another sting? ";
    cin >> retry;
    cout << endl << endl;

  } while (retry == 'y');

  cout << "Thanks have a great day!!!!!";

  return 0;
}

bool recognize(string s) {
  int state = 1;
  int i = 0;

  while ( i < s.length()) {
    switch (state) {

      case 1: if ( s[i] == 'a' )
                state = 2;
              else
                state = 1;
              break;

      case 2: if ( s[i] == 'a' )
                state = -1; // failure
              else
                state = 3;
              break;

      case 3: if ( s[i] == 'a' )
                state = 2; // failure
              else
                state = 4;
              break;

      case 4: if ( s[i] == 'a' )
                state = 4; // failure
              else
                state = 2;
              break;

      default:
              i = s.length();
              break;
    } // end switch

    i ++;
  } // end while

  if ( i == s.length() && state == 4 )
    return true;

  return false;
} // end fnct
