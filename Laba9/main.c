#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RUS");
    char str[1000];
    char sep[10] = "+";
    char *tokens[1000];
    int i = 0;
    printf("Введите математическое выражение: ");
    fgets(str, sizeof(str), stdin);
    char *ptr = str;
    while (*ptr) {
        if (*ptr == ' ') {
            memmove(ptr, ptr + 1, strlen(ptr + 1) + 1);
        } else {
            ptr++;
        }
    }
    char *token = strtok(str, sep);
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, sep);
    }

    int num_tokens = i;
    double sum = atof(tokens[0]);

    for (i = 1; i < num_tokens; i++) {
        char *ptr = tokens[i];
        double val = 0.0;
        if (strchr(ptr, '-') != NULL) {
            char *part1 = strtok(ptr, "-");
            char *part2 = strtok(NULL, "-");
            val = atof(part1) - atof(part2);
        } else {
            val = atof(ptr);
        }
        sum += val;
    }

    printf("Сумма: %.2f\n", sum);

    return 0;
}
