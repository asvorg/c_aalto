#include "filebasics.h"


/**
 * \brief Print the given text file to the standard output stream.
 * 
 * \param filename The name of the file
 * \return The number of characters printed or -1 if file opening or reading 
 *         fails.
 */
int print_file_and_count(const char* filename) {
	
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
	
}
