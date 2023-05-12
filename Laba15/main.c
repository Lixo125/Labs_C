#include <stdio.h>
#include <locale.h>

void print_digits(int n) {
    if (n < 10) {
        printf("%d ", n);
        return;
    }
    print_digits(n / 10);
    printf("%d ", n % 10);
}

void print_digits_reverse(int n) {
    if (n < 10) {
        printf("%d", n);
        return;
    }
    printf("%d ", n % 10);
    print_digits_reverse(n / 10);
}

int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    printf("Введите натуральное число: ");
    scanf("%d", &n);
    printf("Цифры в прямом порядке: ");
    print_digits(n);
    printf("\nЦифры в обратном порядке: ");
    print_digits_reverse(n);
    return 0;
}
