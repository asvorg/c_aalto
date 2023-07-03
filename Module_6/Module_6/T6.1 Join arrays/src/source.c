
#include "source.h"
#include <stdlib.h>

/**
 * \brief Joins 3 arrays into a new dynamically allocated array
 *
 * \param n1 The number of elements in array a1
 * \param a1 The array 1 composed of n1 elements
 * \param n2 The number of elements in array a2
 * \param a2 The array 2 composed of n2 elements
 * \param n3 The number of elements in array a3
 * \param a3 The array 3 composed of n3 elements
 * \return a pointer to the dynamically allocated array
 *
 * \note The caller is responsible for deallocating the allocated array
 */
int *join_arrays(unsigned int n1,
                 const int *a1,
                 unsigned int n2,
                 const int *a2,
                 unsigned int n3,
                 const int *a3)
{
    int len = n1 + n2 + n3;
    int *res = malloc(len * sizeof(int));
    int len_n1 = n1;
    int len_n2 = n2;
    int len_n3 = n3;
    for (int i = 0; i < len_n1; i++)
    {
        res[i] = a1[i];
    }
    for (int i = 0; i < len_n2; i++)
    {
        res[i + n1] = a2[i];
    }
    for (int i = 0; i < len_n3; i++)
    {
        res[i + n1 + n2] = a3[i];
    }
    return res;
}
