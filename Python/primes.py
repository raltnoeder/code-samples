#!/usr/bin/python

import sys
import columns


class Primes(object):

    # Limit number for Eratosthenes' sieve
    SIEVE_SIZE = 500

    # Number of result columns
    COLUMNS = 8

    # Output format of the results
    RESULT_FORMAT = "%5d"

    sieve = None


    def __init__(self):
        self.sieve = Primes.SIEVE_SIZE * [0]


    def calculate_primes(self):
        number = 2
        while number * number < Primes.SIEVE_SIZE:
            if self.sieve[number] == 0:
                max_factor = Primes.SIEVE_SIZE / number
                factor = 2
                while factor < max_factor:
                    product = number * factor
                    self.sieve[product] = 1
                    factor += 1
            number += 1


    def print_results(self):
        result_counter = 0
        number = 1
        while number < Primes.SIEVE_SIZE:
            if self.sieve[number] == 0:
                result_counter = columns.print_column(Primes.COLUMNS, Primes.RESULT_FORMAT,
                                                      number, result_counter)
            number += 1
        columns.finish_column(Primes.COLUMNS, result_counter)
        sys.stdout.write("%d prime numbers\n" % (result_counter))


def main():
    sys.stdout.write("Prime numbers\n")
    sys.stdout.write("(Sieve of Eratosthenes)\n")

    instance = Primes()
    instance.calculate_primes()
    instance.print_results()


main()

