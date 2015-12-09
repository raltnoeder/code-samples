public class Factorials
{
    // Number of result columns
    final public static int COLUMNS = 4;

    // Limit number for the results
    final public static int LIMIT = 999999999;

    // Result output format
    final public static String RESULT_FORMAT = "%9d";

    // Formatter for the output of results in columns
    private Columns output;


    public static void main(String[] arg_values)
    {
        Factorials factInstance = new Factorials();
        System.out.println("factorials:");
        factInstance.calculate();

        System.out.println();
    }

    public Factorials()
    {
        output = new Columns(COLUMNS, RESULT_FORMAT);
    }

    public void calculate()
    {
        int factor = 1;

        for (int result = 1; Factorials.LIMIT / result >= factor; ++factor)
        {
            result *= factor;
            output.printColumn(result);
        }
        output.finishColumn();
    }
}
