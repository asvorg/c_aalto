#include <stdlib.h>
#include <string.h>

char *my_strcat(char *dest, const char *src)
{   
    
    int dest_len = strlen(dest);
    int src_len = strlen(src);
    int y = 0;
    char *res;

    if (dest_len == 0)
    {
        res = malloc(src_len);
    }

    if (src_len == 0)
    {
        res = malloc(dest_len);
    }

    if (dest_len != 0 && src_len != 0)
    {   
        res = malloc(dest_len + src_len);
    }

    for (int i = 0; i < dest_len; i++)
    {
        res[i] = dest[i];
        y++;
    }

    for (int i = 0; i < src_len; i++)
    {   
        res[dest_len + i] = src[i];
        y++;
    }
    res[dest_len + y] = '\0';
    return res;
    
}
