#!/usr/bin/env python

""" module: integer

    python version: 3.5

    purpose: mylexer support function to check if a string is an integer

    Programer: Jeff Gould
"""
# integer function
def integer(lex):

    i = 0
    state = 1 # starting state

    while(i < len(lex)):

        # check for leading + or -
        if (lex[i] == '+' or lex[i] == '-') and i == 0:
            state = 5 # first char correct state
        elif lex[i].isdigit():
            state = 2 # accepting state
        else:
            break
        i += 1

    # check if in final state and end of string
    if (i == len(lex) and state == 2):
        return True
    else:
        return False
# end integer function
