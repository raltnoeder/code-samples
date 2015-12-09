// Limit number for Eratosthenes' sieve
var SIEVE_SIZE = 500;

// Number of result columns
var COLUMNS = 8;

// Result field width
var RESULT_WIDTH = 5;


function Primes()
{
    this.sieve        = new Array(SIEVE_SIZE);
    this.calculate    = PrimesCalculate;
    this.printResults = PrimesPrintResults;
    
    for (var number = 0; number < SIEVE_SIZE; ++number)
    {
        this.sieve[number] = 0;
    }
}


function PrimesCalculate()
{
    for (var number = 2; number * number < SIEVE_SIZE; ++number)
    {
        if (this.sieve[number] == 0)
        {
            var maxFactor = SIEVE_SIZE / number;
            for (var factor = 2; factor < maxFactor; ++factor)
            {
                var product = number * factor;
                this.sieve[product] = 1;
            }
        }
    }
}


function PrimesPrintResults()
{
    var resultCounter = 0;
    for (var number = 1; number < SIEVE_SIZE; ++number)
    {
        if (this.sieve[number] == 0)
        {
            resultCounter = printColumn(RESULT_WIDTH, number, resultCounter);
        }
    }
    finishColumn(resultCounter);
    write(resultCounter + " prime numbers\n");
}


function main()
{
    write("Prime numbers\n");
    write("(Sieve of Eratosthenes)\n");
    
    var instance = new Primes();
    instance.calculate();
    instance.printResults();
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


main()
