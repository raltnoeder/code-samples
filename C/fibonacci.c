#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <columns.h>

// Number of result columns
const uint8_t COLUMNS = 8;

// Result output format
const char *RESULT_FORMAT = "%6u";

// Limit number for the results
static const uint32_t LIMIT = 250000;

static void fibonacci(void);


int main(void)
{
    fputs("Fibonacci numbers\n", stdout);
    fibonacci();

    return EXIT_SUCCESS;
}


static void fibonacci(void)
{
    uint32_t previous = 0;
    uint32_t current  = 1;

    uint32_t fibo_index = 0;
    while (LIMIT - previous >= current)
    {
        uint32_t result;
        if (fibo_index < 2)
        {
            result = fibo_index;
        }
        else
        {
            result   = previous + current;
            previous = current;
            current  = result;
        }

        print_column(stdout, result, &fibo_index);
    }
    finish_column(stdout, &fibo_index);
}
