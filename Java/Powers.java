public class Powers
{
    // Number of result columns
    final public static int COLUMNS = 8;

    // Limit number for the results
    final public static int LIMIT = 999999;

    // Result output format
    final public static String RESULT_FORMAT = "%6d";

    final public static int[] FACTOR_LIST =
    {
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
    };

    // Formatter for the output of results in columns
    private Columns output;


    public static void main(String[] argv)
    {
        Powers powersInstance = new Powers();
        for (int index = 0; index < Powers.FACTOR_LIST.length; ++index)
        {
            powersInstance.powersOf(Powers.FACTOR_LIST[index]);
        }
    }

    public Powers()
    {
        output = new Columns(COLUMNS, RESULT_FORMAT);
    }

    public void powersOf(int factor)
    {
        System.out.printf("Powers of %d:\n", factor);

        int max = LIMIT / factor;

        System.out.printf(Powers.RESULT_FORMAT, factor);
        int resultCounter = 0;

        int number = factor;
        while (number <= max)
        {
            number *= factor;
            output.printColumn(number);
        }
        output.finishColumn();
    }
}
