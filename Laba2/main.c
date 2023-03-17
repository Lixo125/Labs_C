#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, r, n;
    double glavD=0, pobD=0;
    printf("Zadayte razmer massiva:\n");
    scanf("%d", &n);
    double arr[n][n];
    double res[n][n];
    printf("Zadayte elementi massiva(double):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%lf", &arr[i][j]);

    printf("\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%2g\t\t", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (i = 0; i < n; i++)
    {
            glavD += arr[i][i];
            pobD += arr[n-1-i][i];
    }


    printf("Sum - Main dig: %g\nSum - Poboch dig: %g\n", glavD, pobD);

    printf("\nKvadrat matrici:\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (r = 0; r < n; r++)
                res[i][j] += arr[i][r] * arr[r][j];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%lf\t", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}
