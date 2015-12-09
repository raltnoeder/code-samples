public class J101Table
{
    public static void main(String[] argv)
    {
        for (int multiplicator = 1; multiplicator <= 10; ++multiplicator)
        {
            for (int multiplicand = 1; multiplicand <= 10; ++multiplicand)
            {
                int result = multiplicator * multiplicand;
                System.out.printf("%4d", result);
            }
            System.out.println();
        }
    }
}

