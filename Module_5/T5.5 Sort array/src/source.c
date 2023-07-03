
#include "source.h"

/**
 * \brief Compares two values pointed by the pointers
 *
 * \param p1 The address of the first value
 * \param p2 The address of the second value
 * \returns 0 The element pointed to by p1 is equivalent to the element pointed to by p2
 * \returns <0 The element pointed to by p1 goes before the element pointed to by p2
 * \returns >0 The element pointed to by p1 goes after the element pointed to by p2
 */
int compare_ascending(const void *p1, const void *p2)
{
    if (*(int*)p1 < *(int*)p2){
        return -1;
    }
    else if (*(int*)p1 > *(int*)p2){
        return 1;
    }
    else{
        return 0;
    }
}

/**
 * \brief Sorts an integer array in ascending order
 *
 * \param array The array to be sorted
 * \param size The number of elements in the array
 */
void sort(int *array, int size)
{
    int i, j,min;
    for (i = 0; i < size - 1; i++){
        min = i;
        for (j = i + 1; j < size; j++){
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
    
}
