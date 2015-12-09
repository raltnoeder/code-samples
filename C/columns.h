#ifndef COLUMNS_H
#define COLUMNS_H

#include <stdio.h>
#include <stdint.h>

void print_column(FILE *output, unsigned int result, uint32_t *result_counter_ref);

void finish_column(FILE *output, uint32_t *result_counter_ref);

#endif  /* COLUMNS_H */
