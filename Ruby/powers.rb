#!/usr/bin/ruby

require "./columns"

# Number of result columns
$COLUMNS = 8

# Result output format
$RESULT_FORMAT = "%8d"

# Limit number for the results
LIMIT = 999999

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


def powers(factor)
  $stdout.print("Powers of %d\n" % factor)
  number = factor
  max    = LIMIT
  $stdout.print($RESULT_FORMAT % number)
  result_counter = 1

  while number <= max:
    number *= factor
    result_counter = print_column(number, result_counter)
  end
  finish_column(result_counter)
end


def main()
  FACTOR_LIST.each do |factor|
    powers(factor)
  end
end


main()

