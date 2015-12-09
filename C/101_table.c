#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    for (int multiplicator = 1; multiplicator <= 10; ++multiplicator)
    {
        for (int multiplicand = 1; multiplicand <= 10; ++multiplicand)
        {
            int result = multiplicator * multiplicand;
            fprintf(stdout, "%4d", result);
        }
        fputc('\n', stdout);
    }

    return EXIT_SUCCESS;
}

