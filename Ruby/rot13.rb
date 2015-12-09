#!/usr/bin/ruby

ROT_TABLE = [
    ["a", "n"],
    ["b", "o"],
    ["c", "p"],
    ["d", "q"],
    ["e", "r"],
    ["f", "s"],
    ["g", "t"],
    ["h", "u"],
    ["i", "v"],
    ["j", "w"],
    ["k", "x"],
    ["l", "y"],
    ["m", "z"],
    ["n", "a"],
    ["o", "b"],
    ["p", "c"],
    ["q", "d"],
    ["r", "e"],
    ["s", "f"],
    ["t", "g"],
    ["u", "h"],
    ["v", "i"],
    ["w", "j"],
    ["x", "k"],
    ["y", "l"],
    ["z", "m"],
    ["A", "N"],
    ["B", "O"],
    ["C", "P"],
    ["D", "Q"],
    ["E", "R"],
    ["F", "S"],
    ["G", "T"],
    ["H", "U"],
    ["I", "V"],
    ["J", "W"],
    ["K", "X"],
    ["L", "Y"],
    ["M", "Z"],
    ["N", "A"],
    ["O", "B"],
    ["P", "C"],
    ["Q", "D"],
    ["R", "E"],
    ["S", "F"],
    ["T", "G"],
    ["U", "H"],
    ["V", "I"],
    ["W", "J"],
    ["X", "K"],
    ["Y", "L"],
    ["Z", "M"]
]

class Rot13
  
  @char_table = nil


  def initialize()
    @char_table = Array.new(256)
    index = 0
    while index < 256
      @char_table[index] = index.chr()
      index += 1
    end
    for item in ROT_TABLE:
      input_char, output_char = item
      table_index = input_char[0].ord()
      @char_table[table_index] = output_char
    end
  end


  def codec(data)
    index = 0
    data_length = data.length()
    while index < data_length
      input_char = data[index]
      table_index = input_char.ord()
      output_char = @char_table[table_index]
      data[index] = output_char
      index += 1
    end
    return data
  end

end


def main()
  if ARGV.length() == 1
    data = ARGV[0].dup()
    rot = Rot13.new()
    data = rot.codec(data)
    $stdout.write("%s\n" % data)
  else
    $stderr.print("Syntax: rot13.rb <data>\n")
  end
end


main()

