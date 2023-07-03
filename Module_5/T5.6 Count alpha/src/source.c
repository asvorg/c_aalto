#include "source.h"
#include <string.h>


/**
 * \brief Counts alphabetical characters in a string
 *
 * \param str The string to be processed
 * \return The number of alphabetical characters
 */
int count_isalpha(const char *str)
{      
    int count = 0;
    int i;
    int len = strlen(str);
    char alphabet[62] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0132456789";
    for (i = 0; i < len; i++){
        if (str[i] == '0'){
            break;
        }
        if (i > len){
            break;
        }
        if (strchr(alphabet, str[i]) != NULL){
            count++;
        }
    }
       
        
    return count;    
    }
