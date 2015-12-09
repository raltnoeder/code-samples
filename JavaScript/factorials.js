// Number of result columns
var COLUMNS = 4;

// Limit number for the results
var LIMIT = 999999999;

// Result field width
var RESULT_WIDTH = 9;


function main()
{
    write("factorials:\n");
    factorials();
}


function factorials()
{
    var factor = 1;

    var resultCounter = 0;
    for (result = 1; LIMIT / result >= factor; ++factor)
    {
        result *= factor;
        resultCounter = printColumn(RESULT_WIDTH, result, resultCounter);
    }
    finishColumn(resultCounter);
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
