#include <stdlib.h>
#include <string.h>

char *my_strcat(char *dest, const char *src)
{
    char *origdest = dest;

    while (*dest)
    {
        dest++;
    }

    while (*src)
    {
        *dest++ = *src++;     }
    
    *dest = '\0';

    return origdest;
}
