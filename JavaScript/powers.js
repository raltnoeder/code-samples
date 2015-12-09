// Number of result columns
var COLUMNS = 8;

// Limit number for the results
var LIMIT = 999999;

// Result field width
var RESULT_WIDTH = 6;

var factorList = new Array();
factorList.push(2);
factorList.push(3);
factorList.push(5);
factorList.push(7);
factorList.push(11);
factorList.push(13);
factorList.push(17);
factorList.push(19);
factorList.push(23);
factorList.push(29);


function powers(factor)
{
	write("Powers of " + factor + ":\n");

    var number = factor;
    var max    = LIMIT / factor;

    var resultCounter = printColumn(RESULT_WIDTH, factor, 0);

    while (number <= max)
    {
        number *= factor;
        resultCounter = printColumn(RESULT_WIDTH, number, resultCounter);
    }
    finishColumn(resultCounter);
}


function main()
{
	for (var index = 0; index < factorList.length; ++index)
    {
        powers(factorList[index]);
    }
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
