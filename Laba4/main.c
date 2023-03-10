#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "func.h"


int main()
{
    float a, b, c;
    printf("Vvedite storoni treugolnika:\n");
    scanf("%f %f %f", &a, &b, &c);

    if (a + b > c && a + c > b && b + c > a)
    {
        printf("Treugolnik (%g, %g, %g) sushestvuet!\n", a, b, c);
        printf("P = %g\n", perimetr(a, b, c));
        printf("S = %g", square(a, b, c));
    }
    else
        printf("Treugolnika (%g, %g, %g) ne sushestvuet!\n", a, b, c);
}
