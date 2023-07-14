#include <stdio.h>
#include <string.h>
#include "hexread.h"


int main(void)
{
    if (file_to_hex("hexread.c") == -1) {
         fprintf(stderr, "Could not open main.c\n");
    }
}
