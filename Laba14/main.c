#include <stdio.h>
#include <setjmp.h>

jmp_buf env;

int fibonacci(int n, int x, int sum) {
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 1;
    } else {
        int fib = fibonacci(n-1, x, sum) + fibonacci(n-2, x, sum);
        if (n > x) {
            longjmp(env, 1);
        }
        return sum + fib;
    }
}

int main() {
    int n = 1, x, sum = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &x);
    if (setjmp(env) == 0) {
        while (1) {
            int fib = fibonacci(n, x, 0);
            sum += fib;
            printf("Fibonacci(%d) = %d, sum = %d\n", n, fib, sum);
            n++;
        }
    } else {
        printf("Sum of Fibonacci numbers F(%d): %d\n", x, sum);
    }
    return 0;
}
