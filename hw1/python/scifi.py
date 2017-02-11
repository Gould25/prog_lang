#!/usr/bin/env python

""" module: scifi

    python version: 3.5

    purpose: mylexer support function to check if a string is scientific

    Programer: Jeff Gould
"""

from integer import integer    # import integer function
from decimal import decimal    # import decimal function

# scifi function
def scifi(lex):

    # check for 1 and only 1 E
    if(lex.count('E') == 1):
        pos = lex.index('E') # position of E
        int_chk = lex[pos+1: ] # create string before E
        dec_chk = lex[ : pos] # create string after E
    else:
        return False

    # check if before and after strings hold
    if(integer(int_chk) and decimal(dec_chk)):
        return True
    else:
        return False

# end scifi function
