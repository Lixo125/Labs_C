#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b, c, D;
    double x1 ,x2;

    printf("Zadayte parametri function (a*x^2+b*x+c):\na = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    printf("c = ");
    scanf("%d", &c);

    D = pow(b, 2) - 4 * a * c;

    if (D > 0)
    {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        printf("Korni:\nx1 = %g, x2 = %g\n", x1, x2);
    }
    else if (D == 0)
    {
        x1 = (-b + sqrt(D)) / (2 * a);
        printf("Koren:\nx1 = %g\n", x1);
    }
    else
    {
        printf("Net kornei, t.k. D otricatelniy!\n");
    }

    return 0;
}
