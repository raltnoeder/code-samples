#!/usr/bin/python

import sys
import columns

# Number of result columns
COLUMNS = 8

# Limit number for the results
LIMIT = 999999

# Result output format
RESULT_FORMAT = "%6d"

FACTOR_LIST = [
    2,
    3,
    5,
    7,
    11,
    13,
    17,
    19,
    23,
    29
]


def powers(factor):
    sys.stdout.write("Powers of %d:\n" % (factor))
    number = factor
    max    = LIMIT / factor
    sys.stdout.write(RESULT_FORMAT % (factor))
    result_counter = 1
    
    while number <= max:
        number *= factor
        result_counter = columns.print_column(COLUMNS, RESULT_FORMAT,
                                              number, result_counter)
    columns.finish_column(COLUMNS, result_counter)

def main():
    for factor in FACTOR_LIST:
        powers(factor)
    exit(0)


main()
