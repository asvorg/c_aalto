#include "stringsplit.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

	char** res = NULL;
	int count = 0;
	char* copy = malloc(sizeof(char) * (strlen(str) + 1));
	strcpy(copy, str);
	const char* limiter = split;
	char* tok = strtok(copy, limiter);
	while (tok != NULL) {
		*tok = '\0';

		count++;
		res = realloc(res, sizeof(char*) * count);
		res[count - 1] = malloc((strlen(tok) + 1) * sizeof(char));
		strcpy(res[count - 1], tok);
		copy = copy + strlen(tok) + strlen(limiter);
		tok = strtok(NULL, limiter);
	}
	count++;
	res = realloc(res, sizeof(char*) * count);
	res[count - 1] = NULL;
	free(copy);
	return res;


}
/**
 * \brief Prints string parts that are split with split_string function.
 * 
 * \param split_string An array of strings returned by split_string function.
 */
void print_split_string(char** split_string) {
	for (int i = 0; split_string[i] != NULL; i++) {
		printf("%s\n", split_string[i]);
	}
}

/**
 * \brief Releases dynamically allocated string parts by split_string function.
 * 
 * \param split_string An array of strings returned by split_string function.
 */
void free_split_string(char** split_string) {
	for (int i = 0; split_string[i] != NULL; i++) {
		free(split_string[i]);
	}
	free(split_string);
	
}
