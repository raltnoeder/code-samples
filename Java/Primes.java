public class Primes
{
    // Limit number for Eratosthenes' sieve
    final public static int SIEVE_SIZE = 500;

    // Number of result columns
    final public static int COLUMNS = 8;

    // Output format of the results
    final public static String RESULT_FORMAT = "%5d";

    // Eratosthenes' sieve
    private byte[] sieve;

    // Formatter for the output of results in columns
    private Columns output;


    public static void main(String[] argv)
    {
        System.out.println("Prime numbers");
        System.out.println("(Sieve of Eratosthenes)");

        Primes primesInstance = new Primes();
        primesInstance.calculate();
        primesInstance.printResults();
    }

    public Primes()
    {
        output = new Columns(COLUMNS, RESULT_FORMAT);
        sieve = new byte[SIEVE_SIZE];
    }

    public void calculate()
    {
        for (int number = 2; SIEVE_SIZE / number > number; ++number)
        {
            if (sieve[number] == 0)
            {
                int maxFactor = SIEVE_SIZE / number;
                for (int factor = 2; factor < maxFactor; ++factor)
                {
                    int product = number * factor;
                    sieve[product] = 1;
                }
            }
        }
    }

    public void printResults()
    {
        for (int number = 1; number < Primes.SIEVE_SIZE; ++number)
        {
            if (sieve[number] == 0)
            {
                output.printColumn(number);
            }
        }
        output.finishColumn();
        System.out.printf("%d prime numbers\n", output.getResultCount());
    }
}
