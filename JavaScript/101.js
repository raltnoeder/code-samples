function main()
{
    for (var multiplicand = 1; multiplicand <= 10; ++multiplicand)
    {
        for (var multiplicator = 1; multiplicator <= 10; ++multiplicator)
        {
            var result = multiplicator * multiplicand;
            write(multiplicator + " x " + multiplicand + " = " + result + "\n")
        }
        write("\n")
    }
}


main()

