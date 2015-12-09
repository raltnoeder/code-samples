#!/usr/bin/ruby

require "./columns"

# Number of result columns
$COLUMNS = 4

# Result output format
$RESULT_FORMAT = "%9d"

# Limit number for the results
LIMIT = 999999999

def main()
  $stdout.write("factorials:\n")
  factorials()
end


def factorials()
  factor = 1

  result_counter = 0
  result = 1
  while LIMIT / result > factor
    result *= factor
    result_counter = print_column(result, result_counter)
    factor += 1
  end
  finish_column(result_counter)
end

main()

