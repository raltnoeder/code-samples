#!/usr/bin/ruby

def print_column(result, result_counter)
  if result_counter % $COLUMNS != 0
    $stdout.print(" ")
  end
  result_counter = result_counter + 1
  $stdout.print($RESULT_FORMAT % result)
  if result_counter % $COLUMNS == 0
    $stdout.print("\n")
  end
  return result_counter
end


def finish_column(result_counter)
  remainder = result_counter % $COLUMNS
  if remainder != 0
    $stdout.print("\n")
  end
end

