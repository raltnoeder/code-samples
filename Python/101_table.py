#!/usr/bin/python

import sys


def main():
    multiplicator = 1
    while multiplicator <= 10:
        multiplicand = 1
        while multiplicand <= 10:
            result = multiplicator * multiplicand
            sys.stdout.write("%4d" % (result))
            multiplicand += 1
        sys.stdout.write("\n")
        multiplicator += 1


main()

