#include "hexread.h"
#include <stdio.h>


/**
 * \brief Prints the given file as hexdump.
 * 
 * \details The function outputs each byte in the file as a two character hexadecimal 
 *          number. 
 *
 *    - If a byte is less than ``0x10``, then the output should have ``0`` in 
 *      front of the number. 
 *    
 *    - Each line must have maximum of 16 hexadecimal numbers with a space between 
 *      them.
 * 
 *    - Only 16 hexadecimal numbers must be printed in one line and there should 
 *      be a space after the last value.After printing 16 hex values, the next 
 *      byte should be printed on the next line. 
 *
 *    - If the end-of-file indicator is set before a line ends, the dump should 
 *      end.
 * 
 * \param filename The name of the file to dump.
 * \return Returns the number of characters read or -1 if an error occurs when 
 *         reading the file.
 */
int file_to_hex(const char* filename) {

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
    fprintf(stderr, "Could not open file %s\n", filename);
    return -1;
    }

    int size;

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file); 

    int count = 0;

    for (int i = 0; i < size; i++) {
        int c = fgetc(file);
        if (c == EOF) {
            break;
        }
        printf("%02x ", c);
        count++;
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    fclose(file);
    return count;
}
