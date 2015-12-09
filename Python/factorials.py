#!/usr/bin/python

import sys
import columns

# Number of result columns
COLUMNS = 4

# Limit number for the results
LIMIT = 999999999

# Result output format
RESULT_FORMAT = "%9d"


def main():
    sys.stdout.write("factorials:\n")
    factorials()


def factorials():
    factor = 1
    
    result_counter = 0
    result = 1
    while LIMIT / result > factor:
        result *= factor
        result_counter = columns.print_column(COLUMNS, RESULT_FORMAT,
                                              result, result_counter)
        factor += 1
    columns.finish_column(COLUMNS, result_counter)

main()

