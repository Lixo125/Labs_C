#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char first_name[50];
    char last_name[50];
    int birth_year;
} humen;

int main() {

    humen people1[4];
    humen people2[4];

    for (int i = 0; i < 4; i++) {
        printf("Zadayte znachenie elementa - %d: ", i+1);
        scanf("%s %s %d", people1[i].first_name, people1[i].last_name, &people1[i].birth_year);
    }

    memcpy(people2, people1, sizeof(people1)); //Копируем

    for (int i = 0; i < 3; i++) {
        for (int j = i+1; j < 4; j++) {
            if (people2[i].birth_year > people2[j].birth_year) {
                humen temp = people2[i];
                people2[i] = people2[j];
                people2[j] = temp;
            }
        }
    }

    printf("\nIshodniy massiv:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s %s %d\n", people1[i].first_name, people1[i].last_name, people1[i].birth_year);
    }

    printf("\nOtsortirovanniy massiv:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s %s %d\n", people2[i].first_name, people2[i].last_name, people2[i].birth_year);
    }

    return 0;
}
