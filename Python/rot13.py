#!/usr/bin/python

import sys

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

class Rot13(object):

    char_table = bytearray(256)


    def __init__(self):
        index = 0
        while index < 256:
            self.char_table[index] = chr(index)
            index += 1
        for item in ROT_TABLE:
            input_char, output_char = item
            table_index = ord(input_char)
            self.char_table[table_index] = output_char


    def codec(self, data):
        index = 0
        length = len(data)
        while index < length:
            input_char = data[index]
            output_char = self.char_table[input_char]
            data[index] = output_char
            index += 1


def main():
    if len(sys.argv) == 2:
        rot = Rot13()
        data = bytearray(sys.argv[1])
        rot.codec(data)
        output = str(data)
        sys.stdout.write(output + "\n")
    else:
        sys.stderr.write("Syntax: rot13.py <data>\n")


main()

