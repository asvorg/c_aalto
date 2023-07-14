#include "filebasics.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * \brief Print the given text file to the standard output stream.
 * 
 * \param filename The name of the file
 * \return The number of characters printed or -1 if file opening or reading 
 *         fails.
 */
int print_file_and_count(const char* filename) {

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
        printf("%c", c);
        count++;
    }
    fclose(file);
    return count;
	
}

/**
 * \brief Compares two files and returns the first line that differ
 *        in the two files, concatenated together, separated by four dashes, on
 *        different lines.      
 * 
 * \param file1 The name of the first file
 * \param file2 The name of the second file
 * 
 * \note You can assume that lines are not longer than 1000 characters.
 * 
 * \return A dynamically allocated string that contains the first different 
 *         lines in the files. An example string is 
 * 
 *            printf("Hello world!\n");
 *       ----
 *            printf("Hello world\n");
 * \returns NULL if the files are equal or if either one of the 
            files ends.
 */
char* difference(const char* file1, const char* file2) {
    FILE* f1 = fopen(file1, "r");
    FILE* f2 = fopen(file2, "r");
    if (f1 == NULL || f2 == NULL) {
        fprintf(stderr, "Could not open file %s or %s\n", file1, file2);
        return NULL;
    }

    char* l1 = malloc(1000);
    char* l2 = malloc(1000);
    int l = 1;
    while (true) {
        if (fgets(l1, 1000, f1) == NULL) {
            break;
        }
        if (fgets(l2, 1000, f2) == NULL) {
            break;
        }
        if (strcmp(l1, l2) != 0) {
            char* res = malloc(2000);
            sprintf(res, "%s----\n%s", l1, l2);
            free(l1);
            free(l2);
            fclose(f1);
            fclose(f2);
            return res;
        }
        l++;
    }
    free(l1);
    free(l2);
    fclose(f1);
    fclose(f2);
    return NULL;
	
}
