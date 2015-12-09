#!/usr/bin/python

import sys

def print_column(columns, result_format, result, result_counter):
    if result_counter % columns != 0:
        sys.stdout.write(" ")
    result_counter += 1
    sys.stdout.write(result_format % (result))
    if result_counter % columns == 0:
        sys.stdout.write("\n")
    return result_counter


def finish_column(columns, result_counter):
    if result_counter % columns != 0:
        sys.stdout.write("\n")

