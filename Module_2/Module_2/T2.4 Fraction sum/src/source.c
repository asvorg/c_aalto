# include <stdio.h>
# include "source.h"

double fracsum(int x, int y, int a, int b)
{
    float xy = (float)x / (float)y;
    float ab = (float)a / (float)b;
    double res = xy + ab;
    return res;
}