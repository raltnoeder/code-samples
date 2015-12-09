#include <columns.h>

// Number of result columns
extern const uint8_t COLUMNS;

// Result output format
extern const char *RESULT_FORMAT;


void print_column(FILE *output, unsigned int result, uint32_t *result_counter_ref)
{
    uint32_t result_counter = *result_counter_ref;

    if (result_counter % COLUMNS != 0)
    {
        fputc(' ', output);
    }
    fprintf(output, RESULT_FORMAT, result);
    ++result_counter;
    if (result_counter % COLUMNS == 0)
    {
        fputc('\n', output);
    }

    *result_counter_ref = result_counter;
}


void finish_column(FILE *output, uint32_t *result_counter_ref)
{
    if (*result_counter_ref % COLUMNS != 0)
    {
        fputc('\n', output);
    }
}

