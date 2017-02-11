#!/usr/bin/env python

""" module: decimal

    python version: 3.5

    purpose: mylexer support function to check if a string is a decimal

    Programer: Jeff Gould
"""

from integer import integer # import integer function

# decimal function
def decimal(lex):

    # check is string has 1 '.'
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
