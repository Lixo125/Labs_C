#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main() {
    int n, i;
    char operation;
    double **arr1, **arr2, **result;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    arr1= (double**) malloc (sizeof (double*) * n);
    for (int i = 0; i < n; i++)
        arr1[i] = (double*) malloc (sizeof (double)*n);

    arr2= (double**) malloc (sizeof (double*) * n);
    for (int i = 0; i < n; i++)
        arr2[i] = (double*) malloc (sizeof (double)*n);

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

    for(i = 0; i < n; i++)
        free(arr1[i]);
    free(arr1);
    for(i = 0; i < n; i++)
        free(arr2[i]);
    free(arr2);
    for(i = 0; i < n; i++)
        free(result[i]);
    free(result);

    return 0;

}
