#!/usr/bin/ruby

require "./columns"

# Number of result columns
$COLUMNS = 8

# Result output format
$RESULT_FORMAT = "%5d"

class Primes

  # Limit number for the results
  @@LIMIT = 999999

  # Limit number for Eratosthenes' sieve
  @@SIEVE_SIZE = 500

  @sieve = nil


  def initialize()
    @sieve = Array.new(@@SIEVE_SIZE, 0)
  end


  def calculate_primes()
    number = 2
    while number * number < @@SIEVE_SIZE
      if @sieve[number] == 0
        max_factor = @@SIEVE_SIZE / number
        factor = 2
        while factor < max_factor
          product = number * factor
          @sieve[product] = 1
          factor += 1
        end
      end
      number += 1
    end
  end


  def print_results()
    result_counter = 0
    number = 1
    while number < @@SIEVE_SIZE
      if @sieve[number] == 0
        result_counter = print_column(number, result_counter)
      end
      number += 1
    end
    finish_column(result_counter)
    $stdout.print("%d prime numbers\n" % result_counter)
  end

end


def main()
  $stdout.print("Prime numbers\n")
  $stdout.print("(Sieve of Eratosthenes)\n")

  instance = Primes.new()
  instance.calculate_primes()
  instance.print_results()
end


main()

