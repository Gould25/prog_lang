#!/usr/bin/env python

""" module: integer
    python version: 3.5

    CS3500 HW #1 Python3 version

    purpose: mylexer support function to check if a string is an integer

    Programer: Jeff Gould
    Instructor: Dr Morales

"""
# integer function

def integer(lex):

    i = 0
    state = 1

    while(i < len(lex)):

        # check for leading + or -
        if (lex[i] == '+' or lex[i] == '-') and i == 0:
            state = 5 # first char correct state
        elif lex[i].isdigit():
            state = 2 # accepting state
        else:
            break
        i += 1
    if (i == len(lex) and state == 2):
        return True
    else:
        return False
# end integer function
