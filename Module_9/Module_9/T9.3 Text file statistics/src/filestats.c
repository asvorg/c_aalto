
#include "filestats.h"
#include <ctype.h>
#include <stdio.h>
/**
 * \brief Returns the number of lines in a file. 
 * 
 * \param filename The name of the file.
 * \return The number of lines in the file, or -1 if an error occurs. 
 */
int line_count(const char* filename) {
    int cnt = 0;
	FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return -1;
    }
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        cnt++;
    }
    return cnt;
}

/**
 * \brief Returns the number of words in a file.
 * 
 * \details The function assumes that a word is formed by alphabetical characters
 *          as defined in ctype.h so that isalpha() returns nonzero value.
 * 
 *          The words are separated by a white space character as defined in 
 *          ctype.h so that isspace() returns nonzero value.
 * 
 * \param filename The name of the file.
 * \return The number of words in the file, or -1 if an error occurs.
 */
int word_count(const char* filename) {
    int cnt = 0;

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return -1;
    }
    for (int i = 0; i < 1000; i++) {
        int c = fgetc(file);
        if (c == EOF) {
            break;
        }
        if (isspace(c)) {
            cnt++;
        }
    }
    return cnt;
}
