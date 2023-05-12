#include <stdio.h>
#include <time.h>
#include <string.h>
#include <locale.h>


void print_weekday(int year, int month, int day)
{
    struct tm time = {0, 0, 0, day, month - 1, year - 1900};
    time_t t = mktime(&time);
    char* weekdays[] = {"Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота"};
    printf("%s\n", weekdays[localtime(&t)->tm_wday]);
}
void print_calendar(int year, int month);

void print_year_calendar(int year) {
    for (int month = 1; month <= 12; month++) {
        print_calendar(year, month);
    }
}

void print_calendar(int year, int month) {
    char* months[12] = {"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
    printf("   <===%s===>\n", months[month-1]);
    printf("Пн Вт Ср Чт Пт Сб Вс\n");

    struct tm first_day = {0, 0, 0, 0, month - 1, year - 1900};
    time_t first_day_time = mktime(&first_day);
    int first_day_weekday = localtime(&first_day_time)->tm_wday;

    for (int i = 0; i < first_day_weekday; i++) {
        printf("   ");
    }

    int days_in_month;
    if (month == 2) {
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
            days_in_month = 29;
        } else {
            days_in_month = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days_in_month = 30;
    } else {
        days_in_month = 31;
    }

    for (int day = 1; day <= days_in_month; day++) {
        printf("%2d ", day);
        struct tm current_day = {0, 0, 0, day, month - 1, year - 1900};
        time_t current_day_time = mktime(&current_day);
        if (localtime(&current_day_time)->tm_wday == 0) {
            printf("\n");
        }
    }

    printf("\n\n");
}

int main()
{
    setlocale(LC_ALL, "RUS");
    char date[10];
    int year, month, day;

    printf("Введите дату в формате гггг.мм.дд, гггг.мм, гггг или now: ");
    scanf("%s", date);

    if (strcmp(date, "now") == 0)
    {
        time_t now = time(NULL);
        struct tm *local_time = localtime(&now);
        printf("\nТекущая дата: %02d.%02d.%04d\n", local_time->tm_mday, local_time->tm_mon + 1, local_time->tm_year + 1900);
    }
    else if (sscanf(date, "%d.%d.%d", &year, &month, &day) == 3)
    {
        printf("\n\nДень недели на %02d.%02d.%04d:\n", day, month, year);
        print_weekday(year, month, day);
    }
    else if (sscanf(date, "%d.%d", &year, &month) == 2)
    {
        printf("\n\nКалендарь за %d год:\n\n", year);
        print_calendar(year, month);
    }
    else if (sscanf(date, "%d", &year) == 1)
    {
        printf("\n\nКалендарь за %d год:\n\n", year);
        print_year_calendar(year);
    }
    else
    {
        printf("Некорректный ввод.\n");
    }
    return 0;
}

