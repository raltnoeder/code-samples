#!/usr/bin/python

import sys
import columns

# Number of result columns
COLUMNS = 8

# Limit number for the results
LIMIT = 250000

# Result output format
RESULT_FORMAT = "%6d"


def main():
    sys.stdout.write("Fibonacci numbers:\n")
    fibonacci()


def fibonacci():
    fibo_index = 0
    current    = 1
    previous   = 0
    while LIMIT - previous >= current:
        (current, previous) = (
            (fibo_index, 0) if fibo_index < 2 else (current + previous, current)
        )
    
        fibo_index = columns.print_column(COLUMNS, RESULT_FORMAT,
                                          current, fibo_index)
    columns.finish_column(COLUMNS, fibo_index)


main()
