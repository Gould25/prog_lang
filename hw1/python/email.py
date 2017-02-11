#!/usr/bin/env python

""" module: email

    python version: 3.5

    purpose: mylexer support function to check if a string is an email

    Programer: Jeff Gould
"""

from identifier import identifier # import identifier function

# email function
def email(lex):

    # checking for 1 '@'
    if(lex.count('@') == 1):

        #create a suffix list
        suffix_list = ".com"".edu"".net"
        n = len(lex) # set end of string
        pos = lex.index('@') # position of '@'
        suffix = lex[ n-4 : ] # create str from end -4 to end
        post_identifier = lex[pos+1 : n-4] # create str '@' to suffix
        pre_identifier = lex[ : pos] # create str from begin to '@'

    else:
        return False

    # check if pre/post are identifiers and is suffix in list
    if(identifier(pre_identifier) and identifier(post_identifier)
        and suffix in suffix_list):
            return True
    else:
        return False
        
# end email function
