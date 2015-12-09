public class Rot13
{
    final public static byte[][] ROT_TABLE =
    {
        { 'a', 'n' },
        { 'b', 'o' },
        { 'c', 'p' },
        { 'd', 'q' },
        { 'e', 'r' },
        { 'f', 's' },
        { 'g', 't' },
        { 'h', 'u' },
        { 'i', 'v' },
        { 'j', 'w' },
        { 'k', 'x' },
        { 'l', 'y' },
        { 'm', 'z' },
        { 'n', 'a' },
        { 'o', 'b' },
        { 'p', 'c' },
        { 'q', 'd' },
        { 'r', 'e' },
        { 's', 'f' },
        { 't', 'g' },
        { 'u', 'h' },
        { 'v', 'i' },
        { 'w', 'j' },
        { 'x', 'k' },
        { 'y', 'l' },
        { 'z', 'm' },
        { 'A', 'N' },
        { 'B', 'O' },
        { 'C', 'P' },
        { 'D', 'Q' },
        { 'E', 'R' },
        { 'F', 'S' },
        { 'G', 'T' },
        { 'H', 'U' },
        { 'I', 'V' },
        { 'J', 'W' },
        { 'K', 'X' },
        { 'L', 'Y' },
        { 'M', 'Z' },
        { 'N', 'A' },
        { 'O', 'B' },
        { 'P', 'C' },
        { 'Q', 'D' },
        { 'R', 'E' },
        { 'S', 'F' },
        { 'T', 'G' },
        { 'U', 'H' },
        { 'V', 'I' },
        { 'W', 'J' },
        { 'X', 'K' },
        { 'Y', 'L' },
        { 'Z', 'M' }
    };

    final public static int INPUT_CHAR  = 0;
    final public static int OUTPUT_CHAR = 1;

    private byte[] charTable;


    public static void main(String[] args)
    {
        if (args.length == 1)
        {
            Rot13 rot = new Rot13();

            byte data[] = args[0].getBytes();
            rot.codec(data);

            String output = new String(data);
            System.out.println(output);
        }
        else
        {
            System.err.println("Syntax: Rot13 <data>");
        }
    }

    public void codec(byte[] data)
    {
        for (int index = 0; index < data.length; ++index)
        {
            byte inputChar = data[index];

            int tableIndex = inputChar >= 0 ? inputChar : 127 - ((int) inputChar);
            byte outputChar = charTable[tableIndex];

            data[index] = outputChar;
        }
    }

    public Rot13()
    {
        charTable = new byte[256];
        for (int index = 0; index < 256; ++index)
        {
            byte tableChar = index < 128 ? (byte) index : (byte) (127 - index);
            charTable[index] = tableChar;
        }

        for (int index = 0; index < Rot13.ROT_TABLE.length; ++index)
        {
            byte inputChar  = Rot13.ROT_TABLE[index][Rot13.INPUT_CHAR];
            byte outputChar = Rot13.ROT_TABLE[index][Rot13.OUTPUT_CHAR];

            int tableIndex = inputChar >= 0 ? inputChar : 127 - ((int) inputChar);

            charTable[tableIndex] = outputChar;
        }
    }
}
