#!/usr/bin/env python

""" module: integer
    python version: 3.5

    CS3500 HW #1 Python3 version

    purpose: check if string is an integer
"""

def integer(lex):

    i = 0
    state = 1

    while(i < len(lex)):
        if(lex[i] == '+' || lex[i] == '-' && lex[i] == 0):
            state = 1
        elif(isdigit(lex)):
            state = 2
        else:
            return false
    i++

    return true
