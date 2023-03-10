#include <stdio.h>
#include <stdlib.h>

int i, j, k;

void read_arr(double **arr, int n)
{
    for (i = 0; i < n ; i++)
        for (j = 0; j < n; j++)
            scanf("%lf", &arr[i][j]);
}

void print_arr(double **arr, int n)
{
    for (i = 0; i < n * n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%3g\t ", arr[i][j]);
        }
        printf("\n");
    }
}

double** plus_arr(double **arr1, double **arr2, int n)
{
    double **result = (double**) malloc(n * sizeof(double*));
    for(i = 0; i < n; i++)
        result[i] = (double*)malloc(n * sizeof(double*));

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            result[i][j] = arr1[i][j] + arr2[i][j];

    return result;
}

double** minus_arr(double **arr1, double **arr2, int n)
{
    double **result = (double**) malloc(n * sizeof(double*));
    for(i = 0; i < n; i++)
        result[i] = (double*)malloc(n * sizeof(double*));

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            result[i][j] = arr1[i][j] - arr2[i][j];

    return result;
}

double** multiply_arr(double **arr1, double **arr2, int n)
{
    double **result = (double**) malloc(n * sizeof(double*));
    for(i = 0; i < n; i++)
        result[i] = (double*)malloc(n * sizeof(double*));

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
                result[i][j] += arr1[i][k] * arr2[k][j];

    return result;
}
