#include <stdio.h>
#include <locale.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MAXIMUM_SIZE 100

int main() {
    setlocale(LC_ALL, "RUS");
    int nums[MAXIMUM_SIZE];
    int count, i;
    int max = -1;

    printf("Введите количество чисел (не более %d): ", MAXIMUM_SIZE);
    scanf("%d", &count);

    printf("Введите числа через пробел: ");
    for (i = 0; i < count; i++) {
        scanf("%d", &nums[i]);
        max = MAX(max, nums[i]);
    }

    printf("Максимальное число: %d\n", max);

    return 0;
}
