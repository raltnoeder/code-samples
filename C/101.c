#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    for (int multiplicand = 1; multiplicand <= 10; ++multiplicand)
    {
        for (int multiplicator = 1; multiplicator <= 10; ++multiplicator)
        {
            int result = multiplicator * multiplicand;
            fprintf(stdout, "%d x %d = %d\n", multiplicator, multiplicand, result);
        }
        fputc('\n', stdout);
    }

    return EXIT_SUCCESS;
}

