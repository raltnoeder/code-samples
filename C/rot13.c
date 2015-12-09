#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static const char *DEFAULT_NAME = "rot13";

typedef enum
{
    INPUT_CHAR,
    OUTPUT_CHAR,
    CHAR_SELECTOR_SIZE
}
char_selector;

static const size_t CHAR_COUNT = ((size_t) ((unsigned char) ~0)) + 1;

static const unsigned char ROT_TABLE[][2] =
{
    { 'a', 'n' },
    { 'b', 'o' },
    { 'c', 'p' },
    { 'd', 'q' },
    { 'e', 'r' },
    { 'f', 's' },
    { 'g', 't' },
    { 'h', 'u' },
    { 'i', 'v' },
    { 'j', 'w' },
    { 'k', 'x' },
    { 'l', 'y' },
    { 'm', 'z' },
    { 'n', 'a' },
    { 'o', 'b' },
    { 'p', 'c' },
    { 'q', 'd' },
    { 'r', 'e' },
    { 's', 'f' },
    { 't', 'g' },
    { 'u', 'h' },
    { 'v', 'i' },
    { 'w', 'j' },
    { 'x', 'k' },
    { 'y', 'l' },
    { 'z', 'm' },
    { 'A', 'N' },
    { 'B', 'O' },
    { 'C', 'P' },
    { 'D', 'Q' },
    { 'E', 'R' },
    { 'F', 'S' },
    { 'G', 'T' },
    { 'H', 'U' },
    { 'I', 'V' },
    { 'J', 'W' },
    { 'K', 'X' },
    { 'L', 'Y' },
    { 'M', 'Z' },
    { 'N', 'A' },
    { 'O', 'B' },
    { 'P', 'C' },
    { 'Q', 'D' },
    { 'R', 'E' },
    { 'S', 'F' },
    { 'T', 'G' },
    { 'U', 'H' },
    { 'V', 'I' },
    { 'W', 'J' },
    { 'X', 'K' },
    { 'Y', 'L' },
    { 'Z', 'M' }
};

static void init_char_table(unsigned char *char_table);
static void rot13_codec(unsigned char *data, unsigned char *char_table);


int main(int arg_count, char *arg_values[])
{
    int ret_code = EXIT_FAILURE;

    const char *program_name = DEFAULT_NAME;
    if (arg_count >= 1)
    {
        program_name = (const char *) arg_values[0];
    }

    if (arg_count == 2)
    {
        unsigned char *char_table = malloc(CHAR_COUNT);
        if (char_table != NULL)
        {
            init_char_table(char_table);
            // Encode/Decode the first command line argument
            rot13_codec((unsigned char *) arg_values[1], char_table);
            // Print the result
            fputs(arg_values[1], stdout);
            fputc('\n', stdout);
            ret_code = EXIT_SUCCESS;
        }
        else
        {
            fputs("Out of memory\n", stderr);
        }
    }
    else
    {
        fprintf(stderr, "Syntax: %s <data>\n", program_name);
    }

    return ret_code;
}


static void rot13_codec(unsigned char *data, unsigned char *char_table)
{
    size_t data_length = strlen((char *) data);
    for (size_t data_index = 0; data_index < data_length; ++data_index)
    {
        unsigned char input_char  = data[data_index];
        unsigned char output_char = char_table[input_char];

        data[data_index] = output_char;
    }
}


static void init_char_table(unsigned char *char_table)
{
    for (size_t char_index = 0; char_index < CHAR_COUNT; ++char_index)
    {
        unsigned char table_char = (unsigned char) char_index;
        char_table[table_char] = table_char;
    }

    size_t rot_table_size = sizeof (ROT_TABLE) / CHAR_SELECTOR_SIZE;
    for (size_t table_index = 0; table_index < rot_table_size; ++table_index)
    {
        unsigned char input_char  = ROT_TABLE[table_index][INPUT_CHAR];
        unsigned char output_char = ROT_TABLE[table_index][OUTPUT_CHAR];

        char_table[input_char] = output_char;
    }
}
