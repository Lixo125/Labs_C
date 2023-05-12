#include <stdio.h>
#include "func.h"

int main() {
    double s = sum(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    double m = max(3, 1.2, 2.3, 3.4);
    double n = min(4, 4.5, 2.3, 3.4, 1.2);
    double a = average(6, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7);

    printf("Sum = %g\n", s);
    printf("Max = %g\n", m);
    printf("Min = %g\n", n);
    printf("Average = %g\n", a);

    return 0;
}
