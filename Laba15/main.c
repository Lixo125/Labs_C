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
    printf("������� ����������� �����: ");
    scanf("%d", &n);
    printf("����� � ������ �������: ");
    print_digits(n);
    printf("\n����� � �������� �������: ");
    print_digits_reverse(n);
    return 0;
}
