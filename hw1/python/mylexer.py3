#!/usr/bin/env python

""" module: mylexer
    python version: 3.5

    CS3500 HW #1 Python3 version

    purpose: checks string for types: integer, decimal, scientific,
                                        hexidecimal, identifier, email
    Programer: Jeff Gould
    Instructor: Dr Morales

"""

from fncts import *          # import functions

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
# end MAIN FUNCTION

# call main function
main()
