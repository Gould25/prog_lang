#!/usr/bin/env python

""" module: identifier

    python version: 3.5

    purpose: mylexer support function to check if a string is an identifier

    Programer: Jeff Gould
"""

# identifier function
def identifier(lex):
    state = 1
    i = 0

    while (i < len(lex)):

        # check if first char is an alpha char
        if (lex[i].isalpha() and state == 1):
            state = 2 # accepting state

        # check if following chars are alpha digits or '_'
        elif ( (lex[i].isalnum() or lex[i] == '_') and (state == 2 or state == 3)):
            state = 3 # accepting state

        # check for multiple identifier if '.' send to start state
        elif ( lex[i] == '.' and (state == 3 or state == 2)):
            state = 1 # starting state
        else:
            state = -1 # invalid state
        i += 1

    # check if end of string and accepting state
    if ( i == len(lex) and (state == 3 or state == 2) ):
        return True
    else:
        return False

# end identifier function
