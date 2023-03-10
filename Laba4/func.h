
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float perimetr(float a, float b, float c)
{
    return a + b + c;
}

float square(float a, float b, float c)
{
    float p = (a + b + c) / 2;
    return (sqrt(p*(p - a)*(p - b)*(p - c)));
}
