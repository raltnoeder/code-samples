#!/usr/bin/ruby

def main()
  multiplicator = 1
  while multiplicator <= 10
    multiplicand = 1
    while multiplicand <= 10
      result = multiplicator * multiplicand
      $stdout.print("%4d" % result)
      multiplicand += 1
    end
    $stdout.print("\n")
    multiplicator += 1
  end
end


main()

