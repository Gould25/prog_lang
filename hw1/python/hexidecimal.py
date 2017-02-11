#!/usr/bin/env python

""" module: hexidecimal

    python version: 3.5

    purpose: mylexer support function to check if a string is hexidecimal

    Programer: Jeff Gould
"""

# hexidecimal function
def hexidecimal(lex):
    state = 1
    i = 0

    # hexidecimal character list
    hex_digits = '0''1''2''3''4''5''6''7''8''9''a''A''b''B''c''C''d''D''e''E''f''F'

    while(i<len(lex)):

        # check if char in set hex_digits
        if (lex[i] in hex_digits):
            state = 2 # hex char state

        # check for final character H
        elif (lex[i] == "H" and i > 0):
            state = 3 # accepting state

        else:
            state = -1 # invalid state
            break
        i += 1

    # check if in final state and end of string
    if(i == len(lex) and state == 3):
        return True
    else:
        return False

# end hexidecimal function
