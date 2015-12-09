#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <columns.h>

// Number of result columns
const uint8_t COLUMNS = 8;

// Output format of the results
const char *RESULT_FORMAT = "%5u";

// Limit number for Eratosthenes' sieve
static const uint32_t SIEVE_SIZE = 500;

static void initialize(unsigned char *sieve);
static void calculate_primes(unsigned char *sieve);
static void print_primes(unsigned char *sieve);


int main(void)
{
    int ret_code = EXIT_FAILURE;

    fputs("Prime numbers\n", stdout);
    fputs("(Sieve of Eratosthenes)\n", stdout);

    unsigned char *sieve = malloc(sizeof (unsigned char) * SIEVE_SIZE);
    if (sieve != NULL)
    {
        initialize(sieve);

        calculate_primes(sieve);
        print_primes(sieve);

        free(sieve);
        ret_code = EXIT_SUCCESS;
    }
    else
    {
        fputs("Out of memory\n", stderr);
    }

    return ret_code;
}


static void calculate_primes(unsigned char *sieve)
{
    for (uint32_t number = 2; number * number < SIEVE_SIZE; ++number)
    {
        if (sieve[number] == 0)
        {
            uint32_t max_factor = SIEVE_SIZE / number;
            for (uint32_t factor = 2; factor < max_factor; ++factor)
            {
                uint32_t product = number * factor;
                sieve[product] = 1;
            }
        }
    }
}


static void print_primes(unsigned char *sieve)
{
    uint32_t result_counter = 0;
    for (uint32_t number = 1; number < SIEVE_SIZE; ++number)
    {
        if (sieve[number] == 0)
        {
            print_column(stdout, number, &result_counter);
        }
    }
    finish_column(stdout, &result_counter);
    fprintf(stdout, "%u prime numbers\n", (unsigned int) result_counter);
}


static void initialize(unsigned char *sieve)
{
    memset(sieve, 0, sizeof (unsigned char) * SIEVE_SIZE);
}
