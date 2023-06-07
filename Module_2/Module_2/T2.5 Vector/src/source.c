#include <math.h>
#include <stdio.h>
#include <math.h>

double vectorlength(double x, double y, double z)
{
    double res = sqrt(x * x + y * y + z * z);
    return res;
}