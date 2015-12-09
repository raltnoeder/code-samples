#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <columns.h>

// Number of result columns
const uint8_t COLUMNS = 8;

// Result output format
const char *RESULT_FORMAT = "%6u";

// Limit number for the results
static const uint32_t LIMIT = 999999;

static const uint32_t FACTOR_LIST[] =
{
    2,
    3,
    5,
    7,
    11,
    13,
    17,
    19,
    23,
    29
};

static void powers(uint32_t factor);


int main(void)
{
    size_t max_index = sizeof (FACTOR_LIST) / sizeof (uint32_t);
    for (size_t index = 0; index < max_index; ++index)
    {
        powers(FACTOR_LIST[index]);
    }

    return EXIT_SUCCESS;
}


static void powers(uint32_t factor)
{
    fprintf(stdout, "Powers of %u:\n", (unsigned int) factor);

    uint32_t number = factor;
    uint32_t max    = LIMIT / factor;

    fprintf(stdout, RESULT_FORMAT, (unsigned int) factor);
    uint32_t result_counter = 1;

    while (number <= max)
    {
        number *= factor;
        print_column(stdout, number, &result_counter);
    }
    finish_column(stdout, &result_counter);
}
