public class Fibonacci
{
    // Number of result columns
    final public static int COLUMNS = 8;

    // Limit number for the results
    final public static int LIMIT = 250000;

    // Result output format
    final public static String RESULT_FORMAT = "%6d";

    // Formatter for the output of results in columns
    private Columns output;


    public static void main(String[] argv)
    {
        Fibonacci fiboInstance = new Fibonacci();
        System.out.println("Fibonacci numbers");
        fiboInstance.calculate();

        System.out.println();
    }

    public Fibonacci()
    {
        output = new Columns(COLUMNS, RESULT_FORMAT);
    }

    public void calculate()
    {
        int previous = 0;
        int current  = 1;

        for (int fiboIndex = 0; LIMIT - previous >= current; ++fiboIndex)
        {
            int result;
            if (fiboIndex < 2)
            {
                result = fiboIndex;
            }
            else
            {
                result   = previous + current;
                previous = current;
                current  = result;
            }

            output.printColumn(result);
        }
        output.finishColumn();
    }
}
