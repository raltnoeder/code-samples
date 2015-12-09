#!/usr/bin/ruby

def main()
  multiplicand = 1
  while multiplicand <= 10
    multiplicator = 1
    while multiplicator <= 10
      result = multiplicator * multiplicand
      $stdout.print("%d x %d = %d\n" % [multiplicator, multiplicand, result])
      multiplicator += 1
    end
    $stdout.print("\n")
    multiplicand += 1
  end
end


main()

