/* Modify the program so that it will print even-numbers in reverse order:
 *   value of a is now 8
 *   value of a is now 6
 *   value of a is now 4
 * down to zero.
 */

#include <stdio.h>

int main(void)
{
    int a ;
    for (a = 8;; a--) {
            if (a % 2 == 1)
            continue;
        printf("value of a is now %d\n", a);
        if (a == 0)
            break;
    }

    return 0;
}
