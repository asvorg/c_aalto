#include "bit_sequence.h"
#include <stdio.h>

/* Feel free to modify this function to test different things */

int main(void)
{
    /* op_bit_get_sequence tests */
    printf("\n*** Testing your op_bit_get_sequence function..\n");

    printf("Getting sequence... Should be 0x4d, was 0x%02X\n", op_bit_get_sequence(0x55aa55aa, 0x00133026));

    printf("Getting sequence... Should be 0x00, was 0x%02X\n", op_bit_get_sequence(0x55aa55aa, 0x00000000));

    for (int i = 0; i < 32; i++) {
        printf("Getting sequence... Should be 0x01, was 0x%02X\n", op_bit_get_sequence(0x00000001, 1 << i));
    }

    return 0;
}
