#include <stdio.h>
#include <string.h>
#include "source.h"

// can be used for checking what the array looks like
void print_array(int *ar, int s)
{
    int i;
    for (i = 0; i < s-1; i++) printf("%d, ", ar[i]);
    printf("%d\n", ar[i]);
}

int main()
{
    /* Sort. Implement a function to print
     * the resulting array to see that it really works */ 
    //fill the array with 100 numbers in random order
    int arr[1000000];
    int i;
    for (i = 0; i < 1000000; i++) arr[i] = (i * 17 + 13) % 1000000;
    sort(arr, 1000000);
    print_array(arr, 1000000);
    
    return 0;
}
