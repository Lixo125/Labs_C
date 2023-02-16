#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    double glavD, pobD;
    double arr[3][3];
    printf("Zadayte elementi massiva(double) 3x3:\n");
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            scanf("%lf", &arr[i][j]);

    printf("\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%2g\t\t", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    glavD = arr[0][0] + arr[1][1] + arr[2][2];
    pobD = arr[0][2] + arr[1][1] + arr[2][0];

    printf("Sum - Main dig: %g\nSum - Poboch dig: %g\n", glavD, pobD);

    int arr1[2][2];

    printf("\nZadayte elementi massiva(int) 2x2:\n");

    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            scanf("%d", &arr1[i][j]);

    printf("\n");

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d\t", arr1[i][j]);
        }
        printf("\n");
    }

    printf("\nKvadrat matrici:\n");

    int arr2[2][2];
    arr2[0][0] = arr1[0][0]*arr1[0][0] + arr1[0][1]*arr1[1][0];
    arr2[0][1] = arr1[0][0]*arr1[0][1] + arr1[0][1]*arr1[1][1];
    arr2[1][0] = arr1[1][0]*arr1[0][0] + arr1[1][1]*arr1[1][0];
    arr2[1][1] = arr1[1][0]*arr1[0][1] + arr1[1][1]*arr1[1][1];

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d\t", arr2[i][j]);
        }
        printf("\n");
    }

    return 0;
}
