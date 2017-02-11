#!/usr/bin/env python

""" module: decimal
    python version: 3.5

    CS3500 HW #1 Python3 version

    purpose: mylexer support function to check if a string is a decimal

    Programer: Jeff Gould
    Instructor: Dr Morales

"""
# import integer function
from integer import integer

# decimal function

def decimal(lex):

    if(lex.count('.') == 1):
        pos = lex.index('.') # get pos of '.'
        int_chk = lex[ : pos] # create string before '.'
        num_chk = lex[pos+1: ] # create string after '.'
    else:
        return False

    # check if integer before '.' and if digits after '.'
    if(integer(int_chk) and num_chk.isdigit()):
        return True
    else:
        return False
# end decimal function
