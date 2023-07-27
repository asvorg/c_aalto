#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/**
 * \brief Compares two integers and returns their comparison result.
 * \details This function defines the order of the elements by 
 *          returning (in a stable and transitive manner): 
 *          <0	The value pointed to by 'a' goes before the value pointed to by 'b'
 *           0	The value pointed to by 'a' is equivalent to the value pointed to by 'b'
 *          >0	The value pointed to by 'a' goes after the value pointed to by 'b'
 * 
 *          In other words, this function essentially calculates the difference
 *          of the values pointed by its arguments.
 * 
 * \param a A pointer to the integer that will be compared against the 
 *          value pointed by b.
 * \param b A pointer to the integer that will be compared against the 
 *          value pointed by a.
 * \return The comparison result
 */
int compare_ints(const void* a, const void* b) {

	int a_value = *(int*)a;
	int b_value = *(int*)b;
	if (a_value == b_value) {
		return 0;
	}
	else if (a_value < b_value) {
		return b_value - a_value;
	}
	else {
		return a_value - b_value;
	}
	
}

/**
 * \brief Calculates the median of the integers in an array.
 * 
 * \details This function calculates the median of an array of n integers.
 * 
 * \param array The array of n integers.
 * \param n The number of integer elements in the array. There will always be 
 *          odd number of elements. 
 * \return The median value
 * 
 * \note Median is the middle element of the array when it is sorted.
 *       
 *       stdlib.h has some useful functions that might help you to
 *       sort the array to find the median value. You might need 
 *       the comparison function compare_ints if you prefer to 
 *       use stdlib function for sorting the array.
 * 
 * \note In your implementation, do not write to stdout to check the functionality.
 *       You should use my_tests function to print and check the functionality 
 *       of your implementation.
 */
int median(int* array, unsigned int n) {
	unsigned int i, j,min;
    for (i = 0; i < n - 1; i++){
		//sorting copied from T5.5
        min = i;
        for (j = i + 1; j < n; j++){
            if (array[j] < array[min]){
                min = j;
            }
        }
        if (min != i){
            int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
		}
	}
	return array[n / 2];
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
	int test_array1[13] = {10,7,2,5,1,3,6,9,4,8,11,12,13};
	printf("Median of test_array1 is %d\n", median(test_array1, 13));

	int test_array2[101];
	for (int i = 0; i < 101; i++) {
		test_array2[i] = i;
	}
	//shuffle the array
	srand(time(NULL));
	for (int i = 0; i < 101; i++) {
		int j = rand() % 100;
		int temp = test_array2[i];
		test_array2[i] = test_array2[j];
		test_array2[j] = temp;
	}
	printf("Median of test_array2 is %d\n", median(test_array2, 101));
	int test_array3[3] = { 3,1,2 };
	printf("Median of test_array3 is %d\n", median(test_array3, 3));
}

int main(void) {
	/* You may implement your own tests in my_tests function */
	my_tests();
}
