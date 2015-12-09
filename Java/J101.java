public class J101
{
    public static void main(String[] argv)
    {
        for (int multiplicand = 1; multiplicand <= 10; ++multiplicand)
        {
            for (int multiplicator = 1; multiplicator <= 10; ++multiplicator)
            {
                int result = multiplicator * multiplicand;
                System.out.printf("%d x %d = %d\n", multiplicator, multiplicand, result);
            }
            System.out.println();
        }
    }
}

