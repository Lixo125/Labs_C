#include <stdio.h>

#define LONG_SIZE (sizeof(long) * 8)
#define DOUBLE_SIZE (sizeof(double) * 8)

void print_bits_long(long num) {
    char bits[LONG_SIZE + 1];
    bits[LONG_SIZE] = '\0';

    for (int i = LONG_SIZE - 1; i >= 0; i--) {
        bits[i] = (num & 1) ? '1' : '0';
        num >>= 1;
    }

    printf("Bits: %s\n", bits);
}

void print_bits_double(double num) {
    char bits[DOUBLE_SIZE + 1];
    bits[DOUBLE_SIZE] = '\0';

    unsigned long long int_bits = *(unsigned long long*)&num;

    for (int i = DOUBLE_SIZE - 1; i >= 0; i--) {
        bits[i] = (int_bits & 1) ? '1' : '0';
        int_bits >>= 1;
    }

    printf("Bits: %s\n", bits);
}

int count_bits_long(long num) {
    int count = 0;
    while (num != 0) {
        if (num & 1) {
            count++;
        }
        num >>= 1;
    }
    return count;
}

int count_bits_double(double num) {
    int count = 0;
    unsigned long long bits = *(unsigned long long*)&num;
    while (bits != 0) {
        if (bits & 1) {
            count++;
        }
        bits >>= 1;
    }
    return count;
}

int main() {
    long lnum;
    double dnum;

    printf("Enter a long integer: ");
    scanf("%ld", &lnum);
    printf("Number of bits set to 1 in %ld: %d\n", lnum, count_bits_long(lnum));
    print_bits_long(lnum);

    printf("Enter a double: ");
    scanf("%lf", &dnum);
    printf("Number of bits set to 1 in %lf: %d\n", dnum, count_bits_double(dnum));
    print_bits_double(dnum);

    return 0;
}
