#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * \brief Combines one 2-bit number in argument a with a 6-bit number in argument b,
 * 		  and returns a string of a byte of which 6 left most bits are of the 
 * 		  bits of b, and 2 right most bits are the bits of a. 
 * 
 * \details This function get two binary numbers as parameters, a that has 2 bits
 * 			and b that has 6 bits. The function should combine the two numbers 
 * 			in a way that the leftmost six bits are the bits from b, and the last
 * 			two bits are the bits from a. Then, the function should write the binary
 * 			number to the given string, str.
 * 			
 * 			For example, given a = 3 (binary 11) and b = 44 (binary 101100), 
 * 			after the function is called, str should contain the string "10110011".
 * 
 * \param a A 2-bit integer (it is always masked with 0x03)
 * \param b A 6-bit integer (it is always masked with 0x3F)
 * \param str The binary string formed by combining a and b.
 * 
 * \note In your implementation, do not write to stdout to check the functionality.
 *       You should use my_tests function to print and check the functionality 
 *       of your implementation.
 */
void combine_to_string(unsigned char a, unsigned char b, char* str) {
	//TODO: implement your function here!
	for (int i = 0; i < 8; i++) {
		str[i] = '0';
	}
	for (int i = 0; i < 2; i++) {
		if (a & (1 << i)) {
			str[7 - i] = '1';
		}
	}
	for (int i = 0; i < 6; i++) {
		if (b & (1 << i)) {
			str[5 - i] = '1';
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
	unsigned char test_a = 3;
	unsigned char test_b = 44;
	char test_str[9];
	combine_to_string(test_a, test_b, test_str);
	printf("%s\n", test_str);
	test_a = 2;
	test_b = 62;
	combine_to_string(test_a, test_b, test_str);
	printf("%s\n", test_str);
	test_a = 3;
	test_b = 63;
	combine_to_string(test_a, test_b, test_str);
	printf("%s\n", test_str);
	test_a = 0;
	test_b = 0;
	combine_to_string(test_a, test_b, test_str);
	printf("%s\n", test_str);
	

	
}

int main(void) {
	/* You may implement your own tests in my_tests function */
	my_tests();
}
