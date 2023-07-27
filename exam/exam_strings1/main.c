#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * \brief Converts all non-alphabetical characters in a null-terminated 
 *        string to lower case a, 'a'.
 * 
 * \details This function finds all non-alphabetical characters in a string and 
 *          converts these characters into lower-case 'a'. It changes the found 
 *          non-alphabetical characters inplace so that no dynamic allocation is 
 *          needed.
 * 
 * \param str The null-terminated string with some non-alphabetical characters.
 * 
 * \note stdlib provides useful character handling functions in ctype.h. 
 *       ctype.h documentation also states different character classes,  
 *       including alphabetical characters.
 * 
 * \note In your implementation, do not write to stdout to check the functionality.
 *       You should use my_tests function to print and check the functionality 
 *       of your implementation.
 */
void convert_non_alphabetical(char* str) {
	//TODO: implement your function here!
	int len = strlen(str);
	for (int c = 0; c < len; c++) {
		if (isalpha(str[c]) == 0) {
			str[c] = 'a';
		}
	}

}

/**
 * \brief conducts the tests for your implementation.
 * 
 * \details You are strongly encouraged to test your implementation
 * using this function. Try to create at least three test cases to check
 * whether your function implementation is correct.
 * 
 */
void my_tests(void) {
	// You can write your own test code here.
	char test_string1[] = "Hello World!test";
	convert_non_alphabetical(test_string1);
	printf("%s\n", test_string1);
	char test_string2[] = "!!tes£$€{{[]ttestte€€€€€€st";
	convert_non_alphabetical(test_string2);
	printf("%s\n", test_string2);
	char test_string3[] = "123test123";
	convert_non_alphabetical(test_string3);
	printf("%s\n", test_string3);

}

int main(void) {
	/* You may implement your own tests in my_tests function */
	my_tests();
}
