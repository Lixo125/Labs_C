#include <stdio.h>
#include <stdlib.h>

void read_arr(double *arr, int n)
{
    for (int i = 0; i < n * n; i++)
        scanf("%lf", &arr[i]);
}

void print_arr(double *arr, int n)
{
    for (int i = 0; i < n * n; i++)
    {
        printf("%3g\t ", arr[i]);
        if ((i + 1) % n == 0)
            printf("\n");
    }
}

double* plus_arr(double *arr1, double *arr2, int n)
{
    double *result = (double*) malloc(n * n * sizeof(double));
    for (int i = 0; i < n * n; i++)
        result[i] = arr1[i] + arr2[i];

    return result;
}

double* minus_arr(double *arr1, double *arr2, int n)
{
    double *result = (double*) malloc(n * n * sizeof(double));
    for (int i = 0; i < n * n; i++)
        result[i] = arr1[i] - arr2[i];

    return result;
}

double* multiply_arr(double *arr1, double *arr2, int n)
{
    double *result = (double*) malloc(n * n * sizeof(double));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            double sum = 0.0;
            for (int k = 0; k < n; k++)
                sum += arr1[i*n + k] * arr2[k*n + j];
            result[i*n + j] = sum;
        }
    return result;
}

int main() {
    int n;
    double *arr1, *arr2, *result;
    char operation;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    arr1 = (double*) malloc(n * n * sizeof(double));
    arr2 = (double*) malloc(n * n * sizeof(double));

    printf("Enter values for matrix1:\n");
    read_arr(arr1, n);
    printf("Enter values for matrix2:\n");
    read_arr(arr2, n);

    printf("Enter the operation (+, - or *): ");
    scanf(" %c", &operation);

    switch (operation) {
        case '+':
            result = plus_arr(arr1, arr2, n);
            break;
        case '-':
            result = minus_arr(arr1, arr2, n);
            break;
        case '*':
            result = multiply_arr(arr1, arr2, n);
            break;
        default:
            printf("Invalid operation.\n");
            return 1;
    }
    printf("Result:\n");
    print_arr(result, n);

    free(arr1);
    free(arr2);
    free(result);
    return 0;

}
