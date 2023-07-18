#include <stdio.h>
#include <stdarg.h>

int myprint(const char *str, ...){
    va_list args;
    va_start(args, str);
    int i = 0;
    int res = 0;
    while(str[i] != '\0'){
        int num;
        if(str[i] == '&'){
            num = va_arg(args, int);
            printf("%d", num);
            res++;
        }else{
            printf("%c", str[i]);
        }
        i++;
    }
    va_end(args);
    return res;
}