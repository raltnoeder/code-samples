#!/usr/bin/ruby

require "./columns"

# Number of result columns
$COLUMNS = 8

# Result output format
$RESULT_FORMAT = "%6d"

# Limit number for the results
LIMIT = 250000


def main()
  $stdout.print("Fibonacci numbers:\n")
  fibonacci()
end


def fibonacci()
  fibo_index = 0
  current    = 1
  previous   = 0
  while LIMIT - previous >= current
    if fibo_index < 2
      current, previous = fibo_index, 0
    else
      current, previous = current + previous, current
    end
    fibo_index = print_column(current, fibo_index)
  end
  finish_column(fibo_index)
end


main()

