#!/usr/bin/python

import sys

def main():
    multiplicand = 1
    while multiplicand <= 10:
        multiplicator = 1
        while multiplicator <= 10:
            result = multiplicator * multiplicand
            sys.stdout.write("%d x %d = %d\n" % (multiplicator, multiplicand, result))
            multiplicator += 1
        sys.stdout.write("\n")
        multiplicand += 1


main()

