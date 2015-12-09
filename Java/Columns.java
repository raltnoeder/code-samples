public class Columns
{
    private int resultCounter;

    // Number of result columns
    final private int COLUMNS;

    // Result output format
    final private String FORMAT;


    public Columns(int columns, String resultFormat)
    {
        resultCounter = 0;
        COLUMNS       = columns;
        FORMAT        = resultFormat;
    }


    public void printColumn(int result)
    {
        if (resultCounter % COLUMNS != 0)
        {
            System.out.print(' ');
        }
        ++resultCounter;
        System.out.printf(FORMAT, result);
        if (resultCounter % COLUMNS == 0)
        {
            System.out.println();
        }
    }


    public void finishColumn()
    {
        if (resultCounter % COLUMNS != 0)
        {
            System.out.println();
        }
    }


    public int getResultCount()
    {
        return resultCounter;
    }
}
