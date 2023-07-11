#include "source.h"
#include <stdlib.h>
#include <string.h>
/**
 * \brief Removes the C comments from the input C code.
 *
 * \details The function polishes the code by */
//          - removing the block comments delimited by /* and */.
/*            These comments may span multiple lines.You should remove only */
//            characters starting with /* and ending with */. The characters,
/*            including white space characters (' ', \n, \r, \t), */
//            after */ should not be removed.
/*
 *          - remove the line comments starting with // until and including the
 *            newline character \n.
 *
 * \param input A code segment that contains some comments.It is a dynamically
 *              allocated string(array of characters).
 * \return A pointer to the polished code
 */

char *delete_comments(char *input)
{

    char *output = (char*)malloc(sizeof(char));
    char *output_start = output; 

    long unsigned int i = 0;
    for (i = 0; i < strlen(input); i++)
    {
        if (input[i] == '/' && input[i + 1] == '*') 
        {
            while (1){
                if (input[i] != '\n' || input[i] != '\r' || input[i] != '\t' || input[i] != ' ')
                {
                    i++;
                }
                if (input[i] == '*' && input[i + 1] == '/')
                {
                    i += 2;
                    break;
                }
            }
            i++;
        }
        else if (input[i] == '/' && input[i + 1] == '/') 
        {
            while (input[i] != '\n')
            {
                i++;
            }
        }
        else
        {
            *output = input[i];
            output++;
        }
        
    }
    /*
    while (*(output - 1) == ' ')
    {
        output--;
    }
    */
    //remove junk
    *output = '\0';
    return output_start;
}
