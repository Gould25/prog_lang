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

using namespace std;

/*****     Declarations     *****/

// Recognize language Function
// Purpose: to check string s if it is in the languge of the automata
// Post Conditions: returns true if s is in language false if not
bool recognize(string s);

string s;
char retry;
bool check = false;

// end Declarations

int main() {

  do {

    cout << "Enter a string from the alphabet (a,b)" << endl;
    cin >> s;

    //check = recognize(s);

    if (check){
      cout << "YAY String " << s << " is in the alphabet (a,b)!!!!!" << endl;
    }
    else {
      cout << "Sorry String " << s << "isn't in the alphabet (a,b)" << endl;
    }

    cout << "Do you want to check another sting? ";
    cin >> retry;

  } while (retry != 'y' || retry != 'Y');

}
