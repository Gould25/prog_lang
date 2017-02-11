#!/usr/bin/env python

""" module: keyword

    python version: 3.5

    purpose: mylexer support function to check if a string is a keyword

    Programer: Jeff Gould
"""

# keyword function
def keyword(lex):

    # create list of keywords
    keyword_list = "while""if""else""print"

    # check if string is a keyword
    if lex in keyword_list:
        return True
    else:
        return False
        
# end keyword function
