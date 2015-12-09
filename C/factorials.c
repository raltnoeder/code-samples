#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <columns.h>

// Number of result columns
const uint8_t COLUMNS = 4;

// Result output format
const char *RESULT_FORMAT = "%9u";

// Limit number for the results
static const uint32_t LIMIT = 999999999;


static void factorials(void);


int main(void)
{
    fputs("factorials:\n", stdout);
    factorials();

    return 0;
}


static void factorials(void)
{
    uint32_t factor = 1;

    uint32_t result_counter = 0;
    uint32_t *result_counter_ref = &result_counter;
    for (uint32_t result = 1; LIMIT / result >= factor; ++factor)
    {
        result *= factor;
        print_column(stdout, result, result_counter_ref);
    }
    finish_column(stdout, result_counter_ref);
}
