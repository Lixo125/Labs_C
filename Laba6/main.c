#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RUS");

    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");
    char last_name[50], first_name[50], middle_name[50];
    int year;

    if (input_file == NULL) {
        printf("Ошибка при открытии входного файла.\n");
        return 1;
    }

    while (fscanf(input_file, "%s %s %s %d", last_name, first_name, middle_name, &year) == 4) {
        if (year > 1980 && last_name[0] == 'С') {
            printf("%s %s %s %d\n", last_name, first_name, middle_name, year);
            fprintf(output_file, "%s %s %s %d\n", last_name, first_name, middle_name, year);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
