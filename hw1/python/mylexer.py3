#!/usr/bin/env python

""" module: mylexer
    python version: 3.5

    CS3500 HW #1 Python3 version

    purpose: checks string for types: integer, decimal, scientific,
                                        hexidecimal, identifier, email
    Programer: Jeff Gould
    Instructor: Dr Morales

"""

# main function
def main():
    num = int(input())
    print(num)

    for j in range(num):
        lex = input()
        if (integer(lex)): # check for integer
            print(str(j+1)+": Integer.")
        elif (decimal(lex)): # check for decimal
            print(str(j+1)+": Decimal.")
        elif (scifi(lex)): # check for scientific
            print(str(j+1)+": Scientific.")
        elif (hexidecimal(lex)): # check for hexidecimal
            print(str(j+1)+": Hexidecimal.")
        elif (keyword(lex)): # check for keyword
            print(str(j+1)+": Keyword.")
        elif (identifier(lex)): # check for identifier
            print(str(j+1)+": Identifier.")
        elif (email(lex)): # check for identifier
            print(str(j+1)+": Email.")
        else: # INVALID
            print(str(j+1)+": INVALID!")

    decimal(lex)

def integer(lex):

    i = 0
    state = 1

    while(i < len(lex)):

        if (lex[0] == '+' or lex[0] == '-') and i == 0:
            state = 5
        elif lex[i].isdigit():
            state = 2
        else:
            break
        i += 1
    if (i == len(lex) and state == 2):
        return True
    else:
        return False

def decimal(lex):
    if(lex.count('.')>0):
        pos = lex.index('.')
        int_chk = lex[ : pos]
        num_chk = lex[pos+1: ]
    else:
        return False

    if(integer(int_chk) and num_chk.isdigit()):
        return True
    else:
        return False

def scifi(lex):
    if(lex.count('E')>0):
        pos = lex.index('E')
        int_chk = lex[pos+1: ]
        dec_chk = lex[ : pos]
    else:
        return False

    if(integer(int_chk) and decimal(dec_chk)):
        return True
    else:
        return False

def hexidecimal(lex):
    state = 1
    i = 0
    hex_digits = '0''1''2''3''4''5''6''7''8''9''a''A''b''B''c''C''d''D''e''E''f''F'
    while(i<len(lex)):
        if (lex[i] in hex_digits):
            state = 2
        elif (lex[i] == "H"):
            state = 3
        else:
            state = -1
            break
        i += 1
    if(i == len(lex) and state == 3):
        return True
    else:
        return False
# end hexidecimal function

def keyword(lex):
    keyword_list = "while""if""else""print"

    if lex in keyword_list:
        return True
    else:
        return False
# end keyword function

def identifier(lex):
    state = 1
    i = 0
    while (i < len(lex)):
        if (lex[i].isalpha() and state == 1):
            state = 2
        elif ( (lex[i].isalnum() or lex[i] == '_') and (state == 2 or state == 3)):
            state = 3
        elif ( lex[i] == '.' and (state == 3 or state == 2)):
            state = 1
        else:
            state = -1
        i += 1
    if ( i == len(lex) and (state == 3 or state == 2) ):
        return True
    else:
        return False
# end identifier function

def email(lex):
    if(lex.count('@') == 1):
        suffix_list = ".com"".edu"".net"
        n = len(lex)
        pos = lex.index('@')
        suffix = lex[ n-4 : ]
        post_identifier = lex[pos+1 : n-4]
        pre_identifier = lex[ : pos]
    else:
        return False

    if(identifier(pre_identifier) and identifier(post_identifier)
        and suffix in suffix_list):
            return True
    else:
        return False
# end email function

main()
