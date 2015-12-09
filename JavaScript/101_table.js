function main()
{
    for (var multiplicator = 1; multiplicator <= 10; ++multiplicator)
    {
        for (var multiplicand = 1; multiplicand <= 10; ++multiplicand)
        {
            var result = multiplicator * multiplicand;
            printField(4, result);
        }
        write("\n");
    }
}


function printField(width, value)
{
    --width;
    for (var remainder = Math.floor(value / 10); remainder >= 1; remainder = Math.floor(remainder / 10))
    {
        --width;
    }
    while (width > 0)
    {
        --width;
        write(" ");
    }
    write(value);
}


main()

