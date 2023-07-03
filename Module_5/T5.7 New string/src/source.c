#include "source.h"
#include <string.h>
#include <stdio.h>


/* Print string */
/* Parameters:
 * s: string to be printed */

/**
 * \brief Prints ? terminated string
 *
 * \param s A ? terminated string
 */
void qstr_print(const char *s)
{
    int length = strlen(s);
 for (int i = 0; i < length; i++){
     if (s[i] == '?'){
         break;
     }
  printf("%c", s[i]); 
    }
}
/**
 * \brief Returns the length of a ? terminated string
 *
 * \param s A ? terminated string
 * \return The number of characters before first occurrence of ?
 */
unsigned int qstr_length(const char *s)
{
    int length = strlen(s);
    int count = 0;
     for (int i = 0; i < length; i++){
     if (s[i] == '?'){
         break;
     }
        count = count + 1; 
    }
    return count;
}


/**
 * \brief Concatenates two ? terminated strings
 *
 * \param dst The ? terminated string that will contain the concatenated ? terminated string
 * \param src A ? terminated string that will be appended to dst.
 * \return The length of the dst after concatenation
 */
int qstr_cat(char *dst, const char *src)
{
    int length = qstr_length(dst);
    int i = 0;
    while (src[i] != '?'){
        dst[length] = src[i];
        length++;
        i++;
    }
    dst[length] = '\0';
    return length;
}
