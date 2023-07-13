#include "stringsplit.h"

#include <stdio.h>


/**
 * \brief Splits a string into its parts, and returns a dynamically allocated  
 *        array of strings that are dynamically allocated.
 * 
 * \details For example called with "Test string split" and " ",
 *          the function returns ["Test", "string", "split", NULL].
 *          
 *          Or called with "Another - test" and " - ",
 *          returns ["Another", "test", NULL].
 * 
 * \param str The null-terminated string to split.
 * \param split The token string to split str with.
 * \return An array of strings that contains parts of str in each of 
 *         strings excluding the split.      
 */
char** split_string(const char* str, const char* split) {
	
	return NULL;
}

/**
 * \brief Prints string parts that are split with split_string function.
 * 
 * \param split_string An array of strings returned by split_string function.
 */
void print_split_string(char** split_string) {
	
}

/**
 * \brief Releases dynamically allocated string parts by split_string function.
 * 
 * \param split_string An array of strings returned by split_string function.
 */
void free_split_string(char** split_string) {
	
}
