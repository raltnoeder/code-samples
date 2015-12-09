// Number of result columns
var COLUMNS = 8

// Limit number for the results
var LIMIT = 250000;

// Result field width
var RESULT_WIDTH = 9;


function main()
{
    write("Fibonacci numbers\n");
    fibonacci();
}

function fibonacci()
{
    var previous = 0;
    var current  = 1;

    var fiboIndex = 0;
    while (LIMIT - previous >= current)
    {
        var result;
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

        fiboIndex = printColumn(RESULT_WIDTH, result, fiboIndex);
    }
    finishColumn(fiboIndex);
}

function printColumn(width, result, resultCounter)
{
    if (resultCounter % COLUMNS != 0)
    {
        write(" ");
    }
    ++resultCounter;
    printField(width, result);
    if (resultCounter % COLUMNS == 0)
    {
        write("\n");
    }
    return resultCounter;
}


function finishColumn(resultCounter)
{
    if (resultCounter % COLUMNS != 0)
    {
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


main();
